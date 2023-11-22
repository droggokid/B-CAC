/*******************************************************************************
* File Name: Channel_1_ISR.h
* Version 1.71
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Channel_1_ISR_H)
#define CY_ISR_Channel_1_ISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Channel_1_ISR_Start(void);
void Channel_1_ISR_StartEx(cyisraddress address);
void Channel_1_ISR_Stop(void);

CY_ISR_PROTO(Channel_1_ISR_Interrupt);

void Channel_1_ISR_SetVector(cyisraddress address);
cyisraddress Channel_1_ISR_GetVector(void);

void Channel_1_ISR_SetPriority(uint8 priority);
uint8 Channel_1_ISR_GetPriority(void);

void Channel_1_ISR_Enable(void);
uint8 Channel_1_ISR_GetState(void);
void Channel_1_ISR_Disable(void);

void Channel_1_ISR_SetPending(void);
void Channel_1_ISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Channel_1_ISR ISR. */
#define Channel_1_ISR_INTC_VECTOR            ((reg32 *) Channel_1_ISR__INTC_VECT)

/* Address of the Channel_1_ISR ISR priority. */
#define Channel_1_ISR_INTC_PRIOR             ((reg8 *) Channel_1_ISR__INTC_PRIOR_REG)

/* Priority of the Channel_1_ISR interrupt. */
#define Channel_1_ISR_INTC_PRIOR_NUMBER      Channel_1_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Channel_1_ISR interrupt. */
#define Channel_1_ISR_INTC_SET_EN            ((reg32 *) Channel_1_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Channel_1_ISR interrupt. */
#define Channel_1_ISR_INTC_CLR_EN            ((reg32 *) Channel_1_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Channel_1_ISR interrupt state to pending. */
#define Channel_1_ISR_INTC_SET_PD            ((reg32 *) Channel_1_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Channel_1_ISR interrupt. */
#define Channel_1_ISR_INTC_CLR_PD            ((reg32 *) Channel_1_ISR__INTC_CLR_PD_REG)


#endif /* CY_ISR_Channel_1_ISR_H */


/* [] END OF FILE */
