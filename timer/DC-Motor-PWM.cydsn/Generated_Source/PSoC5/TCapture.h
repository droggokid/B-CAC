/*******************************************************************************
* File Name: TCapture.h  
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

#if !defined(CY_PINS_TCapture_H) /* Pins TCapture_H */
#define CY_PINS_TCapture_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TCapture_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TCapture__PORT == 15 && ((TCapture__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TCapture_Write(uint8 value);
void    TCapture_SetDriveMode(uint8 mode);
uint8   TCapture_ReadDataReg(void);
uint8   TCapture_Read(void);
void    TCapture_SetInterruptMode(uint16 position, uint16 mode);
uint8   TCapture_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TCapture_SetDriveMode() function.
     *  @{
     */
        #define TCapture_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TCapture_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TCapture_DM_RES_UP          PIN_DM_RES_UP
        #define TCapture_DM_RES_DWN         PIN_DM_RES_DWN
        #define TCapture_DM_OD_LO           PIN_DM_OD_LO
        #define TCapture_DM_OD_HI           PIN_DM_OD_HI
        #define TCapture_DM_STRONG          PIN_DM_STRONG
        #define TCapture_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TCapture_MASK               TCapture__MASK
#define TCapture_SHIFT              TCapture__SHIFT
#define TCapture_WIDTH              1u

/* Interrupt constants */
#if defined(TCapture__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TCapture_SetInterruptMode() function.
     *  @{
     */
        #define TCapture_INTR_NONE      (uint16)(0x0000u)
        #define TCapture_INTR_RISING    (uint16)(0x0001u)
        #define TCapture_INTR_FALLING   (uint16)(0x0002u)
        #define TCapture_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TCapture_INTR_MASK      (0x01u) 
#endif /* (TCapture__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TCapture_PS                     (* (reg8 *) TCapture__PS)
/* Data Register */
#define TCapture_DR                     (* (reg8 *) TCapture__DR)
/* Port Number */
#define TCapture_PRT_NUM                (* (reg8 *) TCapture__PRT) 
/* Connect to Analog Globals */                                                  
#define TCapture_AG                     (* (reg8 *) TCapture__AG)                       
/* Analog MUX bux enable */
#define TCapture_AMUX                   (* (reg8 *) TCapture__AMUX) 
/* Bidirectional Enable */                                                        
#define TCapture_BIE                    (* (reg8 *) TCapture__BIE)
/* Bit-mask for Aliased Register Access */
#define TCapture_BIT_MASK               (* (reg8 *) TCapture__BIT_MASK)
/* Bypass Enable */
#define TCapture_BYP                    (* (reg8 *) TCapture__BYP)
/* Port wide control signals */                                                   
#define TCapture_CTL                    (* (reg8 *) TCapture__CTL)
/* Drive Modes */
#define TCapture_DM0                    (* (reg8 *) TCapture__DM0) 
#define TCapture_DM1                    (* (reg8 *) TCapture__DM1)
#define TCapture_DM2                    (* (reg8 *) TCapture__DM2) 
/* Input Buffer Disable Override */
#define TCapture_INP_DIS                (* (reg8 *) TCapture__INP_DIS)
/* LCD Common or Segment Drive */
#define TCapture_LCD_COM_SEG            (* (reg8 *) TCapture__LCD_COM_SEG)
/* Enable Segment LCD */
#define TCapture_LCD_EN                 (* (reg8 *) TCapture__LCD_EN)
/* Slew Rate Control */
#define TCapture_SLW                    (* (reg8 *) TCapture__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TCapture_PRTDSI__CAPS_SEL       (* (reg8 *) TCapture__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TCapture_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TCapture__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TCapture_PRTDSI__OE_SEL0        (* (reg8 *) TCapture__PRTDSI__OE_SEL0) 
#define TCapture_PRTDSI__OE_SEL1        (* (reg8 *) TCapture__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TCapture_PRTDSI__OUT_SEL0       (* (reg8 *) TCapture__PRTDSI__OUT_SEL0) 
#define TCapture_PRTDSI__OUT_SEL1       (* (reg8 *) TCapture__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TCapture_PRTDSI__SYNC_OUT       (* (reg8 *) TCapture__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TCapture__SIO_CFG)
    #define TCapture_SIO_HYST_EN        (* (reg8 *) TCapture__SIO_HYST_EN)
    #define TCapture_SIO_REG_HIFREQ     (* (reg8 *) TCapture__SIO_REG_HIFREQ)
    #define TCapture_SIO_CFG            (* (reg8 *) TCapture__SIO_CFG)
    #define TCapture_SIO_DIFF           (* (reg8 *) TCapture__SIO_DIFF)
#endif /* (TCapture__SIO_CFG) */

/* Interrupt Registers */
#if defined(TCapture__INTSTAT)
    #define TCapture_INTSTAT            (* (reg8 *) TCapture__INTSTAT)
    #define TCapture_SNAP               (* (reg8 *) TCapture__SNAP)
    
	#define TCapture_0_INTTYPE_REG 		(* (reg8 *) TCapture__0__INTTYPE)
#endif /* (TCapture__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TCapture_H */


/* [] END OF FILE */
