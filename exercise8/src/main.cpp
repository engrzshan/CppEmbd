/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include <step.h>
#include <wash_prog.h>
#include <gpio.h>

// TODO: insert other definitions and declarations here
void wait()
{
  for(volatile int i = 0; i < 500000; ++i);
}

int main() {

	GPIO port2(LPC_GPIO2_BASE);
	port2.set_as_output(GPIO::pin0);
	port2.set_as_output(GPIO::pin1);
	port2.set_as_output(GPIO::pin2);
	port2.set_as_output(GPIO::pin3);
	port2.set_as_output(GPIO::pin4);
	port2.set_as_output(GPIO::pin5);

	port2.clear(GPIO::pin0);
	port2.clear(GPIO::pin1);
	port2.clear(GPIO::pin2);
	port2.clear(GPIO::pin3);
	port2.clear(GPIO::pin4);
	port2.clear(GPIO::pin5);

	while(true) {
		port2.set(GPIO::pin0);
		wait();
		wait();
		port2.clear(GPIO::pin0);
		wait();
		wait();
	}
}
/*int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}*/
