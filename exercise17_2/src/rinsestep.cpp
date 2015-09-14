#include <debug_log.h>
#include <motor.h>
#include <iostream>
#include <rinsestep.h>

class SevenSegment;

using std::cout;
using std::endl;

static void wait() {
  for(volatile int i = 0; i < 10000000; ++i);
}

RinseStep::RinseStep(wm_step_t step_num)
	:	MotorStep(step_num) {
}

RinseStep::RinseStep(wm_step_t step_num,
		I_DisplayNumeric * p_idisp)
	:	MotorStep(step_num, p_idisp) {
}

RinseStep::RinseStep(wm_step_t step_num, char * p_desc)
	:	MotorStep(step_num, p_desc) {
}

RinseStep::RinseStep(wm_step_t step_num,
		I_DisplayNumeric * p_idisp,
		char * p_desc, Motor * p_motor)
	:	MotorStep(step_num, p_idisp, p_desc, p_motor) {
}

void RinseStep::run() const {
	Step::run();
	m_p_motor->on();
	wait();
	wait();
	m_p_motor->off();
}


