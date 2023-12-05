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
#include "Timer.h"
#include "spi_Slave.h"
#include <stdio.h>

volatile uint16 startCount = 0;
volatile uint16 stopCount = 0;
uint32 counter=0;

const uint32 tick_period_ms = 10;
uint32 start_counter = 0;
uint32 stop_counter=0;
uint32 time_interval_ticks = 0;
uint32 time_interval_ms=0;


void startTidsTagning()
{
    
    Timer_1_Start();
    start_counter = Timer_1_ReadCounter();
}
uint32 stopTidsTagning()
{
    
    stop_counter = Timer_1_ReadCounter();

    // Beregn tidsintervallet i ticks
    time_interval_ticks = start_counter - stop_counter;

    // Konverter tidsintervallet til tid i millisekunder
    time_interval_ms = time_interval_ticks/100;
        

    Timer_1_Stop();
    
    return time_interval_ms;
}

void sendTimeOverSPI(uint32_t time)
{
    // Assuming time is a 32-bit integer
    uint8_t tx_buf[3];
    tx_buf[0] = (time / (1000 * 60)) & 0xFF;         // Minutes
    tx_buf[1] = ((time / 1000) % 60) & 0xFF;         // Seconds
    tx_buf[2] = (time % 1000) & 0xFF;                // Milliseconds

    // Initialize SPI
    //InitializeSPI();

    // Send each byte over SPI
    for (int i = 0; i < 3; ++i)
    {
        sendSPi(tx_buf[i]);
    }
}