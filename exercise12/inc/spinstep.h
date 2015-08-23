#ifndef SPINSTEP_H_
#define SPINSTEP_H_

#include <step.h>
#include <motor.h>

class SpinStep: public Step {
public:
	SpinStep(wm_step_t step_num = e_invalid);
	SpinStep(wm_step_t step_num, SevenSegment * p_sev_seg);
	SpinStep(wm_step_t step_num, char * p_desc);
	SpinStep(wm_step_t step_num, SevenSegment * p_sev_seg, char * p_desc, Motor * p_motor);
	SpinStep(const SpinStep & src);
	SpinStep & operator= (const SpinStep& rhs);
	virtual void run() const;
private:
	Motor * m_p_motor;
};

#endif /* SPINSTEP_H_ */
