

/* File Gaurd by ifndef & endif */
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/*     Macros of Channel Number    */
#define     ADC0                    0
#define     ADC1                    1
#define     ADC2                    2
#define     ADC3                    3
#define     ADC4                    4
#define     ADC5                    5
#define     ADC6                    6
#define     ADC7                    7


typedef struct temp_ADC {
    u16 digitalValue;
    u16 analogValue;
    u16 tempValue;
}Temperature;



/************************************************************************************************/
/* Function Name : ADC_voidInit                                                                 */
/* Description : Initilization of ADC with Specific Specs accordig to Gonfigration File.h       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void ADC_voidInit (void);
/************************************************************************************************/
/* Function Name : ADC_u16ReadSynchronus                                                        */
/* Description : Get Analog Reading From ADC                                                    */
/* Fun. Argument1: Copy_u8ChannelNumber { ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7 }             */
/* Fun. Return : u16                                                                            */
/************************************************************************************************/
u16 ADC_u16Read () ;


void ADC_getTemperature (Temperature * Outdata );

#endif