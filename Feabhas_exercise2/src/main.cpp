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

	Step(wm_step_t step_num) {
		m_step_num = step_num;
	}
	~Step(){}

	void run() const {
		cout << "Running step " << m_step_num << endl;
	}
private:
	wm_step_t m_step_num;
};

int main()
{
	Step s_empty(Step::empty);
	Step s_fill(Step::fill);
	Step s_heat(Step::heat);
	Step s_wash(Step::wash);
	Step s_rinse(Step::rinse);
	Step s_spin(Step::spin);
	Step s_dry(Step::dry);
	Step s_complete(Step::complete);

	s_empty.run();
	s_fill.run();
	s_heat.run();
	s_wash.run();
	s_rinse.run();
	s_spin.run();
	s_dry.run();
	s_complete.run();

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
