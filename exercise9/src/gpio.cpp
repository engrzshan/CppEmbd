#include "gpio.h"

GPIO::GPIO(uint32_t base_addr)
	: 	m_base_addr(*(reinterpret_cast<LPC_GPIO_T *>(base_addr))) {
	Chip_GPIO_Init(LPC_GPIO);
}

GPIO::~GPIO() {
	Chip_GPIO_DeInit(LPC_GPIO);
}

void GPIO::set_pin_as_input(pin_t p) {
	m_base_addr.DIR &= ~(1UL << p);
}

void GPIO::set_port_dir_input(uint32_t mask) {
	m_base_addr.DIR &= ~mask;
}

void GPIO::set_pin_as_output(pin_t p) {
	m_base_addr.DIR |= 1UL << p;
}

void GPIO::set_port_dir_output(uint32_t mask) {
	m_base_addr.DIR |= mask;
}

uint32_t GPIO::get_port_dir() const {
	return m_base_addr.DIR;
}

void GPIO::set(pin_t p) {
	m_base_addr.SET = 1UL << p;
}

void GPIO::set_port_mask(uint32_t mask) {
	m_base_addr.MASK= mask;
}

uint32_t GPIO::get_port_mask() const {
	return m_base_addr.MASK;
}

void GPIO::set_masked_port_val(uint32_t value) {
	m_base_addr.PIN = value;
}

uint32_t GPIO::get_masked_port_val() const {
	return m_base_addr.PIN;
}

void GPIO::set_port_high(uint32_t pins) {
	m_base_addr.SET = pins;
}

void GPIO::set_port_low(uint32_t pins) {
	m_base_addr.CLR = pins;
}

void GPIO::clear(pin_t p) {
	m_base_addr.CLR = 1UL << p;
}

bool GPIO::is_set(pin_t p) const {
	return (bool) ((m_base_addr.PIN >> p) & 1);
}


