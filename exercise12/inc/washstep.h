#ifndef washstep_H
#define washstep_H

#include <step.h>
#include <motor.h>

class WashStep: public Step {
public:
	WashStep(wm_step_t step_num = e_invalid);
	WashStep(wm_step_t step_num, SevenSegment * p_sev_seg);
	WashStep(wm_step_t step_num, char * p_desc);
	WashStep(wm_step_t step_num, SevenSegment * p_sev_seg, char * p_desc, Motor * p_motor);
	WashStep(const WashStep & src);
	WashStep & operator= (const WashStep& rhs);
	virtual void run() const;
private:
	Motor * m_p_motor;
};

#endif /* washstep_H */
