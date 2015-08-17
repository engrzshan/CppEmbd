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
 * Assignment operator for a class that owns a resource
 * The rule of the big three
 */
Step & Step::operator= (const Step& rhs) {
	//Allocate the new temporary resoure
	char * p_temp = new char[strlen(rhs.m_p_desc)+1];

	//Copy rhs.resource data into temporary resource
	strcpy(p_temp, rhs.m_p_desc);

	//Delete this->resource
	delete[] this->m_p_desc;

	//Take ownership of the temporary resource
	this->m_p_desc = p_temp;

	//Copy other members
	m_step_num = rhs.m_step_num;
	m_p_seven_seg = rhs.m_p_seven_seg;
	//dout << "m_p_desc " << (void *)m_p_desc << endl;
	//dout << "m_p_desc " << (void *)m_p_desc << endl;
	//dout << "rhs.m_p_desc " << (void *)rhs.m_p_desc << endl;
	dout << "Step::operator=  : Step number: "
			<< m_step_num << endl;
	return *this;
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



