/* Texas A&M University
** Electronic Systems Engineering Technology
** ESET-420 Capstone II ** Author: Jacob Faseler
** File: ADC.h
** --------
** Interactions with the ADC block
*/
#ifndef SOURCECODE_MYADC_H_
#define SOURCECODE_MYADC_H_

/* Bare-Metal Info */
#define ADC12_A_BASE_ADDR (uint16_t)0x0700

/* TI Kernel-Aware Drivers don't support ADC, so driverlib */
#include <ti/drivers/ADC.h>

/* TI Runtime library */
#include <xdc/runtime/System.h>
#include <ti/sysbios/knl/Task.h>
#include <Debug/syscfg/ti_drivers_config.h>

/* TI Gate Mutex */
#include <ti/sysbios/gates/GateMutex.h>

/* std types */
#include <stdint.h>
#include <stdbool.h>

    /* Global Resources */

/* ADC Mutex Resources */
GateMutex_Struct adc_mut_struct;
GateMutex_Params adc_mut_params;
GateMutex_Handle adc_mutex;

/* ADC Config Resources */
ADC_Handle adc;
ADC_Params adc_parms;
int_fast16_t adc_reading;

/* Function Prototypes */
void ConstructADCmutex(void);
void InitializeADCs (void);
uint16_t readADC(ADC_Handle adc, uint_fast16_t *value_out);

#ifdef OLD_ADC
void InitializeADCs (uint16_t base_address);
#endif

#endif /* SOURCECODE_MYADC_H_ */
