/* Texas A&M University
** Electronic Systems Engineering Technology
** ESET-462 Control Systems ** Author: Jacob Faseler
** File: ADC.c
** --------
** Interactions with the ADC block
*/

/* XDC module Headers */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS module Headers */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>

#include <ti/drivers/Board.h>

/* SourceCode Inclusions */
#include "SourceCode/myADC.h"
#include "SourceCode/Imports/PID_GeekFactory/PID.h"
#include "SourceCode/myPWM.h"

/* PID Resources */
struct pid_controller ctrldata;
pid_t pid;

/* Debug Globals -- Optimize out */
uint_fast16_t adc_value;
uint32_t adc_value_uv;
float adc_value_v;
IArg main_key;
uint8_t i;

/*
 *  =======MAIN==========
 */
int main()
{
    /* Initialize Board */
    InitializeADCs();

    /* Initialize Primitives */
    ConstructADCmutex();

    /* Try ADC */
    readADC(adc, &adc_value);

    /* Try Conversion */
    adc_value_uv = ADC_convertToMicroVolts(adc, adc_value);
    System_printf("\r\n Which in uV is: %d",adc_value_uv);
    System_flush();

    /* Try FPU */

    /* Thread Safe Access */
    main_key = GateMutex_enter(adc_mutex);

        adc_value_v = ((float)adc_value_uv) / 1000000;
        System_printf("\r\n And in Volts that's: %f", adc_value_v);
        System_flush();

    /* Allow other threads access */
    GateMutex_leave(adc_mutex,main_key);

    /* Test PWM */
    InitializePWM();

    /* Set DC higher */
    ChangeDuty(pwm, 80);
    main_key=main_key;

//#define PID_LIB
    /* Instantiate PID */
    float input = 0, output = 0, setpoint = 1;
    float kp = 1.1, ki = 0;
    float error = 0, integral[10]={0,0,0,0,0,0,0,0,0,0};
    float prop_change = 0;
    float average;
#ifdef PID_LIB
    pid = pid_create(&ctrldata,&input,&output,&setpoint,kp,ki,kd);
    pid_limits(pid,0,1000);
    // Allow PID to compute and change output
    pid_auto(pid);
#endif


    /* PID Loop */
    for (;;)
    {
        // Read process feedback
        for (i = 0 ; i < 15 ; i++)
        {
            readADC(adc, &adc_value);
            adc_value_uv = ADC_convertToMicroVolts(adc, adc_value);
            adc_value_v = ((float)adc_value_uv) / 1000000;
            average += adc_value_v;
        }
        average = average / 15;
        // Compute new PID output value
        error = setpoint - input;
        prop_change = kp * error * 10;
        output += prop_change;
        //Change actuator value
        ChangeDuty(pwm, (uint16_t)output);
        System_printf("\r\n input is: %f", input);
        System_printf("\r\n output is: %f", output);
        System_flush();
    }
}
