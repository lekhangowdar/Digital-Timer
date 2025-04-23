/*
 * File:   main.c
 * Author: Lekhan Gowda R
 * ROLLNO: 24008_023
 * Description: LED brightness control using potentiometer
 * Created on September 12, 2024, 3:34 PM
 */

#include "main.h"
#include "adc.h"
#include <xc.h>
#include "timer0.h"
#include "isr.h"

unsigned short duty_cycle; //to store value of duty cycle

static void init_config(void)
{
	LED1 = OFF;

    init_adc();
    
    PEIE = 1;
	/* Clear old content */
	PORTB = 0x00;

	/* Set PORTB as a Output */
	TRISB = 0x00;

	/* Config PORTB as digital */
	ADCON1 = 0x0F;

	init_timer0(); //to initialize timer

	GIE = 1;
}

void main(void)
{
    //variable to read value from channel 4
    unsigned short adc_reg_val;

    init_config();
    
    //run a super loop
    while (1)
    {
        adc_reg_val = read_adc(CHANNEL4);  //read the value from channel 4
        //convert the adc value read into duty cycle so the value range is 0-100
        duty_cycle = (float)(adc_reg_val/10.23);  
    }
}













