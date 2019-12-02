/*
 * myPWM.c
 *
 *  Created on: Dec 2, 2019
 *      Author: JacobFaseler
 */

/* Include Self */
#include "SourceCode/myPWM.h"
#include <ti/drivers/PWM.h>

/* Construct PWM Instance */

/* Period and duty in microseconds */
uint16_t   pwmPeriod = 3000;
uint16_t   duty = 0;
uint16_t   dutyInc = 100;
/* Sleep time in microseconds */
uint32_t   time = 50000;

/* Call driver init functions. */
void InitializePWM(void)
{
    PWM_init();
    PWM_Params_init(&pwm_params);
    pwm_params.idleLevel = PWM_IDLE_LOW;
    pwm_params.periodUnits = PWM_PERIOD_HZ;
    pwm_params.periodValue = 100;
    pwm_params.dutyUnits = PWM_DUTY_FRACTION;
    pwm_params.dutyValue = PWM_DUTY_FRACTION_MAX / 2;

    pwm = PWM_open(CONFIG_PWM_0, &pwm_params);
    if (pwm == NULL)
    {
        /* CONFIG_PWM_0 did not open */
        System_printf("PWM Fail");
    }
    PWM_start(pwm);
}

void ChangeDuty(PWM_Handle pwm, uint16_t percent)
{
    uint32_t duty;

    duty = (uint32_t) (((uint64_t) PWM_DUTY_FRACTION_MAX * percent) / 1000);
    PWM_setDuty(pwm, duty);
}
#ifdef foo

#endif
