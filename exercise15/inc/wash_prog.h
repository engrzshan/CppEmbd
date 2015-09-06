#ifndef WASH_PROG_H_
#define WASH_PROG_H_

#include <step.h>

const int wash_prog_size = 10;

class WashProgramme {
public:
	enum error_t {
		OK,
		FULL
	};
	WashProgramme();
	~WashProgramme();
	//error_t add(Step s);
	error_t add(Step & s);
	void run() const;
private:
	unsigned int next_step;
	Step * programme[wash_prog_size];
};

#endif /* WASH_PROG_H_ */
