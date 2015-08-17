#ifndef STEP_H_
#define STEP_H_

class SevenSegment;

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
	Step(wm_step_t step_num, char * p_desc);
	//Step(wm_step_t step_num, SevenSegment * p_sev_seg);
	 // copy constructor
	Step(Step & step);
	Step & operator= (const Step& rhs);
	~Step();
	void run() const;
private:
	wm_step_t m_step_num;
	SevenSegment * m_p_seven_seg;
	char * m_p_desc;
	//instead of adding a constructor that takes ref to
	//SevenSegment as an argument and then modifying other
	//constructors we can just add a bind function.
	friend void bind(Step & step, SevenSegment & sev_seg);
};

void bind(Step & step, SevenSegment & sev_seg);

#endif /* STEP_H_ */
