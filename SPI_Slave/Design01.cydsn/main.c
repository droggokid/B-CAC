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
#include "spi_Slave.h"

CY_ISR(SPI_RX_ISR)
{
    //definere status
    uint8_t status;
    
    //lægger commando ind i status
    status = modtagetSPi();
    
    //håndtering af status
    if(status==0b10000000)
     LED_1_Write(1);
    else
     LED_1_Write(0);
    
    //læser om knappen er tændt eller slukket
    //slukket
    if(Button_1_Read())
    status &=0b11111110;
    //tændt
    else
    status |=0b00000001;
    
    
    //sender status tilbage
    sendSPi(status);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    SPI_RX_ISR_StartEx(SPI_RX_ISR);

    //initialisereSPI
    InitializeSPI();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        
    }
}

/* [] END OF FILE */
