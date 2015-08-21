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
#include <iostream>
#include <iomanip>
#include <step.h>
#include <wash_prog.h>
#include <gpio.h>
#include <motor.h>
#include <seven_segment.h>
using std::ios;
using std::setw;


// TODO: insert other definitions and declarations here
void wait()
{
  for(volatile int i = 0; i < 1000000; ++i);
}

int main() {

	GPIO 			port2(LPC_GPIO2_BASE);
	Motor 			motor(port2);
	SevenSegment 	sev_seg(port2);

//	motor.on();
//	while(1) {
//		for (int i=0; i<10; ++i) {
//			sev_seg.display(i);
//			wait();
//			wait();
//		}
//		motor.change_direction();
//	}

	WashProgramme color_wash;

//	Step s_empty(Step::empty, &sev_seg);
//	Step s_fill (Step::fill, &sev_seg);
//	Step s_heat (Step::heat, &sev_seg);
//	Step s_wash (Step::wash, &sev_seg);
//	Step s_rinse(Step::rinse, &sev_seg);
//	Step s_spin (Step::spin, &sev_seg);
//	Step s_dry  (Step::dry, &sev_seg);
//	Step s_comp (Step::complete, &sev_seg);

	Step empty(Step::e_empty,"empty");
	Step fill(Step::e_fill,"fill");
	Step heat(Step::e_heat,"heat");
	Step wash(Step::e_wash,"wash");
	Step rinse(Step::e_rinse,"rinse");
	Step spin(Step::e_spin,"spin");
	Step dry(Step::e_dry,"dry");
	Step comp(Step::e_complete,"complete");

	bind(empty, sev_seg);
	bind(fill, sev_seg);
	bind(heat, sev_seg);
	bind(wash, sev_seg);
	bind(rinse, sev_seg);
	bind(spin, sev_seg);
	bind(dry, sev_seg);
	bind(comp, sev_seg);

	color_wash.add(empty);
	color_wash.add(fill);
	color_wash.add(heat);
	color_wash.add(wash);
	color_wash.add(empty);
	color_wash.add(fill);
	color_wash.add(rinse);
	color_wash.add(empty);
	color_wash.add(spin);
	color_wash.add(dry);
	color_wash.add(comp);

	color_wash.run();
}
