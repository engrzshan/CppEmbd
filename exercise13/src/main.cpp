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
#include <washstep.h>
#include <rinsestep.h>
#include <spinstep.h>
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
	WashProgramme 	color_wash;

	Step			empty(Step::e_empty, &sev_seg, "empty");
	Step 			fill(Step::e_fill, &sev_seg, "fill");
	Step 			heat(Step::e_heat,	&sev_seg, "heat");
	WashStep 		wash(Step::e_wash, &sev_seg, "wash", &motor);
	RinseStep 		rinse(Step::e_rinse, &sev_seg, "rinse", &motor);
	SpinStep 		spin(Step::e_spin, &sev_seg, "spin", &motor);
	Step 			dry(Step::e_dry, &sev_seg, "dry");
	Step 			comp(Step::e_complete,	&sev_seg, "complete");

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
