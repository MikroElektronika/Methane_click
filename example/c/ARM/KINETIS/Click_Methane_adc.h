#include "Click_Methane_types.h"


void methane_adcInit()
{
    ADC0_Init();
    ADC0_Set_Input_Channel( _ADC_CHANNEL_12 );
}

uint32_t methane_readADC()
{
    uint32_t readADC;
    
    readADC = ADC0_Read( 12 );
    
    return readADC;
}