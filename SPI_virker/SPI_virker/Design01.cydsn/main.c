#include "project.h"

#include "Loadcell.h"
#include "Timer.h"
#include "FlagMotor.h"
#include "led.h"
#include "spi_Slave.h"


#include <stdio.h>


CY_ISR_PROTO(ISR_SPI_rx_handler);
void handleByteReceived(uint8_t byteReceived);
static int UCstate=0;
uint32 tid=0;
uint32 roundedNum = 0;

uint8_t gameReady = 0;//spi_drv1
uint8_t minutter = 0; //spi_drv2
uint8_t sekunder = 0; //spi_drv3
uint8_t milliSekunder = 0;//spi_drv4
uint8_t dnf=0;//spi_drv5
uint8_t receivedData = 0;
uint8_t spilleterslut = 0;


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    SPI_RX_ISR_StartEx(ISR_SPI_rx_handler);

    // Initialize SPI
    InitializeSPI(); // Make sure this function is correctly configuring the SPI module
    
    // Initialization
    initLoadcell();
    
    // Variable definitions
    int repeats = 50;
    float startoffset = 164.5;
    float factor = 4.672;
    int preload=0;
    uint16_t Result_gram;
    //uint8_t timestop=0;
    char mode='h';
     
    homeStepper(mode);
    stopFlagMotor();
   
    for(;;)
    {
        // UC1 Game preparation
        // Øl fjernet
        if(UCstate == 1)
        {
            offset_Zerodrift_calibrate(repeats, startoffset, factor, preload);
    
            homeStepper(mode);
            stopFlagMotor();
            initLed();
            UCstate = 0;
            spilleterslut = 0xA;
        }
    
        // der er sat en genstand på platform
        if(UCstate == 2)
        {
            gameReady = 0; 
            wait_for_weight(startoffset, factor, preload); // venter på der bliver placeret en øl
            CyDelay(3000); // delay så flasken falder til ro
            Result_gram = readWeight(repeats, startoffset, factor, preload);
    
            if(Result_gram >= 100) { //husk at ændre til 650!!!
                gameReady = 1;
            }

            UCstate=0;
            spilleterslut = 0xB;
        }
     
        // send signal til RPI, Hvis GameReady er 1 så er øllen godkendt
        // UC2 play game
        // Der modtages GO signal
        if(UCstate == 3)
        {
            dnf = 0;
            startTidsTagning();  // timer startes
            Result_gram = readWeight(repeats, startoffset, factor, preload);
    
            if(Result_gram <= 10){
                dnf = 1;
            }
    
            while(Result_gram > 10) {
                Result_gram = readWeight(repeats, startoffset, factor, preload);
            }
    
            wait_for_weight(startoffset, factor, preload); // venter på der bliver placeret en øl
    
            tid = stopTidsTagning(); // tid stoppes 
    
            roundedNum = (tid + 50) / 100 * 100; // rundes af til nærmeste 100 ms
            tid = roundedNum;
            spilleterslut = 0xC;
    
            // tid sendes
            CyDelay(5000);
            Result_gram = readWeight(repeats, startoffset, factor, preload);
    
            if(Result_gram > 310){
                dnf = 1;
            }
            
    
            // dnf value 
            UCstate = 0;
            spilleterslut = 0xD;
        }
    
        // modtager win signal fra RPI
        if(UCstate == 4)
        {
    
            stepperdriver_rotateTo(90, mode);
            // stopFlagMotor();
            if (dnf == 0)
            {
                startLedGreen(80);
            }
            else  { 
                startLedRed(100);
            }
    
            UCstate = 0;
            spilleterslut = 0xE;
        }
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case 0xAA :
        {
            // Kalibrering af vægten samt steppermotor
            UCstate=1;
        }
        break;
        case 0xBB :
        {
            // Gameready - venter, læser samt tjekker på vægten
            UCstate = 2;
            
        }
        break;
        case 0xCC :
        {
            // Loop for aflæsning af vægt - Venter på, at der kommer vægt på vægten / tjekker for eventuel DNF
            UCstate=3;
            // sendTimeOverSPI();
        }
        break;
        case 0xDD :
        {
            // Flagmotor
            UCstate = 4;
            
        }
        break;
        case 0x2 :
        {
            sendSPi(gameReady);
        }
        break;
        case 0x3 :
        {
            minutter = convertMinutter(tid);
            sendSPi(minutter); 
        }
        break;
        case 0x4 :
        {
            sekunder = convertSekunder(tid);
            sendSPi(sekunder);
        }
        break;
        case 0x5 :
        {
            milliSekunder = convertMillisekunder(tid);
            sendSPi(milliSekunder);
        }
        break;
        case 0x6 :
        {
           sendSPi(dnf);
        }
        break;
        default :
        {
            // nothing
        }
        break;

    }
}

CY_ISR(ISR_SPI_rx_handler)
{
    uint8_t receivedData = modtagetSPi();
    
    if(receivedData == 0x1)
    {            
        //for (uint8_t i = 0; i < 2; i++)
        //{
          sendSPi(spilleterslut); 
        //}
            
        //spilleterslut = 0;
    }
    
    // Handling of received SPI data
    handleByteReceived(receivedData);
}
