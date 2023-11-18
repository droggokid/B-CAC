/*******************************************************************************
* File Name: intpin.h  
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

#if !defined(CY_PINS_intpin_H) /* Pins intpin_H */
#define CY_PINS_intpin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "intpin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 intpin__PORT == 15 && ((intpin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    intpin_Write(uint8 value);
void    intpin_SetDriveMode(uint8 mode);
uint8   intpin_ReadDataReg(void);
uint8   intpin_Read(void);
void    intpin_SetInterruptMode(uint16 position, uint16 mode);
uint8   intpin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the intpin_SetDriveMode() function.
     *  @{
     */
        #define intpin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define intpin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define intpin_DM_RES_UP          PIN_DM_RES_UP
        #define intpin_DM_RES_DWN         PIN_DM_RES_DWN
        #define intpin_DM_OD_LO           PIN_DM_OD_LO
        #define intpin_DM_OD_HI           PIN_DM_OD_HI
        #define intpin_DM_STRONG          PIN_DM_STRONG
        #define intpin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define intpin_MASK               intpin__MASK
#define intpin_SHIFT              intpin__SHIFT
#define intpin_WIDTH              1u

/* Interrupt constants */
#if defined(intpin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in intpin_SetInterruptMode() function.
     *  @{
     */
        #define intpin_INTR_NONE      (uint16)(0x0000u)
        #define intpin_INTR_RISING    (uint16)(0x0001u)
        #define intpin_INTR_FALLING   (uint16)(0x0002u)
        #define intpin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define intpin_INTR_MASK      (0x01u) 
#endif /* (intpin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define intpin_PS                     (* (reg8 *) intpin__PS)
/* Data Register */
#define intpin_DR                     (* (reg8 *) intpin__DR)
/* Port Number */
#define intpin_PRT_NUM                (* (reg8 *) intpin__PRT) 
/* Connect to Analog Globals */                                                  
#define intpin_AG                     (* (reg8 *) intpin__AG)                       
/* Analog MUX bux enable */
#define intpin_AMUX                   (* (reg8 *) intpin__AMUX) 
/* Bidirectional Enable */                                                        
#define intpin_BIE                    (* (reg8 *) intpin__BIE)
/* Bit-mask for Aliased Register Access */
#define intpin_BIT_MASK               (* (reg8 *) intpin__BIT_MASK)
/* Bypass Enable */
#define intpin_BYP                    (* (reg8 *) intpin__BYP)
/* Port wide control signals */                                                   
#define intpin_CTL                    (* (reg8 *) intpin__CTL)
/* Drive Modes */
#define intpin_DM0                    (* (reg8 *) intpin__DM0) 
#define intpin_DM1                    (* (reg8 *) intpin__DM1)
#define intpin_DM2                    (* (reg8 *) intpin__DM2) 
/* Input Buffer Disable Override */
#define intpin_INP_DIS                (* (reg8 *) intpin__INP_DIS)
/* LCD Common or Segment Drive */
#define intpin_LCD_COM_SEG            (* (reg8 *) intpin__LCD_COM_SEG)
/* Enable Segment LCD */
#define intpin_LCD_EN                 (* (reg8 *) intpin__LCD_EN)
/* Slew Rate Control */
#define intpin_SLW                    (* (reg8 *) intpin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define intpin_PRTDSI__CAPS_SEL       (* (reg8 *) intpin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define intpin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) intpin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define intpin_PRTDSI__OE_SEL0        (* (reg8 *) intpin__PRTDSI__OE_SEL0) 
#define intpin_PRTDSI__OE_SEL1        (* (reg8 *) intpin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define intpin_PRTDSI__OUT_SEL0       (* (reg8 *) intpin__PRTDSI__OUT_SEL0) 
#define intpin_PRTDSI__OUT_SEL1       (* (reg8 *) intpin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define intpin_PRTDSI__SYNC_OUT       (* (reg8 *) intpin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(intpin__SIO_CFG)
    #define intpin_SIO_HYST_EN        (* (reg8 *) intpin__SIO_HYST_EN)
    #define intpin_SIO_REG_HIFREQ     (* (reg8 *) intpin__SIO_REG_HIFREQ)
    #define intpin_SIO_CFG            (* (reg8 *) intpin__SIO_CFG)
    #define intpin_SIO_DIFF           (* (reg8 *) intpin__SIO_DIFF)
#endif /* (intpin__SIO_CFG) */

/* Interrupt Registers */
#if defined(intpin__INTSTAT)
    #define intpin_INTSTAT            (* (reg8 *) intpin__INTSTAT)
    #define intpin_SNAP               (* (reg8 *) intpin__SNAP)
    
	#define intpin_0_INTTYPE_REG 		(* (reg8 *) intpin__0__INTTYPE)
#endif /* (intpin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_intpin_H */


/* [] END OF FILE */
