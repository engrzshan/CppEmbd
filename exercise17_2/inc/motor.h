#ifndef MOTOR_H_
#define MOTOR_H_
#include <gpio.h>

class Motor {
public:
	Motor(GPIO & gpio);
	~Motor();
	void on();
	void off();
	void change_direction();
private:
	GPIO & m_gpio;
	static const uint32_t  enable_pin;
	static const uint32_t  change_dir_pin;
	static const uint32_t  port_mask;
};

#endif /* MOTOR_H_ */
