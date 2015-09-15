#include <wash_prog.h>
#include <cstddef>
#include <algorithm>
#include <step.h>
#include <functional>

using std::mem_fun;

#ifdef INTERNAL_CONTAINER
WashProgramme::WashProgramme() :
		next_step(0) {
}

WashProgramme::~WashProgramme(){
}

/*WashProgramme::error_t WashProgramme::add(Step s) {
	if(next_step == wash_prog_size) {
		return FULL;
	}
	programme[next_step]= s;
	++next_step;
	return OK;
}*/

WashProgramme::error_t WashProgramme::add(Step &s) {
	if(next_step == wash_prog_size) {
		return FULL;
	}
	//programme[next_step]= s;
	programme.push_back(&s);
	++next_step;
	return OK;
}

void WashProgramme::run() const {
	/*
	 * for_each requires a global function as its 3rd argument.
	 * Here's where mem_fun comes in useful. This adapter lets
	 * you use member functions where a global function is called
	 * for. It creates a Function object and is easy to use.
	 */
	std::for_each( programme.begin(), programme.end(), mem_fun(&Step::run) );
}

#endif // INTERNAL_CONTAINER

// -----------------------------------------------------------------------------
#ifdef CONTAINER_AS_PARAMETER
WashProgramme::WashProgramme(WashProgramme::Programme & programme)
	:	m_programme(programme)
	,	next_step(0) {
}

WashProgramme::~WashProgramme(){
}

// NOTE: No add function
void WashProgramme::run() const {
	/*
	 * for_each requires a global function as its 3rd argument.
	 * Here's where mem_fun comes in useful. This adapter lets
	 * you use member functions where a global function is called
	 * for. It creates a Function object and is easy to use.
	 */
	std::for_each( m_programme.begin(), m_programme.end(), mem_fun(&Step::run) );
}
#endif // CONTAINER_AS_PARAMETER
