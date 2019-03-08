#include "Click_Methane_types.h"


void methane_adcInit()
{
    ADC1_Init();
}

uint32_t methane_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 8 );
    
    return readADC;
}