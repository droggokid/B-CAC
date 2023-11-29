#include "project.h"
#include <stdio.h>
#include <inttypes.h>

volatile uint16 startCount = 0;
volatile uint16 stopCount = 0;
static char outputBuffer[256];
uint32 InterruptCnt;
uint32 counter=0;

const uint32 tick_period_ms = 10;
uint32 start_counter = 0;
 uint32 stop_counter=0;
 uint32 time_interval_ticks = 0;
uint32 time_interval_ms=0;

CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);
void stopTidsTagning();
void startTidsTagning();



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    UART_1_Start();
    

    /* Start the components */
    Timer_1_Start();

    UART_1_PutString("Stop Watch started\r\n");
    UART_1_PutString("a: Start TidsTagning\r\n");
    UART_1_PutString("s: Stop TidsTagning\r\n");

    for(;;)
    {
        
        //startTidsTagning();
        start_counter = Timer_1_ReadCounter();
        
        CyDelay(2000);
        
        stop_counter = Timer_1_ReadCounter();

        // Beregn tidsintervallet i ticks
        time_interval_ticks = start_counter - stop_counter;

        // Konverter tidsintervallet til tid i millisekunder
        time_interval_ms = time_interval_ticks/1000;
        
        sprintf(outputBuffer, "Counter: %lu\r\n",time_interval_ms);
        
        UART_1_PutString(outputBuffer);

        //stopTidsTagning();
        
        //startTidsTagning();
        start_counter = Timer_1_ReadCounter();
        CyDelay(4000);


        // Slut tidspunkt
        stop_counter = Timer_1_ReadCounter();

        // Beregn tidsintervallet i ticks
        time_interval_ticks = start_counter - stop_counter;

        // Konverter tidsintervallet til tid i millisekunder
        time_interval_ms = time_interval_ticks/1000;
        
        sprintf(outputBuffer, "Counter: %lu\r\n",time_interval_ms);
        
        UART_1_PutString(outputBuffer);
        //stopTidsTagning();
        
        //startTidsTagning();
        
        start_counter = Timer_1_ReadCounter();
        CyDelay(60002);

        // Slut tidspunkt
        //stop_counter = Timer_1_ReadCounter();

         // Slut tidspunkt
        stop_counter = Timer_1_ReadCounter();

        // Beregn tidsintervallet i ticks
        time_interval_ticks = start_counter - stop_counter;

        // Konverter tidsintervallet til tid i millisekunder
        time_interval_ms = time_interval_ticks/1000;
        
        sprintf(outputBuffer, "Counter: %lu\r\n",time_interval_ms);
        
        UART_1_PutString(outputBuffer);
        
        //stopTidsTagning();
        
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

void handleByteReceived(uint8_t byteReceived)
{
    switch (byteReceived)
    {
    case 'a':
    {
        startTidsTagning();
    }
    break;
    case 's':
    {
        stopTidsTagning();
    }
    break;
    default:
    {
        // nothing
    }
    break;
    }
}

void startTidsTagning()
{
    UART_1_PutString("Time started\r\n");
    Timer_1_Start();
    startCount = InterruptCnt;
}

void stopTidsTagning()
{
    Timer_1_Stop();
    stopCount = InterruptCnt;
    uint16 elapsed = (stopCount - startCount)*10;
    snprintf(outputBuffer, sizeof(outputBuffer), "Time passed: %u ms \r\n", elapsed);
    UART_1_PutString(outputBuffer);
}
