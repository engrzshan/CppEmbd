#ifndef washstep_H
#define washstep_H

#include <motorstep.h>
class Motor;

class WashStep: public MotorStep {
public:
	WashStep(wm_step_t step_num = e_invalid);
	WashStep(wm_step_t step_num, I_DisplayNumeric * p_idisp);
	WashStep(wm_step_t step_num, char * p_desc);
	WashStep(wm_step_t step_num, I_DisplayNumeric * p_idisp, char * p_desc, Motor * p_motor);
	virtual void run() const;
private:
};

#endif /* washstep_H */
