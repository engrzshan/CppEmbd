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

// TODO: insert other definitions and declarations here

int main() {
	WashProgramme wash_prog;

	Step s_empty(Step::empty);
	Step s_fill(Step::fill);
	Step s_heat(Step::heat);
	Step s_wash(Step::wash);
	Step s_rinse(Step::rinse);
	Step s_spin(Step::spin);
	Step s_dry(Step::dry);
	Step s_comp(Step::complete);

	wash_prog.add(s_empty);
	wash_prog.add(s_fill);
	wash_prog.add(s_heat);
	wash_prog.add(s_wash);
	wash_prog.add(s_rinse);
	wash_prog.add(s_spin);
	wash_prog.add(s_dry);
	wash_prog.add(s_comp);

	wash_prog.run();
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
