#include "Click_Methane_types.h"


void methane_adcInit()
{
    ADC1_Init_Advanced(_ADC_12bit, _ADC_INTERNAL_VREFL | _ADC_INTERNAL_VREFH );
}

uint32_t methane_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 8 );
    
    return readADC;
}