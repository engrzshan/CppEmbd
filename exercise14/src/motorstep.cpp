#include <debug_log.h>
#include <motor.h>
#include <iostream>
#include <seven_segment.h>
#include <motorstep.h>

using std::cout;
using std::endl;

MotorStep::MotorStep(wm_step_t step_num)
	:	Step(step_num)
	,	m_p_motor(NULL) {
}

MotorStep::MotorStep(wm_step_t step_num, I_DisplayNumeric * p_idisp)
	:	Step(step_num, p_idisp)
	,	m_p_motor(NULL) {
}

MotorStep::MotorStep(wm_step_t step_num, char * p_desc)
	:	Step(step_num, p_desc)
	,	m_p_motor(NULL) {
}

MotorStep::MotorStep(wm_step_t step_num, I_DisplayNumeric * p_idisp, char * p_desc, Motor * p_motor)
	:	Step(step_num, p_idisp, p_desc)
	,	m_p_motor(p_motor) {
}

/*
 * Copy ctor because it is not inherited
 */
MotorStep::MotorStep(const MotorStep & src)
	:	Step(src) {
	m_p_motor = src.m_p_motor;
}
/*
 * Assignment operator because it is not inherited
 */
MotorStep & MotorStep::operator= (const MotorStep& rhs) {
	Step::operator =(rhs); // this a function call
	m_p_motor = rhs.m_p_motor;
	return *this;
}
