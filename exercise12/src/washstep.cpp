#include <debug_log.h>
#include <motor.h>
#include <iostream>
#include <seven_segment.h>
#include <washstep.h>

using std::cout;
using std::endl;

//class Wash: public Step {
//public:
//	Wash(wm_step_t step_num = e_invalid);
//	Wash(wm_step_t step_num, SevenSegment * p_sev_seg);
//	Wash(wm_step_t step_num, char * p_desc);
//	Wash(wm_step_t step_num, SevenSegment * p_sev_seg, char * p_desc, Motor & motor);
//	~Wash();
//	virtual void run() const;
//	void wait();
//private:
//	Motor & m_motor;
//};
static void wait() {
  for(volatile int i = 0; i < 10000000; ++i);
}

WashStep::WashStep(wm_step_t step_num)
	:	Step(step_num)
	,	m_p_motor(NULL) {
}

WashStep::WashStep(wm_step_t step_num, SevenSegment * p_sev_seg)
	:	Step(step_num, p_sev_seg)
	,	m_p_motor(NULL) {
}

WashStep::WashStep(wm_step_t step_num, char * p_desc)
	:	Step(step_num, p_desc)
	,	m_p_motor(NULL) {
}

WashStep::WashStep(wm_step_t step_num, SevenSegment * p_sev_seg, char * p_desc, Motor * p_motor)
	:	Step(step_num, p_sev_seg, p_desc)
	,	m_p_motor(p_motor) {
}

/*
 * Copy ctor because it is not inherited
 */
WashStep::WashStep(const WashStep & src)
	:	Step(src) {
	m_p_motor = src.m_p_motor;
}
/*
 * Assignment operator because it is not inherited
 */
WashStep & WashStep::operator= (const WashStep& rhs) {
	Step::operator =(rhs); // this a function call
	m_p_motor = rhs.m_p_motor;
	return *this;
}

void WashStep::run() const {
	Step::run();
	m_p_motor->on();
	wait();
	m_p_motor->change_direction();
	wait();
	m_p_motor->off();
}

