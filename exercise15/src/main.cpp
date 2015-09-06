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

//#define SEVEN_SEGMENT

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
#include <idisplay.h>
#include <seven_segment.h>
#include <UART.h>
#include <circ_buf.h>
#include <debug_log.h>
using std::cout;
using std::endl;
using std::ios;
using std::setw;


// TODO: insert other definitions and declarations here
void wait()
{
  for(volatile int i = 0; i < 1000000; ++i);
}

int main() {
	CircularBuffer 	buf(10);
	CircularBuffer::buf_status_t st;

	// add 11 items to a buffer of size 10
	for(int i=0; i<11; ++i) {
		st = buf.add(i);
		if(st == CircularBuffer::e_buf_ok) {
			dout << "OK" << endl;
		} else {
			dout << "Buffer full" << endl;
		}
	}

	// read 11 items from a buffer of size 10
	for(int i=0; i<11; ++i) {
		uint32_t data;
		st = buf.get(data);
		if(st == CircularBuffer::e_buf_ok) {
			dout << "OK - ";
			dout << "Data is: " << data << endl;
		} else {
			dout << "Buffer empty - ";
			dout << "Data is: " << data << endl;
		}
	}

/*	GPIO 			port2(LPC_GPIO2_BASE);
	Motor 			motor(port2);
#ifdef SEVEN_SEGMENT
	I_DisplayNumeric * p_idisp = new SevenSegment(port2);
#else
	I_DisplayNumeric * p_idisp = new UART(LPC_UART3_BASE);
#endif
	//UART			uart(LPC_UART3_BASE);
	WashProgramme 	color_wash;

	Step			empty(Step::e_empty, p_idisp, "empty");
	Step 			fill(Step::e_fill, p_idisp, "fill");
	Step 			heat(Step::e_heat,	p_idisp, "heat");
	WashStep 		wash(Step::e_wash, p_idisp, "wash", &motor);
	RinseStep 		rinse(Step::e_rinse, p_idisp, "rinse", &motor);
	SpinStep 		spin(Step::e_spin, p_idisp, "spin", &motor);
	Step 			dry(Step::e_dry, p_idisp, "dry");
	Step 			comp(Step::e_complete,	p_idisp, "complete");

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

	delete p_idisp;*/
}
