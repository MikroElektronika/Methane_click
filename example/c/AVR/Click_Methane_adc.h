#include "Click_Methane_types.h"


void methane_adcInit()
{
    ADC_Init();
}

uint32_t methane_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 7 );
    
    return readADC;
}