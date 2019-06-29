/*
 * DIYReflowOvenV1.c
 *
 * Created: 2016-12-13 22:13:06
 * Author : Branden
 */ 
/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
//#define __AVR_ATxmega128A4U__



#include <asf.h>
#include <avr/io.h>
#include <stdio.h>


void uart_putchar(uint8_t c, FILE * stream);
volatile FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);



void uart_putchar(uint8_t c, FILE * stream)
{
	udi_cdc_putc(c);
}

bool my_callback_cdc_enable(void)
{
	return true;
}

void my_callback_cdc_disable(void)
{

}

void my_callback_rx_notify(uint8_t port)
{
	//echo test
	udi_cdc_putc(udi_cdc_getc());
	
}

void my_callback_tx_empty_notify(uint8_t port)
{
	
}


int main(void)
{


	cli();

	sysclk_init();
	udc_start();

	
	stdout = &mystdout;
	
	irq_initialize_vectors();


	sei();
	
	
	
	
	while(1){ }
	

}
