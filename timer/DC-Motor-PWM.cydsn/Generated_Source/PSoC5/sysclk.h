/*******************************************************************************
* File Name: sysclk.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_sysclk_H)
#define CY_CLOCK_sysclk_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void sysclk_Start(void) ;
void sysclk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void sysclk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void sysclk_StandbyPower(uint8 state) ;
void sysclk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 sysclk_GetDividerRegister(void) ;
void sysclk_SetModeRegister(uint8 modeBitMask) ;
void sysclk_ClearModeRegister(uint8 modeBitMask) ;
uint8 sysclk_GetModeRegister(void) ;
void sysclk_SetSourceRegister(uint8 clkSource) ;
uint8 sysclk_GetSourceRegister(void) ;
#if defined(sysclk__CFG3)
void sysclk_SetPhaseRegister(uint8 clkPhase) ;
uint8 sysclk_GetPhaseRegister(void) ;
#endif /* defined(sysclk__CFG3) */

#define sysclk_Enable()                       sysclk_Start()
#define sysclk_Disable()                      sysclk_Stop()
#define sysclk_SetDivider(clkDivider)         sysclk_SetDividerRegister(clkDivider, 1u)
#define sysclk_SetDividerValue(clkDivider)    sysclk_SetDividerRegister((clkDivider) - 1u, 1u)
#define sysclk_SetMode(clkMode)               sysclk_SetModeRegister(clkMode)
#define sysclk_SetSource(clkSource)           sysclk_SetSourceRegister(clkSource)
#if defined(sysclk__CFG3)
#define sysclk_SetPhase(clkPhase)             sysclk_SetPhaseRegister(clkPhase)
#define sysclk_SetPhaseValue(clkPhase)        sysclk_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(sysclk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define sysclk_CLKEN              (* (reg8 *) sysclk__PM_ACT_CFG)
#define sysclk_CLKEN_PTR          ((reg8 *) sysclk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define sysclk_CLKSTBY            (* (reg8 *) sysclk__PM_STBY_CFG)
#define sysclk_CLKSTBY_PTR        ((reg8 *) sysclk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define sysclk_DIV_LSB            (* (reg8 *) sysclk__CFG0)
#define sysclk_DIV_LSB_PTR        ((reg8 *) sysclk__CFG0)
#define sysclk_DIV_PTR            ((reg16 *) sysclk__CFG0)

/* Clock MSB divider configuration register. */
#define sysclk_DIV_MSB            (* (reg8 *) sysclk__CFG1)
#define sysclk_DIV_MSB_PTR        ((reg8 *) sysclk__CFG1)

/* Mode and source configuration register */
#define sysclk_MOD_SRC            (* (reg8 *) sysclk__CFG2)
#define sysclk_MOD_SRC_PTR        ((reg8 *) sysclk__CFG2)

#if defined(sysclk__CFG3)
/* Analog clock phase configuration register */
#define sysclk_PHASE              (* (reg8 *) sysclk__CFG3)
#define sysclk_PHASE_PTR          ((reg8 *) sysclk__CFG3)
#endif /* defined(sysclk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define sysclk_CLKEN_MASK         sysclk__PM_ACT_MSK
#define sysclk_CLKSTBY_MASK       sysclk__PM_STBY_MSK

/* CFG2 field masks */
#define sysclk_SRC_SEL_MSK        sysclk__CFG2_SRC_SEL_MASK
#define sysclk_MODE_MASK          (~(sysclk_SRC_SEL_MSK))

#if defined(sysclk__CFG3)
/* CFG3 phase mask */
#define sysclk_PHASE_MASK         sysclk__CFG3_PHASE_DLY_MASK
#endif /* defined(sysclk__CFG3) */

#endif /* CY_CLOCK_sysclk_H */


/* [] END OF FILE */
