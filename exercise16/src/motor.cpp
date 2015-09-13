#include <motor.h>
#include <gpio.h>
#include <iostream>
#include <iomanip>
using std::ios;
using std::setw;

const uint32_t  Motor::enable_pin = (1 << 4);
const uint32_t  Motor::change_dir_pin = (1 << 5);
const uint32_t  Motor::port_mask = ~(Motor::enable_pin|Motor::change_dir_pin);

Motor::Motor(GPIO & gpio)
	: m_gpio(gpio) {
	m_gpio.set_port_mask(
			m_gpio.get_port_mask() & Motor::port_mask);

	m_gpio.set_port_dir_output(
			Motor::enable_pin|Motor::change_dir_pin);

	m_gpio.set_port_low(Motor::enable_pin|Motor::change_dir_pin);
}

Motor::~Motor() {
	m_gpio.set_port_mask(~port_mask);
}

void Motor::on() {
	m_gpio.set_port_high(Motor::enable_pin|Motor::change_dir_pin);
}

void Motor::off() {
	m_gpio.set_port_low(Motor::enable_pin);
}

void Motor::change_direction() {
	// stop before changing direction
	m_gpio.set_port_low(Motor::enable_pin);

	if(m_gpio.get_masked_port_val() & Motor::change_dir_pin) {
		m_gpio.set_port_low(Motor::change_dir_pin);
	} else {
		m_gpio.set_port_high(Motor::change_dir_pin);
	}
	// re-start after changing direction
	m_gpio.set_port_high(Motor::enable_pin);
}
