#include "Click_Methane_types.h"


void methane_adcInit()
{
    ADC_Init();
}

uint32_t methane_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Get_Sample( 0 );
    
    return readADC;
}