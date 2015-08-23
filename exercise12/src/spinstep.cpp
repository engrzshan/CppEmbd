#include <debug_log.h>
#include <motor.h>
#include <iostream>
#include <seven_segment.h>
#include <spinstep.h>

using std::cout;
using std::endl;

static void wait() {
  for(volatile int i = 0; i < 10000000; ++i);
}

SpinStep::SpinStep(wm_step_t step_num)
	:	Step(step_num)
	,	m_p_motor(NULL) {
}

SpinStep::SpinStep(wm_step_t step_num, SevenSegment * p_sev_seg)
	:	Step(step_num, p_sev_seg)
	,	m_p_motor(NULL) {
}

SpinStep::SpinStep(wm_step_t step_num, char * p_desc)
	:	Step(step_num, p_desc)
	,	m_p_motor(NULL) {
}

SpinStep::SpinStep(wm_step_t step_num, SevenSegment * p_sev_seg,
		char * p_desc, Motor * p_motor)
	:	Step(step_num, p_sev_seg, p_desc)
	,	m_p_motor(p_motor) {
}

/*
 * Copy ctor because it is not inherited
 */
SpinStep::SpinStep(const SpinStep & src)
	:	Step(src) {
	m_p_motor = src.m_p_motor;
}
/*
 * Assignment operator because it is not inherited
 */
SpinStep & SpinStep::operator= (const SpinStep& rhs) {
	Step::operator =(rhs); // this a function call
	m_p_motor = rhs.m_p_motor;
	return *this;
}

void SpinStep::run() const {
	Step::run();
	m_p_motor->on();
	for(int i=10; i>0; --i) {
		wait();
	}
	m_p_motor->off();
}





