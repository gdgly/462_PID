/*
 * myPWM.h
 *
 *  Created on: Dec 2, 2019
 *      Author: JacobFaseler
 */

#ifndef SOURCECODE_MYPWM_H_
#define SOURCECODE_MYPWM_H_

#include <Debug/syscfg/ti_drivers_config.h>
#include <ti/drivers/PWM.h>
#include <xdc/runtime/System.h>

/* HW Resource Abstractions */
PWM_Handle pwm;
PWM_Params pwm_params;
uint32_t duty_value;

/* Fn Protos */
void InitializePWM(void);
void ChangeDuty(PWM_Handle pwm, uint16_t percent);

#endif /* SOURCECODE_MYPWM_H_ */
