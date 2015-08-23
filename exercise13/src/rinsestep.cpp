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
		SevenSegment * p_sev_seg)
	:	MotorStep(step_num, p_sev_seg) {
}

RinseStep::RinseStep(wm_step_t step_num, char * p_desc)
	:	MotorStep(step_num, p_desc) {
}

RinseStep::RinseStep(wm_step_t step_num,
		SevenSegment * p_sev_seg,
		char * p_desc, Motor * p_motor)
	:	MotorStep(step_num, p_sev_seg, p_desc, p_motor) {
}

void RinseStep::run() const {
	Step::run();
	m_p_motor->on();
	wait();
	wait();
	m_p_motor->off();
}





