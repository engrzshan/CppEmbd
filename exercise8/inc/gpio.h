#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include <chip.h>
#include <gpio_17xx_40xx.h>

class GPIO {
public:
	enum pin_t {pin0, pin1, pin2, pin3, pin4, pin5};
	explicit GPIO(uint32_t base_addr);
	~GPIO();
	void set_as_input(pin_t p);
	void set_as_output(pin_t p);
	void set(pin_t p);
	void clear(pin_t p);
	bool is_set(pin_t p);
private:
	LPC_GPIO_T & m_base_addr;
};


#endif /* GPIO_H_ */

