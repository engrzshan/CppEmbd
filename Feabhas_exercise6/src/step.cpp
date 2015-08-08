#include <step.h>
#include <iostream>
using std::cout;
using std::endl;

Step::Step() :
	m_step_num(Step::invalid) {
		cout << "Step::Step: Step number " << m_step_num << endl;
	}

Step::Step(wm_step_t step_num) :
	m_step_num(step_num) {
	cout << "Step::Step: Step number " << m_step_num << endl;
}

Step::Step(Step & step) {
	m_step_num = step.m_step_num;
	cout << "Step::Copy constructor: Step number "
			<< m_step_num << endl;
}

Step::~Step() {
	cout << "Step::~Step: Step number " << m_step_num << endl;
}

void Step::run() const {
	cout << "Running step " << m_step_num << endl;
}




