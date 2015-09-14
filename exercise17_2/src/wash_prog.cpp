#include <wash_prog.h>
#include <cstddef>

#ifdef INTERNAL_CONTAINER
WashProgramme::WashProgramme() :
		next_step(0) {
}

WashProgramme::~WashProgramme(){
}

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
	for(std::list<Step *>::const_iterator it=programme.begin(); it!=programme.end(); ++it) {
		if((*it)!=NULL) {
			(*it)->run();
		}
	}
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
	Programme::const_iterator it;
	for(it=m_programme.begin(); it!=m_programme.end(); ++it) {
		if((*it)!=NULL) {
			(*it)->run();
		}
	}
}
#endif // CONTAINER_AS_PARAMETER
