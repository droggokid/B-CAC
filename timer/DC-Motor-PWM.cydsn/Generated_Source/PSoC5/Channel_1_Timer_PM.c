/*******************************************************************************
* File Name: Channel_1_Timer_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Channel_1_Timer.h"

static Channel_1_Timer_backupStruct Channel_1_Timer_backup;


/*******************************************************************************
* Function Name: Channel_1_Timer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Channel_1_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Channel_1_Timer_SaveConfig(void) 
{
    #if (!Channel_1_Timer_UsingFixedFunction)
        Channel_1_Timer_backup.TimerUdb = Channel_1_Timer_ReadCounter();
        Channel_1_Timer_backup.InterruptMaskValue = Channel_1_Timer_STATUS_MASK;
        #if (Channel_1_Timer_UsingHWCaptureCounter)
            Channel_1_Timer_backup.TimerCaptureCounter = Channel_1_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Channel_1_Timer_UDB_CONTROL_REG_REMOVED)
            Channel_1_Timer_backup.TimerControlRegister = Channel_1_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Channel_1_Timer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Channel_1_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Channel_1_Timer_RestoreConfig(void) 
{   
    #if (!Channel_1_Timer_UsingFixedFunction)

        Channel_1_Timer_WriteCounter(Channel_1_Timer_backup.TimerUdb);
        Channel_1_Timer_STATUS_MASK =Channel_1_Timer_backup.InterruptMaskValue;
        #if (Channel_1_Timer_UsingHWCaptureCounter)
            Channel_1_Timer_SetCaptureCount(Channel_1_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Channel_1_Timer_UDB_CONTROL_REG_REMOVED)
            Channel_1_Timer_WriteControlRegister(Channel_1_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Channel_1_Timer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Channel_1_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Channel_1_Timer_Sleep(void) 
{
    #if(!Channel_1_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Channel_1_Timer_CTRL_ENABLE == (Channel_1_Timer_CONTROL & Channel_1_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Channel_1_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Channel_1_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Channel_1_Timer_Stop();
    Channel_1_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Channel_1_Timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Channel_1_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Channel_1_Timer_Wakeup(void) 
{
    Channel_1_Timer_RestoreConfig();
    #if(!Channel_1_Timer_UDB_CONTROL_REG_REMOVED)
        if(Channel_1_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Channel_1_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
