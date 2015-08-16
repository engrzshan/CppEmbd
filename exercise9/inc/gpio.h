#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include <chip.h>
#include <gpio_17xx_40xx.h>

class GPIO {
public:
	enum pin_t {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7};
	explicit GPIO(uint32_t base_addr);
	~GPIO();
	void set_pin_as_input(pin_t p);
	void set_pin_as_output(pin_t p);
	void set(pin_t p);
	void clear(pin_t p);
	bool is_set(pin_t p) const;
	void set_port_dir_output(uint32_t mask);
	void set_port_dir_input(uint32_t mask);
	uint32_t get_port_dir() const;
	void set_port_mask(uint32_t mask);
	uint32_t get_port_mask() const;
	void set_masked_port_val(uint32_t value);
	uint32_t get_masked_port_val() const;
	void set_port_high(uint32_t pins);
	void set_port_low(uint32_t pins);
private:
	LPC_GPIO_T & m_base_addr;
	// Disable copying.
	GPIO(const GPIO&);
	GPIO& operator=(const GPIO&);
};


#endif /* GPIO_H_ */


