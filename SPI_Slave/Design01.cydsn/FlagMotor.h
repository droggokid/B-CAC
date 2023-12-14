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

/* 
* stepperdriver.h
*
* Created: 18-10-2023 16:13:18
* Author: jesper
*/

#include "project.h"



void coilA1(void);
void coilA2(void);
void coilB1(void);
void coilB2(void);
void coilA1A2(void);
void coilA2B1(void);
void coilB1B2(void);
void coilB2A1(void);
void stopFlagMotor(void);



//tager et step og kan bestemme modes wavedrive=w fullstep=f halfstep=h
//frem 1 er frem 0 er tilbage
void takestep(char step_mode, char frem);

// tager antal steps og stepper det antal 
//og vis man tage - step rotere den baglæns
void numberOfSteps(int steps, char mode);

void homeStepper(char mode);

void stepperdriver_rotateTo(int targetDegrees, char mode);


/* [] END OF FILE */
