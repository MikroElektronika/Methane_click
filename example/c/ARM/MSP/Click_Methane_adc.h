#include "Click_Methane_types.h"


void methane_adcInit()
{
    ADC_Init();
    ADC_Set_Input_Channel( _ADC_CHANNEL_15 );
}

uint32_t methane_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 15 );
    
    return readADC;
}