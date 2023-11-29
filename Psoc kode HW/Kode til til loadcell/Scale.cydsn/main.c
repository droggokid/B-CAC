/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "Loadcell.h"
#include "Timer.h"
#include "FlagMotor.h"
#include "led.h"
#include <stdio.h>

CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);
char uartBuffer[256];
int UCstate=0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
    initLoadcell();
    UART_1_PutString("Scale application started\r\n");
    
    int repeats = 50;
    float startoffset = 164.5;
    float factor = 4.672;
    int preload=0;
    uint16_t Result_gram;
    uint8_t gameReady=0;
    uint8_t timestop=0;
    uint8_t dnf=0;
    char mode='h';
    uint32_t tid=0;
    
    homeStepper(mode);
    stopFlagMotor();
    
    

    //float zerodriftOffset = readWeight( repeats,startoffset,  factor, preload);
    //snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %f\r\n ", zerodriftOffset);
    //UART_1_PutString(uartBuffer);
    
    
    //offset_Zerodrift_calibrate( repeats,  startoffset,  factor, preload);
    
    
    //zerodriftOffset = readWeight( repeats,startoffset,  factor, preload);
    //snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %f\r\n", zerodriftOffset);
    
    //UART_1_PutString(uartBuffer);
    
    
    //wait_for_weight( startoffset,  factor, preload);
    
    //CyDelay(500);
    //zerodriftOffset = readWeight( repeats,startoffset,  factor, preload);
    //snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %f\r\n", zerodriftOffset);
    
    //UART_1_PutString(uartBuffer);
    
    
    for(;;)
    {
           //UC1 Game preperation
    //Øl fjernet
    if(UCstate==1)
    {
    offset_Zerodrift_calibrate( repeats,  startoffset,  factor, preload);
    {
    float zerodriftOffset = readWeight( repeats,startoffset,  factor, preload);
    snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %f\r\n ", zerodriftOffset);
    UART_1_PutString(uartBuffer);
    }
    homeStepper(mode);
    stopFlagMotor();
    UCstate=0;
    }
    
    
    
    //der er sat en genstand på platform
    if(UCstate==2)
    {
    wait_for_weight(startoffset, factor,preload);//venter på der bliver plasseret en øl
    CyDelay(3000); //delay så flasken flader til ro
    Result_gram = readWeight( repeats,startoffset, factor, preload);
    {
    
    snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %d\r\n ", Result_gram);
    UART_1_PutString(uartBuffer);
    
    }
    if(Result_gram>650)
    gameReady=1;
    else
    gameReady=0;
    
    {
    snprintf(uartBuffer,sizeof(uartBuffer),"gameReady (g) %d\r\n ", gameReady);
    UART_1_PutString(uartBuffer);
    }
    UCstate=0;
    }
     
    //send signal til RPI, Hvis GameReady er 1 så er øllen godkendt
    
    
    
    //UC2 play game
    
    //Dermodtages GO signal
    
    if(UCstate==3)
    {
    Result_gram = readWeight(repeats,startoffset, factor, preload);
        {//print
        snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %d\r\n ", Result_gram);
        UART_1_PutString(uartBuffer);
        }
    if(Result_gram<10)
        dnf=1;
    else
        dnf=0;
        {//print
        snprintf(uartBuffer,sizeof(uartBuffer),"Dnf (g) %d\r\n ", dnf);
        UART_1_PutString(uartBuffer);
        }
    startTidsTagning();//timer startes
    
    while(Result_gram>10)
    Result_gram = readWeight(repeats,startoffset, factor, preload);
    
    
    wait_for_weight(startoffset, factor,preload);//venter på der bliver plasseret en øl
    timestop=1;
    tid = stopTidsTagning(); //tid stoppes
    int roundedNum = (tid + 50) / 100 * 100;//rundes af til nærmeste 100 ms
        {//print
        snprintf(uartBuffer,sizeof(uartBuffer),"tid (g) %d\r\n ", tid);
        UART_1_PutString(uartBuffer);
        snprintf(uartBuffer,sizeof(uartBuffer),"tid (g) %d\r\n ", roundedNum);
        UART_1_PutString(uartBuffer);
        }
    //tid sendes
    CyDelay(5000);
    Result_gram = readWeight(repeats,startoffset, factor, preload);
        {//print
        snprintf(uartBuffer,sizeof(uartBuffer),"Read value (g) %d\r\n ", Result_gram);
        UART_1_PutString(uartBuffer);
        }
    if(Result_gram>310)
        dnf=1;
    //dnf value sendes
    
        {//print
        snprintf(uartBuffer,sizeof(uartBuffer),"Dnf (g) %d\r\n ", dnf);
        UART_1_PutString(uartBuffer);
        }
    UCstate=0;
    }
    
    //modtager win signal fra RPI
    if(UCstate==4)
    {
    
    stepperdriver_rotateTo(90, mode);
    stopFlagMotor();
    UCstate=0;
    }
    }
    
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case '1' :
        {
            UCstate=1;
        }
        break;
        case '2' :
        {
            UCstate=2;
        }
        break;
        case '3' :
        {
            UCstate=3;
        }
        break;
        case '4' :
        {
            UCstate=4;
        }
        break;
        default :
        {
            // nothing
        }
        break;
    }
}

CY_ISR(ISR_UART_rx_handler)
{
    
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

/* [] END OF FILE */
