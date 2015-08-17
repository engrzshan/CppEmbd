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

//Step::Step(Step & step) {
//	m_step_num = step.m_step_num;
//	dout << "Step::Copy constructor: Step number "
//			<< m_step_num << endl;
//}
// Needed this, otherwise when WashProgramme::add() is called
// a shallow copy is performed which does not allow the use of
// delete[] in the dstr of this class and we get hard fault
// indicating a null pointer has been free'd.
// This is not
Step & Step::operator= (const Step& rhs) {
	m_step_num = rhs.m_step_num;
	m_p_seven_seg = rhs.m_p_seven_seg;
	//dout << "m_p_desc " << (void *)m_p_desc << endl;
	m_p_desc = new char[(strlen(rhs.m_p_desc)+1)];
	strcpy(m_p_desc, rhs.m_p_desc);
	//dout << "m_p_desc " << (void *)m_p_desc << endl;
	//dout << "rhs.m_p_desc " << (void *)rhs.m_p_desc << endl;
	dout << "Step::operator=  : Step number: "
			<< m_step_num << endl;
	return *this;
}

Step::~Step() {
	dout << "Step::~Step: Step number " << m_step_num << endl;
	delete[] m_p_desc;
}

void Step::run() const {
	if(m_p_desc != NULL) {
		dout << "Running step " << m_p_desc << endl;
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



