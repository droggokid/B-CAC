#include "project.h"
#include <stdio.h>
#include "Loadcell.h"
#include "Timer.h"
#include "FlagMotor.h"
#include "led.h"
#include "spi_Slave.h"


CY_ISR_PROTO(ISR_SPI_rx_handler);
void handleByteReceived(uint8_t byteReceived);
static int UCstate = 0;
uint32 tid = 0;
uint32 roundedNum = 0;

uint8_t gameReady = 0;     //spi_drv1
uint8_t minutes = 0;       //spi_drv2
uint8_t seconds = 0;       //spi_drv3
uint8_t milliSeconds = 0;  //spi_drv4
uint8_t dnf = 0;           //spi_drv5
uint8_t receivedData = 0;
uint8_t gameDone  = 0;


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
    float startoffset = 178.74; // vægt 63
    //float startoffset = 126.07; //vægt 101
    float factor = 3.98;//vægt 63
    //float factor = 4.24; //vægt 101
    
    int preload = 0;
    uint16_t Result_gram;
    //uint8_t timestop=0;
    char mode = 'h';
     
    homeStepper(mode);
    stopFlagMotor();
   
    for(;;)
    {
        // UC1 Game preparation
        // Øl fjernet
        if(UCstate == 1)
        {
            offsetZerodriftCalibrate(repeats, startoffset, factor, preload);
    
            homeStepper(mode);
            stopFlagMotor();
            initLed();
            UCstate = 0;
            gameDone = 0xA;
        }
    
        // der er sat en genstand på platform
        if(UCstate == 2)
        {
            gameReady = 0; 
            waitForWeight(startoffset, factor, preload); // venter på der bliver placeret en øl
            CyDelay(3000); // delay så flasken falder til ro
            Result_gram = readWeight(repeats, startoffset, factor, preload);
    
            if(Result_gram >= 620) { //husk at ændre til 650!!!
                gameReady = 9;
            }

            UCstate=0;
            gameDone = 0xB;
        }
     
        // send signal til RPI, Hvis GameReady er 1 så er øllen godkendt
        // UC2 play game
        // Der modtages GO signal
        if(UCstate == 3)
        {
            dnf = 0;
            startTimer();  // timer startes
            Result_gram = readWeight(repeats, startoffset, factor, preload);
    
            if(Result_gram <= 10){
                dnf = 1;
            }
    
            while(Result_gram > 10) {
                Result_gram = readWeight(repeats, startoffset, factor, preload);
            }
    
            waitForWeight(startoffset, factor, preload); // venter på der bliver placeret en øl
    
            tid = stopTimer(); // tid stoppes 
    
            roundedNum = (tid + 50) / 100 * 100; // rundes af til nærmeste 100 ms
            tid = roundedNum;
            gameDone = 0xC;
    
            // tid sendes
            CyDelay(5000);
            Result_gram = readWeight(repeats, startoffset, factor, preload);
    
            if(Result_gram > 320){
                dnf = 1;
            }
            
    
            // dnf value 
            UCstate = 0;
            gameDone = 0xD;
        }
    
        // modtager win signal fra RPI
        if(UCstate == 4)
        {
    
            flagMotorRotateTo(90, mode);
            // stopFlagMotor();
            if (dnf == 0)
            {
                startLedGreen(80);
            }
            else  { 
                startLedRed(100);
            }
    
            UCstate = 0;
            gameDone = 0xE;
        }
         // modtager win signal fra RPI
        if(UCstate == 5)
        {
    
           
            if (dnf == 0)
            {
                startLedGreen(80);
            }
            else  { 
                startLedRed(100);
            }
    
            UCstate = 0;
            gameDone = 0xF;
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
            UCstate = 4; //win
            
        }
        break;
        case 0xEE : 
        {
            UCstate = 5; //lose
        }
        break;
        case 0x2 :
        {
            sendSPi(gameReady);
        }
        break;
        case 0x3 :
        {
            minutes = convertMinutes(tid);
            sendSPi(minutes); 
        }
        break;
        case 0x4 :
        {
            seconds = convertSeconds(tid);
            sendSPi(seconds);
        }
        break;
        case 0x5 :
        {
            milliSeconds = convertMilliseconds(tid);
            sendSPi(milliSeconds);
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
    uint8_t receivedData = receivedSPi();
    
    if(receivedData == 0x1)
    {            
          sendSPi(gameDone); 
    }
    
    // Handling of received SPI data
    handleByteReceived(receivedData);
}