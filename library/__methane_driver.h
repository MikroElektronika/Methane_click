/*
    __methane_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __methane_driver.h
@brief    Methane Driver
@mainpage Methane Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   METHANE
@brief      Methane Click Driver
@{

| Global Library Prefix | **METHANE** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2019.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _METHANE_H_
#define _METHANE_H_

/** 
 * @macro T_METHANE_P
 * @brief Driver Abstract type 
 */
#define T_METHANE_P    const uint8_t*

/** @defgroup METHANE_COMPILE Compilation Config */              /** @{ */

//  #define   __METHANE_DRV_SPI__                            /**<     @macro __METHANE_DRV_SPI__  @brief SPI driver selector */
//  #define   __METHANE_DRV_I2C__                            /**<     @macro __METHANE_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __METHANE_DRV_UART__                           /**<     @macro __METHANE_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup METHANE_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup METHANE_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup METHANE_INIT Driver Initialization */              /** @{ */

#ifdef   __METHANE_DRV_SPI__
void methane_spiDriverInit(T_METHANE_P gpioObj, T_METHANE_P spiObj);
#endif
#ifdef   __METHANE_DRV_I2C__
void methane_i2cDriverInit(T_METHANE_P gpioObj, T_METHANE_P i2cObj, uint8_t slave);
#endif
#ifdef   __METHANE_DRV_UART__
void methane_uartDriverInit(T_METHANE_P gpioObj, T_METHANE_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void methane_gpioDriverInit(T_METHANE_P gpioObj);
                                                                       /** @} */
/** @defgroup METHANE_FUNC Driver Functions */                   /** @{ */



/**
 * @brief Get the correction factor function
 *
 * @param[in] temperature                    float value of the ambient air temperature
 *
 * @param[in] humidity                       float value of the relative humidity
 *
 * @return
 * float value of the calculated correction factor
 *
 * Function get the correction factor to correct for temperature and humidity.
*/
float methane_getCorrectionFactor( float temperature, float humidity );

/**
 * @brief Get the resistance of the sensor function
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @return
 * float value of the sensor resistance in kOhm
 *
 * Function get the resistance of the sensor, ie. measurement adc value
 * of MQ-4 sensor on Methane click board.
*/
float methane_getResistance( uint32_t adcValue );

/**
 * @brief Get the corrected resistance of the sensor function
 *
 * @param[in] temperature                    float value of the ambient air temperature
 *
 * @param[in] humidity                       float value of the relative humidity
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @return
 * float value of the corrected sensor resistance kOhm
 *
 * Function get the corrected resistance of the sensor, ie. measurement adc value
 * of MQ-4 sensor on Methane click board.
*/
float methane_getCorrectedResistance( float temperature, float humidity, uint32_t adcValue );



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Methane_STM.c
    @example Click_Methane_TIVA.c
    @example Click_Methane_CEC.c
    @example Click_Methane_KINETIS.c
    @example Click_Methane_MSP.c
    @example Click_Methane_PIC.c
    @example Click_Methane_PIC32.c
    @example Click_Methane_DSPIC.c
    @example Click_Methane_AVR.c
    @example Click_Methane_FT90x.c
    @example Click_Methane_STM.mbas
    @example Click_Methane_TIVA.mbas
    @example Click_Methane_CEC.mbas
    @example Click_Methane_KINETIS.mbas
    @example Click_Methane_MSP.mbas
    @example Click_Methane_PIC.mbas
    @example Click_Methane_PIC32.mbas
    @example Click_Methane_DSPIC.mbas
    @example Click_Methane_AVR.mbas
    @example Click_Methane_FT90x.mbas
    @example Click_Methane_STM.mpas
    @example Click_Methane_TIVA.mpas
    @example Click_Methane_CEC.mpas
    @example Click_Methane_KINETIS.mpas
    @example Click_Methane_MSP.mpas
    @example Click_Methane_PIC.mpas
    @example Click_Methane_PIC32.mpas
    @example Click_Methane_DSPIC.mpas
    @example Click_Methane_AVR.mpas
    @example Click_Methane_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __methane_driver.h

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