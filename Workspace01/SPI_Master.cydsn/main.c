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
#include "SPI_Master.h"
#include "Terminal.h"



CY_ISR(SPI_RX_ISR){
    while(SPIM_1_ReadRxStatus() & SPIM_1_STS_RX_FIFO_NOT_EMPTY){
        setData_UART(SPIM_1_ReadRxData());    
    }
}

CY_ISR(UART_RX_ISR){
    
    char data;
    data = UART_1_ReadRxData();
    UART_1_PutString("\033[2J");
    
    switch(data){
        case '1':
        setData_SPI(0x80);
        UART_1_PutString("LED taendt\n\r");
        UART_1_PutString("Tryk s for update, 0 for slukke LED, og 1 for taend LED\n\r");   
        break;
        
        case '0':
        setData_SPI(0x00);
        UART_1_PutString("LED slukket\n\r");
        UART_1_PutString("Tryk s for update, 0 for slukke LED, og 1 for taend LED\n\r");   
        break;
        
        case 's':
        print();
        break;
    }
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    SPI_RX_ISR_StartEx(SPI_RX_ISR);
    UART_RX_ISR_StartEx(UART_RX_ISR);
    UART_1_Start();
    SPIM_1_Start();
        

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    for(;;)
    {
        /* Place your application code here. */
        requestStatus();
        CyDelay(100);
    }
}

/* [] END OF FILE */
