#include "gpio.h"

GPIO::GPIO(uint32_t base_addr)
	: 	m_base_addr(*(reinterpret_cast<LPC_GPIO_T *>(base_addr))) {
	Chip_GPIO_Init(LPC_GPIO);
}

GPIO::~GPIO() {
	Chip_GPIO_DeInit(LPC_GPIO);
}

void GPIO::set_as_input(pin_t p) {
	m_base_addr.DIR &= ~(1UL << p);
}

void GPIO::set_as_output(pin_t p) {
	m_base_addr.DIR |= 1UL << p;
}

void GPIO::set(pin_t p) {
	m_base_addr.SET = 1UL << p;
}

void GPIO::clear(pin_t p) {
	m_base_addr.CLR = 1UL << p;
}

bool GPIO::is_set(pin_t p) {
	return (bool) ((m_base_addr.PIN >> p) & 1);
}


