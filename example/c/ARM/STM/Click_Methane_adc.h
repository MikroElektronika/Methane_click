#include "Click_Methane_types.h"


void methane_adcInit()
{
    ADC1_Init();
    ADC_Set_Input_Channel( _ADC_CHANNEL_4 );
}

uint32_t methane_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 4 );
    
    return readADC;
}