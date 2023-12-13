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
#include <stdio.h>


float zeroDriftOffset=0;





void initLoadcell(void)
{
    ADC_SAR_1_Start();
    ADC_SAR_1_StartConvert();
}



void offset_Zerodrift_calibrate(uint8_t repeats, float startoffset, float factor,uint8_t preload)
{
   float result_array[repeats];
    float result_gram;
    float result=0;
    
    int i=0;
            while(i<repeats)
            {
                if (ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT))
                {
                result_array[i]=ADC_SAR_1_GetResult16();
                result+=result_array[i];
                i++;
                }
            }
            
    result=result/repeats; 
    result_gram = (((float)result-startoffset)/factor); // Konvertering til gram
    zeroDriftOffset= result_gram-preload;
}
void wait_for_weight(float startoffset, float factor,uint8_t preload)
{
    float result_gram;
    while(result_gram<50)
    {
    if (ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT))
        {
            uint16_t result = ADC_SAR_1_GetResult16(); // << NOTE! This is NOT a voltage or a weight. It is just a number, which the voltage is converted to.
            result_gram = (((float)result-startoffset)/factor); // Konvertering til gram
            result_gram -=zeroDriftOffset;
            result_gram -=preload;
        }
    }
}

float readWeight(uint8_t repeats,float startoffset, float factor,uint8_t preload)
{
    uint8_t repeating = repeats;
    float result_array[repeating];
    float result_gram;
    float result=0;
    
    int i=0;
            while(i<repeating)
            {
                if (ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT))
                {
                result_array[i]=ADC_SAR_1_GetResult16();
                result+=result_array[i];
                i++;
                }
                
            }
            
            result=result/repeating; 
            result_gram = (((float)result-startoffset)/factor); // Konvertering til gram
            
    return result_gram-zeroDriftOffset-(float)preload;
}









/* [] END OF FILE */
