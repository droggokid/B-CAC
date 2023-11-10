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
#include "SPI_Master.h"
uint8_t send_data = 0x00;

void requestStatus(){
    SPIM_1_WriteTxData(send_data);  
}

void setData_SPI(uint8_t data){
    send_data = data;   
}



/* [] END OF FILE */
