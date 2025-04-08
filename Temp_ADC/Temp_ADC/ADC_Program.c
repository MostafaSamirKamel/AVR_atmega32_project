
/* Include Header Files From LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include Header Files From MCAL */
#include "DIO_Interface.h"
/* Include My own Header Files*/
#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"



u16 ADC_u16Result = 0 ;
u8 ADC_u18BusyFlag = 0 ;

/************************************************************************************************/
/* Function Name : ADC_voidInit                                                                 */
/* Description : Initilization of ADC with Specific Specs accordig to Gonfigration File.h       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void ADC_voidInit (void)
{
/*======================================*/
/*       Select Reference Voltage       */ 
/*--------------------------------------*/
    #if ( REFERENCE_VOLTAGE == AREF )
        CLEAR_BIT(ADMUX_REG,6);
        CLEAR_BIT(ADMUX_REG,7);
    #elif ( REFERENCE_VOLTAGE == AVCC )
        SET_BIT(ADMUX_REG,6);
        CLEAR_BIT(ADMUX_REG,7);
    #elif ( REFERENCE_VOLTAGE == INTERNAL )
        SET_BIT(ADMUX_REG,6);
        SET_BIT(ADMUX_REG,7);
    #else
        CLEAR_BIT(ADMUX_REG,6);
        SET_BIT(ADMUX_REG,7);  
    #endif
	
/*======================================*/
/*     Select ADC  channel & mode   */
/*--------------------------------------*/
		// ACD0 - ADC1
CLEAR_BIT(ADMUX_REG,0);
CLEAR_BIT(ADMUX_REG,1);
CLEAR_BIT(ADMUX_REG,2);
CLEAR_BIT(ADMUX_REG,3);
SET_BIT(ADMUX_REG,4);

	
/*======================================*/
/*     Select RIGHT or LEFT Adjust      */
/*--------------------------------------*/
    #if ( ADJUST == RIGHT )
        CLEAR_BIT(ADMUX_REG,5);
    #elif ( ADJUST == LEFT )
        SET_BIT(ADMUX_REG,5);
    #endif
/*======================================*/
/*        ADC Enable or Disable         */
/*--------------------------------------*/
    #if ( ADEN == ENABLE )
        SET_BIT(ADCSRA_REG,7);  
    #elif ( ADEN == DISABLE )
        CLEAR_BIT(ADCSRA_REG,7); 
    #endif
/*======================================*/
/*    AUTO Trigger Enable or Disable    */
/*--------------------------------------*/
    #if ( ADATE == ENABLE )
        SET_BIT(ADCSRA_REG,5);
            /*======================================*/ 
            /*       ADC Auto Trigger Source        */
            /*--------------------------------------*/
        #if( AUTO_TRIGGER_SOURCE == Free_Running_Mode )
            CLEAR_BIT(SFIOR_REG,5);
            CLEAR_BIT(SFIOR_REG,6);
            CLEAR_BIT(SFIOR_REG,7);
        #elif ( AUTO_TRIGGER_SOURCE == Analog_Comparator )
              SET_BIT(SFIOR_REG,5);
            CLEAR_BIT(SFIOR_REG,6);
            CLEAR_BIT(SFIOR_REG,7);    
        #elif ( AUTO_TRIGGER_SOURCE == External_Interrupt_Request_0 )
            CLEAR_BIT(SFIOR_REG,5);
              SET_BIT(SFIOR_REG,6);
            CLEAR_BIT(SFIOR_REG,7);
        #elif ( AUTO_TRIGGER_SOURCE == Timer_Counter0_Compare_Match )
              SET_BIT(SFIOR_REG,5);
              SET_BIT(SFIOR_REG,6);
            CLEAR_BIT(SFIOR_REG,7);
        #elif ( AUTO_TRIGGER_SOURCE == Timer_Counter0_Overflow )
            CLEAR_BIT(SFIOR_REG,5);
            CLEAR_BIT(SFIOR_REG,6);
              SET_BIT(SFIOR_REG,7);
        #elif ( AUTO_TRIGGER_SOURCE == Timer_Counter1_Compare_MatchB )
              SET_BIT(SFIOR_REG,5);
            CLEAR_BIT(SFIOR_REG,6);
              SET_BIT(SFIOR_REG,7);
        #elif ( AUTO_TRIGGER_SOURCE == Timer_Counter1_Overflow )
            CLEAR_BIT(SFIOR_REG,5);
              SET_BIT(SFIOR_REG,6);
              SET_BIT(SFIOR_REG,7);
        #elif ( AUTO_TRIGGER_SOURCE == Timer_Counter1_Capture_Event )
              SET_BIT(SFIOR_REG,5);
              SET_BIT(SFIOR_REG,6);
              SET_BIT(SFIOR_REG,7);
        #endif

    #elif ( ADATE == DISABLE )
        CLEAR_BIT(ADCSRA_REG,5); 
    #endif
/*======================================*/
/*    ADC Interrupt Enable or Disable   */
/*--------------------------------------*/
    #if ( ADIE == ENABLE )          // work with Interrupt
        SET_BIT(ADCSRA_REG,3);  
    #elif ( ADIE == DISABLE )       // work with Polling
        CLEAR_BIT(ADCSRA_REG,3); 
    #endif
/*======================================*/
/*       ADC Prescaler Selection        */
/*--------------------------------------*/
    /*     Clear Prescaler      */ 
    ADCSRA_REG = ( ADCSRA_REG & 0b11111000 );

    #if( PRESCALER == NOT_USE_PRESCALER )
        // NOTHING
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_2 )
          SET_BIT(ADCSRA_REG,0);
        CLEAR_BIT(ADCSRA_REG,1);
        CLEAR_BIT(ADCSRA_REG,2);    
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_4 )
        CLEAR_BIT(ADCSRA_REG,0);
          SET_BIT(ADCSRA_REG,1);
        CLEAR_BIT(ADCSRA_REG,2);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_8 )
          SET_BIT(ADCSRA_REG,0);
          SET_BIT(ADCSRA_REG,1);
        CLEAR_BIT(ADCSRA_REG,2);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_16 )
        CLEAR_BIT(ADCSRA_REG,0);
        CLEAR_BIT(ADCSRA_REG,1);
          SET_BIT(ADCSRA_REG,2);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_32 )
          SET_BIT(ADCSRA_REG,0);
        CLEAR_BIT(ADCSRA_REG,1);
          SET_BIT(ADCSRA_REG,2);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_64 )
        CLEAR_BIT(ADCSRA_REG,0);
          SET_BIT(ADCSRA_REG,1);
          SET_BIT(ADCSRA_REG,2);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_128 )
          SET_BIT(ADCSRA_REG,0);
          SET_BIT(ADCSRA_REG,1);
          SET_BIT(ADCSRA_REG,2);
    #endif
/*======================================*/
}

/************************************************************************************************/
/* Function Name : ADC_u16Read                                                        */
/* Description : Get Analog Reading From ADC                                                    */
/* Fun. Argument1: Copy_u8ChannelNumber { ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7 }             */
/* Fun. Return : u16                                                                            */
/************************************************************************************************/
u16 ADC_u16Read () 
{
    /*    Start Conversion    */ 
    #if ( ADATE == ENABLE )
        // Start Conversion When auto Triggering Occures.
    #elif ( ADATE == DISABLE )
        SET_BIT(ADCSRA_REG,6);  // Normal Start Conversion
    #endif
/*===============================================================================================*/    
    #if ( ADIE == ENABLE )                        // work with Interrupt
        // When ADC Finish conversion will Raising Interrupt Flag and Jump to ADC_ISR Function.    
    #elif ( ADIE == DISABLE )                     // work with Polling
        /* GET FLAG and Polling the Flag */
        u8 ADI_F = 0 ;
        while( ADI_F == 0 )
        {
            ADI_F = GET_BIT(ADCSRA_REG,4);    // Stuck on while untill Flag Raising 1 .
        }
    #endif
/*===============================================================================================*/
    #if ( ADIE == ENABLE )          // work with Interrupt
        // Interrupt Flag Will Cleared Automaticlly.    
    #elif ( ADIE == DISABLE )       // work with Polling
        /* Clear Flag */
        SET_BIT(ADCSRA_REG,4);
    #endif 
/*==========================================================================================================================*/
/*********************************************************     Get Reading      *********************************************/
/*        Get Reading from 16 Bit ADC_REG  if we used RIGHT Adjust and Resoluotion 10 BIT  Return Value From { 0 -> 1023 }  */
/*        Get Reading from 8 Bit ADCH_REG  if we used LEFT Adjust and Resoluotion  8 BIT   Return Value From { 0 -> 255  }  */
/*--------------------------------------------------------------------------------------------------------------------------*/
    #if ( ADJUST == RIGHT )
        return ADC_REG ;      
    #elif ( ADJUST == LEFT )
        return ADCH_REG ;
    #endif
/*===============================================================================================*/

}


/*********************************     This Equation Used in App      ****************************/
        //  Analog_Signal =   Digital_Signal *  Step Size
        //  Analog_Signal = ( Digital_Signal * V max )  / 2^Rsolution   // Rsolution =10 BIT & Vmax = 2.5v = 2500 mv 
        //  Analog_Signal = ( Digital_Signal * 2500UL ) / 1024  
/*===============================================================================================*/
void ADC_getTemperature ( Temperature * Outdata )
{
    Outdata->digitalValue = ADC_u16Read();
    Outdata->analogValue  = (Outdata->digitalValue * 2500UL) / 1024;
    Outdata->tempValue    =  Outdata->analogValue / 10 ;
}
