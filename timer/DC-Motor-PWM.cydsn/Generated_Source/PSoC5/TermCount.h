/*******************************************************************************
* File Name: TermCount.h  
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

#if !defined(CY_PINS_TermCount_H) /* Pins TermCount_H */
#define CY_PINS_TermCount_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TermCount_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TermCount__PORT == 15 && ((TermCount__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TermCount_Write(uint8 value);
void    TermCount_SetDriveMode(uint8 mode);
uint8   TermCount_ReadDataReg(void);
uint8   TermCount_Read(void);
void    TermCount_SetInterruptMode(uint16 position, uint16 mode);
uint8   TermCount_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TermCount_SetDriveMode() function.
     *  @{
     */
        #define TermCount_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TermCount_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TermCount_DM_RES_UP          PIN_DM_RES_UP
        #define TermCount_DM_RES_DWN         PIN_DM_RES_DWN
        #define TermCount_DM_OD_LO           PIN_DM_OD_LO
        #define TermCount_DM_OD_HI           PIN_DM_OD_HI
        #define TermCount_DM_STRONG          PIN_DM_STRONG
        #define TermCount_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TermCount_MASK               TermCount__MASK
#define TermCount_SHIFT              TermCount__SHIFT
#define TermCount_WIDTH              1u

/* Interrupt constants */
#if defined(TermCount__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TermCount_SetInterruptMode() function.
     *  @{
     */
        #define TermCount_INTR_NONE      (uint16)(0x0000u)
        #define TermCount_INTR_RISING    (uint16)(0x0001u)
        #define TermCount_INTR_FALLING   (uint16)(0x0002u)
        #define TermCount_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TermCount_INTR_MASK      (0x01u) 
#endif /* (TermCount__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TermCount_PS                     (* (reg8 *) TermCount__PS)
/* Data Register */
#define TermCount_DR                     (* (reg8 *) TermCount__DR)
/* Port Number */
#define TermCount_PRT_NUM                (* (reg8 *) TermCount__PRT) 
/* Connect to Analog Globals */                                                  
#define TermCount_AG                     (* (reg8 *) TermCount__AG)                       
/* Analog MUX bux enable */
#define TermCount_AMUX                   (* (reg8 *) TermCount__AMUX) 
/* Bidirectional Enable */                                                        
#define TermCount_BIE                    (* (reg8 *) TermCount__BIE)
/* Bit-mask for Aliased Register Access */
#define TermCount_BIT_MASK               (* (reg8 *) TermCount__BIT_MASK)
/* Bypass Enable */
#define TermCount_BYP                    (* (reg8 *) TermCount__BYP)
/* Port wide control signals */                                                   
#define TermCount_CTL                    (* (reg8 *) TermCount__CTL)
/* Drive Modes */
#define TermCount_DM0                    (* (reg8 *) TermCount__DM0) 
#define TermCount_DM1                    (* (reg8 *) TermCount__DM1)
#define TermCount_DM2                    (* (reg8 *) TermCount__DM2) 
/* Input Buffer Disable Override */
#define TermCount_INP_DIS                (* (reg8 *) TermCount__INP_DIS)
/* LCD Common or Segment Drive */
#define TermCount_LCD_COM_SEG            (* (reg8 *) TermCount__LCD_COM_SEG)
/* Enable Segment LCD */
#define TermCount_LCD_EN                 (* (reg8 *) TermCount__LCD_EN)
/* Slew Rate Control */
#define TermCount_SLW                    (* (reg8 *) TermCount__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TermCount_PRTDSI__CAPS_SEL       (* (reg8 *) TermCount__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TermCount_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TermCount__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TermCount_PRTDSI__OE_SEL0        (* (reg8 *) TermCount__PRTDSI__OE_SEL0) 
#define TermCount_PRTDSI__OE_SEL1        (* (reg8 *) TermCount__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TermCount_PRTDSI__OUT_SEL0       (* (reg8 *) TermCount__PRTDSI__OUT_SEL0) 
#define TermCount_PRTDSI__OUT_SEL1       (* (reg8 *) TermCount__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TermCount_PRTDSI__SYNC_OUT       (* (reg8 *) TermCount__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TermCount__SIO_CFG)
    #define TermCount_SIO_HYST_EN        (* (reg8 *) TermCount__SIO_HYST_EN)
    #define TermCount_SIO_REG_HIFREQ     (* (reg8 *) TermCount__SIO_REG_HIFREQ)
    #define TermCount_SIO_CFG            (* (reg8 *) TermCount__SIO_CFG)
    #define TermCount_SIO_DIFF           (* (reg8 *) TermCount__SIO_DIFF)
#endif /* (TermCount__SIO_CFG) */

/* Interrupt Registers */
#if defined(TermCount__INTSTAT)
    #define TermCount_INTSTAT            (* (reg8 *) TermCount__INTSTAT)
    #define TermCount_SNAP               (* (reg8 *) TermCount__SNAP)
    
	#define TermCount_0_INTTYPE_REG 		(* (reg8 *) TermCount__0__INTTYPE)
#endif /* (TermCount__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TermCount_H */


/* [] END OF FILE */
