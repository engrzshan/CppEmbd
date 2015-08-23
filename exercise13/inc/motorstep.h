/*
 * motorstep.h
 *
 *  Created on: 23 Aug 2015
 *      Author: engrzshan
 */

#ifndef MOTORSTEP_H_
#define MOTORSTEP_H_

#include <step.h>
class Motor;

class MotorStep: public Step {
public:
	MotorStep(wm_step_t step_num = e_invalid);
	MotorStep(wm_step_t step_num, SevenSegment * p_sev_seg);
	MotorStep(wm_step_t step_num, char * p_desc);
	MotorStep(wm_step_t step_num, SevenSegment * p_sev_seg, char * p_desc, Motor * p_motor);
	MotorStep(const MotorStep & src);
	MotorStep & operator= (const MotorStep& rhs);
	virtual void run() const = 0;
protected:
	Motor * m_p_motor;
};

#endif /* MOTORSTEP_H_ */
