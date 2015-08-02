/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setiosflags;
using std::setprecision;
using std::ios;
using std::setw;
// TODO: insert other definitions and declarations here

class Step {
public:
	enum wm_step_t {
		invalid,
		empty,
		fill,
		heat,
		wash,
		rinse,
		spin,
		dry,
		complete
	};

	Step() :
		m_step_num(Step::invalid) {
		cout << "Step::Step: Step number " << m_step_num << endl;
	}

	Step(wm_step_t step_num) :
		m_step_num(step_num) {
		cout << "Step::Step: Step number " << m_step_num << endl;
	}

	~Step(){
		cout << "Step::~Step: Step number " << m_step_num << endl;
	}

	void run() const {
		cout << "Running step " << m_step_num << endl;
	}
private:
	const wm_step_t m_step_num;
};

void wash(Step programme[], int num_steps) {
	for(int i=0; i<num_steps; i++)
	{
		programme[i].run();
	}
}
#define sizeof_arr(ARR)	(sizeof(ARR)/sizeof(ARR[0]))

int main() {
	Step colourwash[] = {
		Step(Step::empty),
		Step(Step::fill),
		Step(Step::heat),
		Step(Step::wash),
		Step(Step::rinse),
		Step(Step::spin),
		Step(Step::dry),
		Step(Step::complete)
	};
	wash(colourwash, sizeof_arr(colourwash));
}
/*int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}*/
