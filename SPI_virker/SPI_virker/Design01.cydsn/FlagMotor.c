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

#include "FlagMotor.h"
#define CLOSED_ANGLE 0
#define STEPS_PER_DEGREE_half 0.267 // Assuming a standard 200 steps per revolution stepper motor
#define STEPS_PER_DEGREE_other 0.133

static char stepCount = 0;
int currentPosition = CLOSED_ANGLE;



void coilA1(void)
{
    A2_Write(0);
    B1_Write(0);
    B2_Write(0);
    A1_Write(1);
}
void coilA2(void)
{
    B1_Write(0);
    B2_Write(0);
    A1_Write(0);
    A2_Write(1);
}
void coilB1(void)
{
    A2_Write(0);
    B2_Write(0);
    A1_Write(0);
    B1_Write(1);
}
void coilB2(void)
{
    A2_Write(0);
    B1_Write(0);
    A1_Write(0);
    B2_Write(1);
}
void coilA1A2(void)
{
    B1_Write(0);
    B2_Write(0);
    A1_Write(1);
    A2_Write(1);
}
void coilA2B1(void)
{
    A1_Write(0);
    B2_Write(0);
    B1_Write(1);
    A2_Write(1);
}
void coilB1B2(void)
{
    A2_Write(0);
    A1_Write(0);
    B2_Write(1);
    B1_Write(1);
}
void coilB2A1(void)
{
    B1_Write(0);
    A2_Write(0);
    A1_Write(1);
    B2_Write(1);
}
void stopFlagMotor(void)
{
    B1_Write(0);
    B2_Write(0);
    A1_Write(0);
    A2_Write(0);
}


void takeStep(char stepMode, char direction)
{
	
	 switch(stepMode)
	 {
		 case 'w':
		 {
			 switch(stepCount)
			 {
				 case 0:
				 case 1:
				 {
					 
					 
					 if(direction==1)
						coilA1();
					 else
						coilB2();
                        
                        stepCount+=2;
					 
				 }
				 break;
				 case 2:
				 case 3:
				 {
					 
					 if(direction==1)
                        coilA2();
						
					 else
                        coilB1();
						
                        stepCount+=2;
				 }
				 break;
				 case 4:
				 case 5:
				 {
					 
					 if(direction==1)
                        coilB1();
					else
						coilA2();
                        
                        stepCount+=2;
					 
				 }
				 break;
				 case 6:
				 case 7:
				 {
					 
					 if(direction==1)
                        coilB2();
						
					 else
						coilA1();
                        stepCount=0;
                        
                }
				 break;
				 
				 
			 }
		 }
		 break;
		 case 'f' :
		 {
			 switch(stepCount)
			 {
				 case 0:
				 case 1:
				 {
					 
					 
					 if(direction==1)
                        coilA1A2();
					 else
						coilB2A1();
                        
                        stepCount+=2;
					 
				 }
				 break;
				 case 2:
				 case 3:
				 {
					 
					 if(direction==1)
						coilA2B1();
					 else
						coilB1B2();
                        
                    stepCount+=2;
				 }
				 break;
				 case 4:
				 case 5:
				 {
					 
					 if(direction==1)
						coilB1B2();
					 else
						coilA2B1();
					 
                    stepCount+=2;
				 }
				 break;
				 case 6:
				 case 7:
				 {
					 
					 if(direction==1)
						coilB2A1();
					 else
					    coilA1A2();
				 }
                
                stepCount=0;
				 break;
				 
				 
			 }
		 }
		 break;
		 case 'h' :
		 {
			 switch(stepCount)
			 {
				 case 0:
				 {
					 
					 
					 if(direction==1)
                    {coilA1();
                    stepCount++;}
					 else
                    {coilB2A1();
                    stepCount++;}
                    
					 
				 }
				 break;
				 case 1:
				 {
					 
					 
					 if(direction==1)
                    {coilA1A2();
                    stepCount++;}
					 else
                    {coilB2();
                    stepCount++;}
					 
                    
				 }
				 break;
				 case 2:
				 {
					 
					 if(direction==1)
                    {coilA2();
                    stepCount++;}
					 else
                    {coilB1B2();
                    stepCount++;}
                        
                     
				 }
				 break;
				 case 3:
				 {
					 
					 if(direction==1)
                    {coilA2B1();
                    stepCount++;}
					 else
                    {coilB1();
                    stepCount++;}
                        
                    
				 }
				 break;
				 case 4:
				 {
					 
					 if(direction==1)
                    {coilB1();
                    stepCount++;}
					 else
                    {coilA2B1();
                    stepCount++;}
                    
					 
				 }
				 break;
				 case 5:
				 {
					 
					 if(direction==1)
                    {coilB1B2();
                    stepCount++;}
					 else
                    {coilA2();
                    stepCount++;}
                    
				 }
				 break;
				 case 6:
				 {
					 
					 if(direction==1)
                    {coilB2();
                    stepCount++;}
					 else
                    {coilA1A2();
                    stepCount++;}
                        
                    
				 }
				 break;
				 case 7:
				 {
					 
					 if(direction==1)
                    {coilB2A1();
                    stepCount=0;}
					 else
                    {coilA1();
                    stepCount=0;}
                   
				 }
				 break;
				 
				 
			 }
		 }
		 break;
		 default :
		 {
			 // nothing
		 }
		 break;
	 }
}

void numberOfSteps(int steps, char mode)
{
	if(steps<0)
	for(int i=0; i>steps; i--)// tager antal steps
	{
		
		takeStep(mode, 0);
    	CyDelay(5);
		
	}
	
	 for(int i=0; i<steps; i++)// tager antal steps
	 {
		 
		takeStep(mode, 1);
	    CyDelay(5);
		 
	 }
	 
}



void homeStepper(char mode){
     if(mode == 'h')
    numberOfSteps(-96, mode);
    else
    numberOfSteps(-48, mode);
    currentPosition=0;
    flagMotorRotateTo(0, mode);
    
}


void flagMotorRotateTo(int targetDegrees, char mode) {
	
	
    if(mode == 'h')
    {
    	if(targetDegrees!=currentPosition)
		{
			int stepsToTake = (targetDegrees - currentPosition) * STEPS_PER_DEGREE_half;

			currentPosition = targetDegrees;

			numberOfSteps(stepsToTake, mode);
		}
        }
    else
        {
		if(targetDegrees!=currentPosition)
		{
			int stepsToTake = (targetDegrees - currentPosition) * STEPS_PER_DEGREE_other;

			currentPosition = targetDegrees;

			numberOfSteps(stepsToTake, mode);
		}
        }
	
}





/* [] END OF FILE */


/* [] END OF FILE */
