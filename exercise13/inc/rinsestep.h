#ifndef RINSESTEP_H_
#define RINSESTEP_H_

#include <motorstep.h>
class Motor;

class RinseStep: public MotorStep {
public:
	RinseStep(wm_step_t step_num = e_invalid);
	RinseStep(wm_step_t step_num, SevenSegment * p_sev_seg);
	RinseStep(wm_step_t step_num, char * p_desc);
	RinseStep(wm_step_t step_num, SevenSegment * p_sev_seg, char * p_desc, Motor * p_motor);
	virtual void run() const;
private:
};

#endif /* RINSESTEP_H_ */
