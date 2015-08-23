#ifndef SPINSTEP_H_
#define SPINSTEP_H_

#include <motorstep.h>
class Motor;

class SpinStep: public MotorStep {
public:
	SpinStep(wm_step_t step_num = e_invalid);
	SpinStep(wm_step_t step_num, SevenSegment * p_sev_seg);
	SpinStep(wm_step_t step_num, char * p_desc);
	SpinStep(wm_step_t step_num, SevenSegment * p_sev_seg, char * p_desc, Motor * p_motor);
	virtual void run() const;
private:
};

#endif /* SPINSTEP_H_ */
