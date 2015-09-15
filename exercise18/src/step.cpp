#include <debug_log.h>
#include <step.h>
#include <iostream>
#include <seven_segment.h>
#include <cstring>
#include <cstddef>

using std::cout;
using std::endl;

static void wait() {
  for(volatile int i = 0; i < 5000000; ++i);
}

Step::Step()
	:	m_step_num(Step::e_invalid)
	,	m_p_idisp(NULL)
	,	m_p_desc(NULL) {
	dout << "Step::Step(): Step number " << m_step_num << endl;
}

Step::Step(wm_step_t step_num)
	:	m_step_num(step_num)
	,	m_p_idisp(NULL)
	,	m_p_desc(NULL) {
	dout << "Step::Step(): Step number " << m_step_num << endl;
}

Step::Step(wm_step_t step_num, I_DisplayNumeric * idisp_num)
	:	m_step_num(step_num)
	,	m_p_idisp(idisp_num)
	,	m_p_desc(NULL) {
}

Step::Step(wm_step_t step_num, char * p_desc)
	:	m_step_num(step_num)
	,	m_p_idisp(NULL)
	,	m_p_desc(new char[(strlen(p_desc)+1)]) {
	strcpy(m_p_desc, p_desc);
	dout << "Step::Step(): Step number " << m_step_num << endl;
	dout << "Description " << m_p_desc << endl;
}

Step::Step(wm_step_t step_num, I_DisplayNumeric * idisp_num, char * p_desc)
	:	m_step_num(step_num)
	,	m_p_idisp(idisp_num)
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
	,	m_p_idisp(src.m_p_idisp)
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
	m_p_idisp = rhs.m_p_idisp;

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
	if(m_p_idisp == NULL) return;
	// Text output over interface:
	// Use a cross-cast to see if the output device
	// supports text output.  If it does (AND there's
	// something to print) then display the description.

	I_DisplayText * p_i_disp_text = dynamic_cast<I_DisplayText*>(m_p_idisp);

	if(p_i_disp_text != NULL) {
		p_i_disp_text->display("Running step: ");
		if(m_p_desc != NULL) {
			p_i_disp_text->display(m_p_desc);
		} else {
			dout << "Running step " << m_step_num << endl;
		}
		p_i_disp_text->display("\n\r");
	} else { // the interface does not support textual output
		m_p_idisp->display(m_step_num);
	}
	wait();
}


