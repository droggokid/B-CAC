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
#include "stepper.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    stepperdriver_init();
    /* Replace with your application code */
    for(;;) 
    {
				
		
        stepperdriver_rotateTo(0,'h');
		CyDelay(2000);
		stepperdriver_rotateTo(180,'h');
        stop();
		CyDelay(2000);
		stepperdriver_rotateTo(0,'h');
        stop();
		CyDelay(2000);
		stepperdriver_rotateTo(180,'h');
        stop();
		CyDelay(2000);
		stepperdriver_rotateTo(0,'h');
        stop();
		CyDelay(2000);
		stepperdriver_rotateTo(180,'h');
        stop();
		CyDelay(2000);
    }
}

/* [] END OF FILE */
