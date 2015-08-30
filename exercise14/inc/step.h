#ifndef STEP_H_
#define STEP_H_

class I_DisplayNumeric;

class Step {
public:
	enum wm_step_t {
		e_invalid,
		e_empty,
		e_fill,
		e_heat,
		e_wash,
		e_rinse,
		e_spin,
		e_dry,
		e_complete
	};
	Step();
	Step(wm_step_t step_num);
	Step(wm_step_t step_num, char * p_desc);
	Step(wm_step_t step_num, I_DisplayNumeric * idisp_num);
	Step(wm_step_t step_num, I_DisplayNumeric * idisp_num, char * p_desc);

	 // copy constructor
	Step(const Step & src);
	Step & operator= (const Step& rhs);
	~Step();
	virtual void run() const;

private:
	wm_step_t m_step_num;
	char * m_p_desc;
	I_DisplayNumeric * m_p_idisp;
	//instead of adding a constructor that takes ref to
	//SevenSegment as an argument and then modifying other
	//constructors we can just add a bind function.
	//friend void bind(Step & step, SevenSegment & sev_seg);
};

//void bind(Step & step, SevenSegment & sev_seg);

#endif /* STEP_H_ */
