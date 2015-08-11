#ifndef STEP_H_
#define STEP_H_

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
	 // copy constructor
	Step(Step & step);
	~Step();
	void run() const;
private:
	wm_step_t m_step_num;
};


#endif /* STEP_H_ */
