;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.2
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; A1
A1__0__INTTYPE EQU CYREG_PICU1_INTTYPE7
A1__0__MASK EQU 0x80
A1__0__PC EQU CYREG_PRT1_PC7
A1__0__PORT EQU 1
A1__0__SHIFT EQU 7
A1__AG EQU CYREG_PRT1_AG
A1__AMUX EQU CYREG_PRT1_AMUX
A1__BIE EQU CYREG_PRT1_BIE
A1__BIT_MASK EQU CYREG_PRT1_BIT_MASK
A1__BYP EQU CYREG_PRT1_BYP
A1__CTL EQU CYREG_PRT1_CTL
A1__DM0 EQU CYREG_PRT1_DM0
A1__DM1 EQU CYREG_PRT1_DM1
A1__DM2 EQU CYREG_PRT1_DM2
A1__DR EQU CYREG_PRT1_DR
A1__INP_DIS EQU CYREG_PRT1_INP_DIS
A1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
A1__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
A1__LCD_EN EQU CYREG_PRT1_LCD_EN
A1__MASK EQU 0x80
A1__PORT EQU 1
A1__PRT EQU CYREG_PRT1_PRT
A1__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
A1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
A1__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
A1__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
A1__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
A1__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
A1__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
A1__PS EQU CYREG_PRT1_PS
A1__SHIFT EQU 7
A1__SLW EQU CYREG_PRT1_SLW

; A2
A2__0__INTTYPE EQU CYREG_PICU2_INTTYPE1
A2__0__MASK EQU 0x02
A2__0__PC EQU CYREG_PRT2_PC1
A2__0__PORT EQU 2
A2__0__SHIFT EQU 1
A2__AG EQU CYREG_PRT2_AG
A2__AMUX EQU CYREG_PRT2_AMUX
A2__BIE EQU CYREG_PRT2_BIE
A2__BIT_MASK EQU CYREG_PRT2_BIT_MASK
A2__BYP EQU CYREG_PRT2_BYP
A2__CTL EQU CYREG_PRT2_CTL
A2__DM0 EQU CYREG_PRT2_DM0
A2__DM1 EQU CYREG_PRT2_DM1
A2__DM2 EQU CYREG_PRT2_DM2
A2__DR EQU CYREG_PRT2_DR
A2__INP_DIS EQU CYREG_PRT2_INP_DIS
A2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
A2__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
A2__LCD_EN EQU CYREG_PRT2_LCD_EN
A2__MASK EQU 0x02
A2__PORT EQU 2
A2__PRT EQU CYREG_PRT2_PRT
A2__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
A2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
A2__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
A2__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
A2__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
A2__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
A2__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
A2__PS EQU CYREG_PRT2_PS
A2__SHIFT EQU 1
A2__SLW EQU CYREG_PRT2_SLW

; B1
B1__0__INTTYPE EQU CYREG_PICU1_INTTYPE6
B1__0__MASK EQU 0x40
B1__0__PC EQU CYREG_PRT1_PC6
B1__0__PORT EQU 1
B1__0__SHIFT EQU 6
B1__AG EQU CYREG_PRT1_AG
B1__AMUX EQU CYREG_PRT1_AMUX
B1__BIE EQU CYREG_PRT1_BIE
B1__BIT_MASK EQU CYREG_PRT1_BIT_MASK
B1__BYP EQU CYREG_PRT1_BYP
B1__CTL EQU CYREG_PRT1_CTL
B1__DM0 EQU CYREG_PRT1_DM0
B1__DM1 EQU CYREG_PRT1_DM1
B1__DM2 EQU CYREG_PRT1_DM2
B1__DR EQU CYREG_PRT1_DR
B1__INP_DIS EQU CYREG_PRT1_INP_DIS
B1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
B1__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
B1__LCD_EN EQU CYREG_PRT1_LCD_EN
B1__MASK EQU 0x40
B1__PORT EQU 1
B1__PRT EQU CYREG_PRT1_PRT
B1__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
B1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
B1__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
B1__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
B1__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
B1__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
B1__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
B1__PS EQU CYREG_PRT1_PS
B1__SHIFT EQU 6
B1__SLW EQU CYREG_PRT1_SLW

; B2
B2__0__INTTYPE EQU CYREG_PICU2_INTTYPE0
B2__0__MASK EQU 0x01
B2__0__PC EQU CYREG_PRT2_PC0
B2__0__PORT EQU 2
B2__0__SHIFT EQU 0
B2__AG EQU CYREG_PRT2_AG
B2__AMUX EQU CYREG_PRT2_AMUX
B2__BIE EQU CYREG_PRT2_BIE
B2__BIT_MASK EQU CYREG_PRT2_BIT_MASK
B2__BYP EQU CYREG_PRT2_BYP
B2__CTL EQU CYREG_PRT2_CTL
B2__DM0 EQU CYREG_PRT2_DM0
B2__DM1 EQU CYREG_PRT2_DM1
B2__DM2 EQU CYREG_PRT2_DM2
B2__DR EQU CYREG_PRT2_DR
B2__INP_DIS EQU CYREG_PRT2_INP_DIS
B2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
B2__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
B2__LCD_EN EQU CYREG_PRT2_LCD_EN
B2__MASK EQU 0x01
B2__PORT EQU 2
B2__PRT EQU CYREG_PRT2_PRT
B2__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
B2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
B2__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
B2__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
B2__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
B2__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
B2__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
B2__PS EQU CYREG_PRT2_PS
B2__SHIFT EQU 0
B2__SLW EQU CYREG_PRT2_SLW

; Rx_1
Rx_1__0__INTTYPE EQU CYREG_PICU0_INTTYPE0
Rx_1__0__MASK EQU 0x01
Rx_1__0__PC EQU CYREG_PRT0_PC0
Rx_1__0__PORT EQU 0
Rx_1__0__SHIFT EQU 0
Rx_1__AG EQU CYREG_PRT0_AG
Rx_1__AMUX EQU CYREG_PRT0_AMUX
Rx_1__BIE EQU CYREG_PRT0_BIE
Rx_1__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Rx_1__BYP EQU CYREG_PRT0_BYP
Rx_1__CTL EQU CYREG_PRT0_CTL
Rx_1__DM0 EQU CYREG_PRT0_DM0
Rx_1__DM1 EQU CYREG_PRT0_DM1
Rx_1__DM2 EQU CYREG_PRT0_DM2
Rx_1__DR EQU CYREG_PRT0_DR
Rx_1__INP_DIS EQU CYREG_PRT0_INP_DIS
Rx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Rx_1__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Rx_1__LCD_EN EQU CYREG_PRT0_LCD_EN
Rx_1__MASK EQU 0x01
Rx_1__PORT EQU 0
Rx_1__PRT EQU CYREG_PRT0_PRT
Rx_1__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Rx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Rx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Rx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Rx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Rx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Rx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Rx_1__PS EQU CYREG_PRT0_PS
Rx_1__SHIFT EQU 0
Rx_1__SLW EQU CYREG_PRT0_SLW

; Tx_1
Tx_1__0__INTTYPE EQU CYREG_PICU0_INTTYPE1
Tx_1__0__MASK EQU 0x02
Tx_1__0__PC EQU CYREG_PRT0_PC1
Tx_1__0__PORT EQU 0
Tx_1__0__SHIFT EQU 1
Tx_1__AG EQU CYREG_PRT0_AG
Tx_1__AMUX EQU CYREG_PRT0_AMUX
Tx_1__BIE EQU CYREG_PRT0_BIE
Tx_1__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Tx_1__BYP EQU CYREG_PRT0_BYP
Tx_1__CTL EQU CYREG_PRT0_CTL
Tx_1__DM0 EQU CYREG_PRT0_DM0
Tx_1__DM1 EQU CYREG_PRT0_DM1
Tx_1__DM2 EQU CYREG_PRT0_DM2
Tx_1__DR EQU CYREG_PRT0_DR
Tx_1__INP_DIS EQU CYREG_PRT0_INP_DIS
Tx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Tx_1__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Tx_1__LCD_EN EQU CYREG_PRT0_LCD_EN
Tx_1__MASK EQU 0x02
Tx_1__PORT EQU 0
Tx_1__PRT EQU CYREG_PRT0_PRT
Tx_1__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Tx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Tx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Tx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Tx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Tx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Tx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Tx_1__PS EQU CYREG_PRT0_PS
Tx_1__SHIFT EQU 1
Tx_1__SLW EQU CYREG_PRT0_SLW

; UART_1
UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB05_06_ACTL
UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB05_06_CTL
UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB05_06_CTL
UART_1_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB05_06_CTL
UART_1_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB05_06_CTL
UART_1_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB05_06_MSK
UART_1_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB05_06_MSK
UART_1_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB05_06_MSK
UART_1_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB05_06_MSK
UART_1_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB05_ACTL
UART_1_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B0_UDB05_CTL
UART_1_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B0_UDB05_ST_CTL
UART_1_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B0_UDB05_CTL
UART_1_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B0_UDB05_ST_CTL
UART_1_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B0_UDB05_MSK
UART_1_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB05_06_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B0_UDB05_06_ST
UART_1_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B0_UDB05_MSK
UART_1_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB05_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B0_UDB05_ST_CTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B0_UDB05_ST_CTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B0_UDB05_ST
UART_1_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB05_06_A0
UART_1_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB05_06_A1
UART_1_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB05_06_D0
UART_1_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB05_06_D1
UART_1_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB05_06_ACTL
UART_1_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB05_06_F0
UART_1_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB05_06_F1
UART_1_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB05_A0_A1
UART_1_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B0_UDB05_A0
UART_1_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B0_UDB05_A1
UART_1_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB05_D0_D1
UART_1_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B0_UDB05_D0
UART_1_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B0_UDB05_D1
UART_1_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB05_ACTL
UART_1_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB05_F0_F1
UART_1_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B0_UDB05_F0
UART_1_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B0_UDB05_F1
UART_1_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
UART_1_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB05_MSK_ACTL
UART_1_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB02_03_ACTL
UART_1_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB02_03_ST
UART_1_BUART_sRX_RxSts__3__MASK EQU 0x08
UART_1_BUART_sRX_RxSts__3__POS EQU 3
UART_1_BUART_sRX_RxSts__4__MASK EQU 0x10
UART_1_BUART_sRX_RxSts__4__POS EQU 4
UART_1_BUART_sRX_RxSts__5__MASK EQU 0x20
UART_1_BUART_sRX_RxSts__5__POS EQU 5
UART_1_BUART_sRX_RxSts__MASK EQU 0x38
UART_1_BUART_sRX_RxSts__MASK_REG EQU CYREG_B0_UDB02_MSK
UART_1_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB02_ACTL
UART_1_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B0_UDB02_ST
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B0_UDB02_03_A0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B0_UDB02_03_A1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B0_UDB02_03_D0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B0_UDB02_03_D1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB02_03_ACTL
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B0_UDB02_03_F0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B0_UDB02_03_F1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B0_UDB02_A0_A1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B0_UDB02_A0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B0_UDB02_A1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B0_UDB02_D0_D1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B0_UDB02_D0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B0_UDB02_D1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B0_UDB02_ACTL
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B0_UDB02_F0_F1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B0_UDB02_F0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B0_UDB02_F1
UART_1_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB00_01_A0
UART_1_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB00_01_A1
UART_1_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB00_01_D0
UART_1_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB00_01_D1
UART_1_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB00_01_ACTL
UART_1_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB00_01_F0
UART_1_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB00_01_F1
UART_1_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB00_A0_A1
UART_1_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B0_UDB00_A0
UART_1_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B0_UDB00_A1
UART_1_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB00_D0_D1
UART_1_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B0_UDB00_D0
UART_1_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B0_UDB00_D1
UART_1_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB00_ACTL
UART_1_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB00_F0_F1
UART_1_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B0_UDB00_F0
UART_1_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B0_UDB00_F1
UART_1_BUART_sTX_TxSts__0__MASK EQU 0x01
UART_1_BUART_sTX_TxSts__0__POS EQU 0
UART_1_BUART_sTX_TxSts__1__MASK EQU 0x02
UART_1_BUART_sTX_TxSts__1__POS EQU 1
UART_1_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB00_01_ACTL
UART_1_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB00_01_ST
UART_1_BUART_sTX_TxSts__2__MASK EQU 0x04
UART_1_BUART_sTX_TxSts__2__POS EQU 2
UART_1_BUART_sTX_TxSts__3__MASK EQU 0x08
UART_1_BUART_sTX_TxSts__3__POS EQU 3
UART_1_BUART_sTX_TxSts__MASK EQU 0x0F
UART_1_BUART_sTX_TxSts__MASK_REG EQU CYREG_B0_UDB00_MSK
UART_1_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB00_ACTL
UART_1_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B0_UDB00_ST
UART_1_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
UART_1_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
UART_1_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
UART_1_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
UART_1_IntClock__INDEX EQU 0x00
UART_1_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
UART_1_IntClock__PM_ACT_MSK EQU 0x01
UART_1_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
UART_1_IntClock__PM_STBY_MSK EQU 0x01

; Timer_1
Timer_1_TimerUDB_rstSts_stsreg__0__MASK EQU 0x01
Timer_1_TimerUDB_rstSts_stsreg__0__POS EQU 0
Timer_1_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB03_04_ACTL
Timer_1_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB03_04_ST
Timer_1_TimerUDB_rstSts_stsreg__2__MASK EQU 0x04
Timer_1_TimerUDB_rstSts_stsreg__2__POS EQU 2
Timer_1_TimerUDB_rstSts_stsreg__3__MASK EQU 0x08
Timer_1_TimerUDB_rstSts_stsreg__3__POS EQU 3
Timer_1_TimerUDB_rstSts_stsreg__MASK EQU 0x0D
Timer_1_TimerUDB_rstSts_stsreg__MASK_REG EQU CYREG_B0_UDB03_MSK
Timer_1_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB03_ACTL
Timer_1_TimerUDB_rstSts_stsreg__STATUS_REG EQU CYREG_B0_UDB03_ST
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB01_02_ACTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB01_02_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB01_02_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB01_02_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB01_02_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB01_02_MSK
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB01_02_MSK
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB01_02_MSK
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB01_02_MSK
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK EQU 0x80
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS EQU 7
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB01_ACTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB01_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB01_ST_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG EQU CYREG_B0_UDB01_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB01_ST_CTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK EQU 0x80
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB01_MSK_ACTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB01_MSK_ACTL
Timer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB01_MSK
Timer_1_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB03_04_A0
Timer_1_TimerUDB_sT8_timerdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB03_04_A1
Timer_1_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB03_04_D0
Timer_1_TimerUDB_sT8_timerdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB03_04_D1
Timer_1_TimerUDB_sT8_timerdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB03_04_ACTL
Timer_1_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB03_04_F0
Timer_1_TimerUDB_sT8_timerdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB03_04_F1
Timer_1_TimerUDB_sT8_timerdp_u0__A0_A1_REG EQU CYREG_B0_UDB03_A0_A1
Timer_1_TimerUDB_sT8_timerdp_u0__A0_REG EQU CYREG_B0_UDB03_A0
Timer_1_TimerUDB_sT8_timerdp_u0__A1_REG EQU CYREG_B0_UDB03_A1
Timer_1_TimerUDB_sT8_timerdp_u0__D0_D1_REG EQU CYREG_B0_UDB03_D0_D1
Timer_1_TimerUDB_sT8_timerdp_u0__D0_REG EQU CYREG_B0_UDB03_D0
Timer_1_TimerUDB_sT8_timerdp_u0__D1_REG EQU CYREG_B0_UDB03_D1
Timer_1_TimerUDB_sT8_timerdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB03_ACTL
Timer_1_TimerUDB_sT8_timerdp_u0__F0_F1_REG EQU CYREG_B0_UDB03_F0_F1
Timer_1_TimerUDB_sT8_timerdp_u0__F0_REG EQU CYREG_B0_UDB03_F0
Timer_1_TimerUDB_sT8_timerdp_u0__F1_REG EQU CYREG_B0_UDB03_F1

; Clock_PWM
Clock_PWM__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
Clock_PWM__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
Clock_PWM__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
Clock_PWM__CFG2_SRC_SEL_MASK EQU 0x07
Clock_PWM__INDEX EQU 0x01
Clock_PWM__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_PWM__PM_ACT_MSK EQU 0x02
Clock_PWM__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_PWM__PM_STBY_MSK EQU 0x02

; isr_Timer
isr_Timer__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_Timer__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_Timer__INTC_MASK EQU 0x01
isr_Timer__INTC_NUMBER EQU 0
isr_Timer__INTC_PRIOR_NUM EQU 7
isr_Timer__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
isr_Timer__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_Timer__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; isr_uart_rx
isr_uart_rx__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_uart_rx__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_uart_rx__INTC_MASK EQU 0x02
isr_uart_rx__INTC_NUMBER EQU 1
isr_uart_rx__INTC_PRIOR_NUM EQU 7
isr_uart_rx__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
isr_uart_rx__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_uart_rx__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 18
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 18
CYDEV_CHIP_MEMBER_4D EQU 13
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 19
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 17
CYDEV_CHIP_MEMBER_4I EQU 23
CYDEV_CHIP_MEMBER_4J EQU 14
CYDEV_CHIP_MEMBER_4K EQU 15
CYDEV_CHIP_MEMBER_4L EQU 22
CYDEV_CHIP_MEMBER_4M EQU 21
CYDEV_CHIP_MEMBER_4N EQU 10
CYDEV_CHIP_MEMBER_4O EQU 7
CYDEV_CHIP_MEMBER_4P EQU 20
CYDEV_CHIP_MEMBER_4Q EQU 12
CYDEV_CHIP_MEMBER_4R EQU 8
CYDEV_CHIP_MEMBER_4S EQU 11
CYDEV_CHIP_MEMBER_4T EQU 9
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 16
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 24
CYDEV_CHIP_MEMBER_FM3 EQU 28
CYDEV_CHIP_MEMBER_FM4 EQU 29
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 26
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 27
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000003
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END