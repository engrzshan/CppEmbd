#ifndef STEP_H_
#define STEP_H_

#include <seven_segment.h>

class Step {
public:
	enum wm_step_t {
		invalid,
		empty,
		fill,
		heat,
		wash,
		rinse,
		spin,
		dry,
		complete
	};
	Step();
	Step(wm_step_t step_num);
	Step(wm_step_t step_num, SevenSegment * p_sev_seg);
	 // copy constructor
	Step(Step & step);
	~Step();
	void run() const;
private:
	wm_step_t m_step_num;
	SevenSegment * m_p_sev_seg;
};


#endif /* STEP_H_ */
