/*
 * idisplay.h
 *
 *  Created on: 29 Aug 2015
 *      Author: engrzshan
 */

#ifndef IDISPLAY_H_
#define IDISPLAY_H_

class I_DisplayNumeric {
public:
	virtual void display(unsigned int value) = 0;
	virtual ~I_DisplayNumeric(){}
};

class I_DisplayText {
public:
	virtual void display(const char * str) = 0;
	virtual ~I_DisplayText(){}
};

#endif /* IDISPLAY_H_ */
