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
	virtual void display(unsigned int num) = 0;
	virtual ~I_DisplayNumeric(){}
};



#endif /* IDISPLAY_H_ */
