/*
    __methane_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__methane_driver.h"
#include "__methane_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __METHANE_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const float _METHANE_RLOAD                                        = 10.0;
const float _METHANE_RZERO                                        = 76.63;
const float _METHANE_PARA                                         = 116.6020682;
const float _METHANE_PARB                                         = 2.769034857;
const float _METHANE_CORA                                         = 0.00035;
const float _METHANE_CORB                                         = 0.02718;
const float _METHANE_CORC                                         = 1.39538;
const float _METHANE_CORD                                         = 0.0018;
const float _METHANE_ATMOCO2                                      = 397.13;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __METHANE_DRV_SPI__

void methane_spiDriverInit(T_METHANE_P gpioObj, T_METHANE_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __METHANE_DRV_I2C__

void methane_i2cDriverInit(T_METHANE_P gpioObj, T_METHANE_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __METHANE_DRV_UART__

void methane_uartDriverInit(T_METHANE_P gpioObj, T_METHANE_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void methane_gpioDriverInit(T_METHANE_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */



/* Get the correction factor function */
float methane_getCorrectionFactor( float temperature, float humidity )
{
    float result;

    result = _METHANE_CORA;
    result *= temperature * temperature;
    result -= _METHANE_CORB * temperature;
    result += _METHANE_CORC;
    result -= ( humidity - 33.0 ) * _METHANE_CORD;

    return result;
}

/* Get the resistance of the sensor function */
float methane_getResistance( uint32_t adcValue )
{
    float result;

    result = 1023.0;
    result /= ( float ) adcValue;
    result *= 5.0;
    result -= 1.0;
    result *= _METHANE_RLOAD;

    return result;
}

/* Get the corrected resistance of the sensor function */
float methane_getCorrectedResistance( float temperature, float humidity, uint32_t adcValue )
{
    float result;

    result = methane_getResistance( adcValue );
    result /= methane_getCorrectionFactor( temperature, humidity );

    return result;
}



/* -------------------------------------------------------------------------- */
/*
  __methane_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */