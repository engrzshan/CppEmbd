#include <wash_prog.h>

//const int wash_prog_size = 10;

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

WashProgramme::error_t WashProgramme::add(Step & s) {
	if(next_step == wash_prog_size) {
		return FULL;
	}
	programme[next_step]= s;
	++next_step;
	return OK;
}

void WashProgramme::run() const {
	for (unsigned int i=0; i<next_step; ++i) {
		programme[i].run();
	}
}


