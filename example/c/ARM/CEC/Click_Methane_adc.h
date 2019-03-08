#include "Click_Methane_types.h"


void methane_adcInit()
{
    ADC1_Init();
    ADC1_Set_Input_Channel( 0x01 );
}

uint32_t methane_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 1 );
    
    return readADC;
}