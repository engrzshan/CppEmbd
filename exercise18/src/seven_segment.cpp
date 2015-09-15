#include <debug_log.h>
#include <seven_segment.h>
#include <gpio.h>
#include <iostream>
#include <iomanip>

using std::ios;
using std::setw;
using std::cout;
using std::endl;

const uint32_t SevenSegment::pin_all = 0x4fu;
const uint32_t SevenSegment::port_mask = ~SevenSegment::pin_all;

SevenSegment::SevenSegment(GPIO & gpio)
	: m_gpio(gpio) {
	m_gpio.set_port_mask(
			m_gpio.get_port_mask() & SevenSegment::port_mask);

	dout << "mask " << std::setw(8) << std::setfill('0')
				<< std::hex
				<< m_gpio.get_port_mask() << std::endl;

	m_gpio.set_port_dir_output(SevenSegment::pin_all);

	dout << "dir " << std::setw(8) << std::setfill('0')
			<< std::hex <<
			m_gpio.get_port_dir() << std::endl;

	dout << "pin " << std::setw(8) << std::setfill('0')
				<< std::hex
				<< m_gpio.get_masked_port_val() << std::endl;

	blank();
}

SevenSegment::~SevenSegment() {
	m_gpio.set_port_mask(m_gpio.get_port_mask() |
			(~SevenSegment::port_mask));
}

void SevenSegment::display(unsigned int val) {
	// Should not require this line, but bare with it for now
	// until HW has the ability to toggle /bl
	m_gpio.set(GPIO::pin6);
	if(val < 10U) {
	m_gpio.set_masked_port_val(
			(m_gpio.get_masked_port_val() & 0xf0)|val);
	} else {
		dout << "Value can't be displayed" << std::endl;
	}
}

void SevenSegment::blank() {
	m_gpio.clear(GPIO::pin6);
}
