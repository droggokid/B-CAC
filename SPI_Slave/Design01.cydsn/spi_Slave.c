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

#include "spi_Slave.h"

void InitializeSPI(void)
{
    // Initialiser SPI-modulet her
    SPIS_2_Start();
    
}

uint8_t modtagetSPi(void)
{
    
    uint8_t receivedData = 0;
    // Lyt for kommandoer fra masteren via SPI
    
    while(SPIS_2_GetRxBufferSize() != 0)
    {
        receivedData = SPIS_2_ReadRxData();
    }
   //returnere dataen    
    return receivedData;
     
}
void sendSPi(uint8_t data)
{
   // Vent, indtil TX-bufferen er klar til at sende data
//    while ((SPIS_2_ReadTxStatus() & SPIS_2_STS_TX_FIFO_NOT_FULL)==0)
//    {
        // Vent, indtil TX-bufferen er klar
//    }
    SPIS_2_ClearTxBuffer();
    // Skriver data til TX-bufferen for at sende det til masteren
    SPIS_2_WriteTxData(data);
}
/* [] END OF FILE */
