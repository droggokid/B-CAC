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
    
    Timer_1_WriteCounter(0);
    
    return time_interval_ms;
}

uint8_t convertMinutter(uint32_t time_1)
{
    // Assuming time is a 32-bit integer
    uint8_t minutter = 0;
    minutter = (time_1 / (1000 * 60)) & 0xFF;   // Minutter
    return minutter;
}

uint8_t convertSekunder(uint32_t time_2)
{
    // Assuming time is a 32-bit integer
    uint8_t sekunder = 0;
    sekunder = ((time_2 / 1000) % 60) & 0xFF;   // Sekunder
    return sekunder;
}

uint8_t convertMillisekunder(uint32_t time_3)
{
    uint16_t temp = 0;
    // Assuming time is a 32-bit integer
    uint8_t milliSekunder = 0;
    milliSekunder = ((time_3 % 1000)/100) & 0xFF; // Millisekunder
    return milliSekunder;
}