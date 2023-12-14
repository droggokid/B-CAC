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
uint32 counter = 0;

const uint32 tickPeriodMs = 10;
uint32 startCounter = 0;
uint32 stopCounter = 0;
uint32 timeIntervalTicks = 0;
uint32 timeIntervalMs = 0;


void startTimer()
{
    
    Timer_1_Start();
    startCounter = Timer_1_ReadCounter();
}
uint32 stopTimer()
{
    
    stopCounter = Timer_1_ReadCounter();

    // Beregn tidsintervallet i ticks
    timeIntervalTicks = startCounter - stopCounter;

    // Konverter tidsintervallet til tid i millisekunder
    timeIntervalMs = timeIntervalTicks/100;

    Timer_1_Stop();
    
    Timer_1_WriteCounter(0);
    
    return timeIntervalMs;
}

uint8_t convertMinutes(uint32_t time_1)
{
    // Assuming time is a 32-bit integer
    uint8_t minutter = 0;
    minutter = (time_1 / (1000 * 60)) & 0xFF;   // Minutter
    return minutter;
}

uint8_t convertSeconds(uint32_t time_2)
{
    // Assuming time is a 32-bit integer
    uint8_t sekunder = 0;
    sekunder = ((time_2 / 1000) % 60) & 0xFF;   // Sekunder
    return sekunder;
}

uint8_t convertMilliseconds(uint32_t time_3)
{
    uint16_t temp = 0;
    // Assuming time is a 32-bit integer
    uint8_t milliSekunder = 0;
    milliSekunder = ((time_3 % 1000)/100) & 0xFF; // Millisekunder
    return milliSekunder;
}