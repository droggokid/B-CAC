#include "project.h"
#include "spi_Slave.h"

CY_ISR(SPI_RX_ISR)
{
    // Define status
    uint8_t status;
    
    // Get the command from SPI
    status = modtagetSPi();
    
    // Handle the status
    // If anything is received, turn off the LED
    if(status != 0)
    {
        LED_1_Write(1); // Turn on the LED
    }
    else
    {
        // Read the button status
        // If the button is off, clear the least significant bit
        if(Button_1_Read())
            status &= 0b11111110;
        // If the button is on, set the least significant bit
        else
            status |= 0b00000001;
        
        // Send back the status
        sendSPi(status);
        
        // Turn off the LED
        LED_1_Write(0);
    }
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    SPI_RX_ISR_StartEx(SPI_RX_ISR);

    // Initialize SPI
    InitializeSPI(); // Make sure this function is correctly configuring the SPI module

    /* Place your initialization/startup code here (e.g., MyInst_Start()) */
    for(;;)
    {
        // Your main loop code here
    }
}

/* [] END OF FILE */
