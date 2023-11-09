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
#include "Terminal.h"
uint8_t rx_data;

void print(){
        
    UART_1_PutString("\033[2J");
    
    if(rx_data & 0x80)
        UART_1_PutString("LED er taendt\r\n");
    else
        UART_1_PutString("LED er slukket\r\n");
    
    if(rx_data & 0x01)
        UART_1_PutString("Knap er trykket\r\n");
    else
        UART_1_PutString("Knap er ikke trykket\r\n");
    UART_1_PutString("Tryk s for update, 0 for slukke LED, og 1 for taend LED\n\r");   
        

}

void setData_UART(uint8_t data){
    rx_data = data;
}
    



/* [] END OF FILE */
