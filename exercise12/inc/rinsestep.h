#ifndef RINSESTEP_H_
#define RINSESTEP_H_

#include <step.h>
#include <motor.h>

class RinseStep: public Step {
public:
	RinseStep(wm_step_t step_num = e_invalid);
	RinseStep(wm_step_t step_num, SevenSegment * p_sev_seg);
	RinseStep(wm_step_t step_num, char * p_desc);
	RinseStep(wm_step_t step_num, SevenSegment * p_sev_seg, char * p_desc, Motor * p_motor);
	RinseStep(const RinseStep & src);
	RinseStep & operator= (const RinseStep& rhs);
	virtual void run() const;
private:
	Motor * m_p_motor;
};

#endif /* RINSESTEP_H_ */
