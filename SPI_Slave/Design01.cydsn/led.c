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
#include "led.h"
#include <stdio.h>

void initLed(void)
{
    PWM_1_Start();
    PWM_1_WriteCompare1(0);
    PWM_1_WriteCompare2(0);
}


void startLedGreen(int8_t dutyCycle)
{
 PWM_1_WriteCompare1(dutyCycle);
}
void stopLedGreen(void)
{
    PWM_1_WriteCompare1(0);
}
void startLedRed(int8_t dutyCycle)
{
    PWM_1_WriteCompare2(dutyCycle);
}
void stopLedRed(void )
{
    PWM_1_WriteCompare2(0);
}
/* [] END OF FILE */
