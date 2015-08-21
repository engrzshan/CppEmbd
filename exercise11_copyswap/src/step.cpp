#include <debug_log.h>
#include <step.h>
#include <iostream>
#include <seven_segment.h>
#include <cstring>
using std::cout;
using std::endl;

Step::Step()
	:	m_step_num(Step::invalid)
	,	m_p_seven_seg(NULL)
	,	m_p_desc(NULL) {
	dout << "Step::Step(): Step number " << m_step_num << endl;
}

Step::Step(wm_step_t step_num)
	:	m_step_num(step_num)
	,	m_p_seven_seg(NULL)
	,	m_p_desc(NULL) {
	dout << "Step::Step(): Step number " << m_step_num << endl;
}

//Step::Step(wm_step_t step_num, SevenSegment * p_sev_seg)
//	:m_step_num(step_num)
//	,m_p_sev_seg(p_sev_seg) {
//}

Step::Step(wm_step_t step_num, char * p_desc)
	:	m_step_num(step_num)
	,	m_p_seven_seg(NULL)
	,	m_p_desc(new char[(strlen(p_desc)+1)]) {
	strcpy(m_p_desc, p_desc);
	dout << "Step::Step(): Step number " << m_step_num << endl;
	dout << "Description " << m_p_desc << endl;
}
/*
 * Copy ctor for a class that owns a resource
 * The rule of the big three
 */
Step::Step(const Step & src)
	//Copy non-dynamic members (using MIL)
	: 	m_step_num(src.m_step_num)
	,	m_p_seven_seg(src.m_p_seven_seg)
	//Allocate new resource
	,	m_p_desc(new char[(strlen(src.m_p_desc)+1)]) {
	//Copy src.resource data into new resource
	strcpy(m_p_desc, src.m_p_desc);
	dout << "Step::Copy constructor: Step number "
			<< m_step_num << endl;
}
/*
 * Assignment operator implemented using copy-swap
 * idiom for a class that owns a resource
 * The rule of the big three (and a half)
 */
//Step & Step::operator= (const Step& rhs) {
//	//Copy construct temp
//	Step temp(rhs);
//	//Swap temp with this
//	swap(temp);
//
//	dout << "Step::operator=  : Step number: "
//			<< m_step_num << endl;
//	return *this;
//}

/*
 * Assignment operator implemented using copy-swap
 * idiom for a class that owns a resource
 * The rule of the big three (and a half)
 *
 * There is a (small) chance that if the copy constructor
 * (for temp) fails it could throw an exception, possibly
 * leaving the receiving object in an invalid state.
 *
 * To stop this, we re-write the assignment operator and
 * move the copy construction outside the call. Notice the
 * assignment operator has been re-written to take a Step
 * object by value. See this blog article by Glenn from Feabhas
 * https://blog.feabhas.com/2014/12/the-rule-of-the-big-three-and-a-half-resource-management-in-c/
 * Also see this stackoverflow.com question/answer
 * http://stackoverflow.com/questions/4172722/what-is-the-rule-of-three
 */
Step & Step::operator= (Step rhs) {
	//Swap rhs with this
	swap(rhs);
	dout << "Step::operator=  : Step number: "
			<< m_step_num << endl;
	return *this;
}


void Step::swap(Step & rhs) {
	//Swap each attribute
	std::swap(this->m_step_num, rhs.m_step_num);
	std::swap(this->m_p_seven_seg, rhs.m_p_seven_seg);
	std::swap(this->m_p_desc, rhs.m_p_desc);
}

/*
 * Destructor for a class that owns a resource
 * The rule of the big three
 */
Step::~Step() {
	dout << "Step::~Step: Step number " << m_step_num << endl;
	//Delete resource
	delete[] m_p_desc;
}

void Step::run() const {
	if(m_p_desc != NULL) {
		dout << "Running step: " << m_p_desc << endl;
	} else {
		dout << "Running step " << m_step_num << endl;
	}

	if(m_p_seven_seg != NULL) {
		m_p_seven_seg->display(m_step_num);
	}
}

void bind(Step & step, SevenSegment & sev_seg) {
	step.m_p_seven_seg = &sev_seg;
}



