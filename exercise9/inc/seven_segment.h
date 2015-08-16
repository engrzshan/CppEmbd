#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include <gpio.h>

class SevenSegment {
public:
	SevenSegment(GPIO & gpio);
	~SevenSegment();
	void display(int val);
	void blank();
private:
	GPIO & m_gpio;
	static const uint32_t port_mask;
	static const uint32_t pin_all;
};


#endif /* SEVEN_SEGMENT_H_ */
