/*
 * debug_log.h
 *
 *  Created on: 16 Aug 2015
 *      Author: engrzshan
 */

#ifndef DEBUG_LOG_H_
#define DEBUG_LOG_H_

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif


#endif /* DEBUG_LOG_H_ */
