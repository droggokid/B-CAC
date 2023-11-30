/*******************************************************************************
* File Name: ledGreen.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ledGreen_H) /* Pins ledGreen_H */
#define CY_PINS_ledGreen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ledGreen_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ledGreen__PORT == 15 && ((ledGreen__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ledGreen_Write(uint8 value);
void    ledGreen_SetDriveMode(uint8 mode);
uint8   ledGreen_ReadDataReg(void);
uint8   ledGreen_Read(void);
void    ledGreen_SetInterruptMode(uint16 position, uint16 mode);
uint8   ledGreen_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ledGreen_SetDriveMode() function.
     *  @{
     */
        #define ledGreen_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ledGreen_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ledGreen_DM_RES_UP          PIN_DM_RES_UP
        #define ledGreen_DM_RES_DWN         PIN_DM_RES_DWN
        #define ledGreen_DM_OD_LO           PIN_DM_OD_LO
        #define ledGreen_DM_OD_HI           PIN_DM_OD_HI
        #define ledGreen_DM_STRONG          PIN_DM_STRONG
        #define ledGreen_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ledGreen_MASK               ledGreen__MASK
#define ledGreen_SHIFT              ledGreen__SHIFT
#define ledGreen_WIDTH              1u

/* Interrupt constants */
#if defined(ledGreen__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ledGreen_SetInterruptMode() function.
     *  @{
     */
        #define ledGreen_INTR_NONE      (uint16)(0x0000u)
        #define ledGreen_INTR_RISING    (uint16)(0x0001u)
        #define ledGreen_INTR_FALLING   (uint16)(0x0002u)
        #define ledGreen_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ledGreen_INTR_MASK      (0x01u) 
#endif /* (ledGreen__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ledGreen_PS                     (* (reg8 *) ledGreen__PS)
/* Data Register */
#define ledGreen_DR                     (* (reg8 *) ledGreen__DR)
/* Port Number */
#define ledGreen_PRT_NUM                (* (reg8 *) ledGreen__PRT) 
/* Connect to Analog Globals */                                                  
#define ledGreen_AG                     (* (reg8 *) ledGreen__AG)                       
/* Analog MUX bux enable */
#define ledGreen_AMUX                   (* (reg8 *) ledGreen__AMUX) 
/* Bidirectional Enable */                                                        
#define ledGreen_BIE                    (* (reg8 *) ledGreen__BIE)
/* Bit-mask for Aliased Register Access */
#define ledGreen_BIT_MASK               (* (reg8 *) ledGreen__BIT_MASK)
/* Bypass Enable */
#define ledGreen_BYP                    (* (reg8 *) ledGreen__BYP)
/* Port wide control signals */                                                   
#define ledGreen_CTL                    (* (reg8 *) ledGreen__CTL)
/* Drive Modes */
#define ledGreen_DM0                    (* (reg8 *) ledGreen__DM0) 
#define ledGreen_DM1                    (* (reg8 *) ledGreen__DM1)
#define ledGreen_DM2                    (* (reg8 *) ledGreen__DM2) 
/* Input Buffer Disable Override */
#define ledGreen_INP_DIS                (* (reg8 *) ledGreen__INP_DIS)
/* LCD Common or Segment Drive */
#define ledGreen_LCD_COM_SEG            (* (reg8 *) ledGreen__LCD_COM_SEG)
/* Enable Segment LCD */
#define ledGreen_LCD_EN                 (* (reg8 *) ledGreen__LCD_EN)
/* Slew Rate Control */
#define ledGreen_SLW                    (* (reg8 *) ledGreen__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ledGreen_PRTDSI__CAPS_SEL       (* (reg8 *) ledGreen__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ledGreen_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ledGreen__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ledGreen_PRTDSI__OE_SEL0        (* (reg8 *) ledGreen__PRTDSI__OE_SEL0) 
#define ledGreen_PRTDSI__OE_SEL1        (* (reg8 *) ledGreen__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ledGreen_PRTDSI__OUT_SEL0       (* (reg8 *) ledGreen__PRTDSI__OUT_SEL0) 
#define ledGreen_PRTDSI__OUT_SEL1       (* (reg8 *) ledGreen__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ledGreen_PRTDSI__SYNC_OUT       (* (reg8 *) ledGreen__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ledGreen__SIO_CFG)
    #define ledGreen_SIO_HYST_EN        (* (reg8 *) ledGreen__SIO_HYST_EN)
    #define ledGreen_SIO_REG_HIFREQ     (* (reg8 *) ledGreen__SIO_REG_HIFREQ)
    #define ledGreen_SIO_CFG            (* (reg8 *) ledGreen__SIO_CFG)
    #define ledGreen_SIO_DIFF           (* (reg8 *) ledGreen__SIO_DIFF)
#endif /* (ledGreen__SIO_CFG) */

/* Interrupt Registers */
#if defined(ledGreen__INTSTAT)
    #define ledGreen_INTSTAT            (* (reg8 *) ledGreen__INTSTAT)
    #define ledGreen_SNAP               (* (reg8 *) ledGreen__SNAP)
    
	#define ledGreen_0_INTTYPE_REG 		(* (reg8 *) ledGreen__0__INTTYPE)
#endif /* (ledGreen__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ledGreen_H */


/* [] END OF FILE */
