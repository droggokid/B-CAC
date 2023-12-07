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
uint8_t receivedData = 0;
uint32 roundedNum = 0;
uint32_t hardcode_tid = 6300;

uint32 tid=0;
uint8_t minutter = 0;
uint8_t sekunder = 0;
uint8_t milliSekunder = 0;
uint8_t spilleterslut = 0;

//uint8_t roundNum(uint8_t num) { 
//       int temp = 0;
//        
//        temp = num % 100;
//        
//        return num - temp;
//    }

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    SPI_RX_ISR_StartEx(ISR_SPI_rx_handler);

    // Initialize SPI
    InitializeSPI(); // Make sure this function is correctly configuring the SPI module
    
    
    //Initiering
    initLoadcell();
    
    //Variable definationer
    int repeats = 50;
    float startoffset = 164.5;
    float factor = 4.672;
    int preload=0;
    uint16_t Result_gram;
    uint8_t gameReady=0;
    uint8_t timestop=0;
    uint8_t dnf=0;
    char mode='h';
     
    homeStepper(mode);
    stopFlagMotor();
   
    for(;;)
    {
           //UC1 Game preperation
    //Øl fjernet
    if(UCstate==1)
    
    {
    offset_Zerodrift_calibrate( repeats,  startoffset,  factor, preload);
    {
    float zerodriftOffset = readWeight( repeats,startoffset,  factor, preload);
    //snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %f\r\n ", zerodriftOffset);
    //UART_1_PutString(uartBuffer);
    }
    
    homeStepper(mode);
    stopFlagMotor();
    UCstate=0;
    spilleterslut = 0;
    }
    
    //der er sat en genstand på platform
    if(UCstate==2)
    {
    wait_for_weight(startoffset, factor,preload);//venter på der bliver plasseret en øl
    CyDelay(3000); //delay så flasken flader til ro
    Result_gram = readWeight( repeats,startoffset, factor, preload);
    {
    
    //snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %d\r\n ", Result_gram);
    //UART_1_PutString(uartBuffer);
    
    }
    if(Result_gram>650)
    gameReady=1;
    else
    gameReady=0;
    
    {
    //snprintf(uartBuffer,sizeof(uartBuffer),"gameReady (g) %d\r\n ", gameReady);
    //UART_1_PutString(uartBuffer);
    }
    //sendSPi(receivedData);
    UCstate=0;
    }
     
    //send signal til RPI, Hvis GameReady er 1 så er øllen godkendt
    
    //UC2 play game
    
    //Dermodtages GO signal
    
    if(UCstate==3)
    {
    
    Result_gram = readWeight(repeats,startoffset, factor, preload);
        {//print
        //snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %d\r\n ", Result_gram);
        //UART_1_PutString(uartBuffer);
        }
    if(Result_gram<10)
        dnf=1;
    else
        dnf=0;
        {//print
        //snprintf(uartBuffer,sizeof(uartBuffer),"Dnf (g) %d\r\n ", dnf);
        //UART_1_PutString(uartBuffer);
        }
    //startTidsTagning();//timer startes
    
    while(Result_gram>10)
    Result_gram = readWeight(repeats,startoffset, factor, preload);
    //CyDelay(65250);
    
    tid = 65270;
    
    //wait_for_weight(startoffset, factor,preload);//venter på der bliver plasseret en øl
    
    
    //tid = stopTidsTagning(); //tid stoppes 
    spilleterslut = 0x4;
    
    
    roundedNum = (tid + 50) / 100 * 100;//rundes af til nærmeste 100 ms
    tid = roundedNum;
   
        {//print
        //snprintf(uartBuffer,sizeof(uartBuffer),"tid (g) %d\r\n ", tid);
        //UART_1_PutString(uartBuffer);
        //snprintf(uartBuffer,sizeof(uartBuffer),"tid (g) %d\r\n ", roundedNum);
        //UART_1_PutString(uartBuffer);
        }
    //tid sendes
    
    
    //CyDelay(5000);
    Result_gram = readWeight(repeats,startoffset, factor, preload);
        {//print
        //snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %d\r\n ", Result_gram);
        //UART_1_PutString(uartBuffer);
        }
    if(Result_gram>310)
        dnf=1;
    //dnf value sendes
    
        {//print
        //snprintf(uartBuffer,sizeof(uartBuffer),"Dnf (g) %d\r\n ", dnf);
        //UART_1_PutString(uartBuffer);
        }
    UCstate=0;
    }
    
    //modtager win signal fra RPI
    if(UCstate==4)
    {
    
    stepperdriver_rotateTo(90, mode);
    stopFlagMotor();
    sendSPi(receivedData);
    UCstate=0;
    }
    }
    
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case 0xAA :
        {
            //Kalibrering af vægten samt steppermotor
            UCstate=1;
            
        }
        break;
        case 0xBB :
        {
            //Gameready - venter, læser samt tjekker på vægten
            UCstate=2;
            
        }
        break;
        case 0xCC :
        {
            //Loop for aflæsning af vægt - Venter på, at der kommer vægt på vægten / tjekker for eventuel DNF
            UCstate=3;
            //sendTimeOverSPI();
        }
        break;
        case 0xDD :
        {
            //Flagmotor
            UCstate = 4;
            
        }
        
        break;
        case 0x2 :
        {
            minutter = convertMinutter(tid);
            sendSPi(minutter); 
        }
        
        break;
        case 0x3 :
        {
            sekunder = convertSekunder(tid);
            sendSPi(sekunder);
        }
        
        break;
        case 0x4 :
        {
            milliSekunder = convertMillisekunder(tid);
            milliSekunder = milliSekunder/100;
            sendSPi(milliSekunder);
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
        sendSPi(spilleterslut);
        
    }
    //Handling of recieved SPI data
    handleByteReceived(receivedData);
    
        
}