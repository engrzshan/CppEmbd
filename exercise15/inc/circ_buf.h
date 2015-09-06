/*
 * circ_buf.h
 *
 *  Created on: 6 Sep 2015
 *      Author: engrzshan
 */

#ifndef CIRC_BUF_H_
#define CIRC_BUF_H_

const uint32_t BUF_SIZE = 10;

class CircularBuffer {
public:
	CircularBuffer(uint32_t	size)
	:	m_writer(0)
	,	m_reader(0)
	,	m_items_in_buf(0)
	{

	}

	~CircularBuffer(){}
//	void init() {
//		writer = 0;
//		reader = 0;
//		items_in_buf = 0;
//	}

	enum buf_status_t{
		e_buf_ok, e_buf_empty, e_buf_full
	};

	buf_status_t add(uint32_t to_store) {
		if(m_items_in_buf==BUF_SIZE) {
			return e_buf_full;
		}

		buffer[m_writer] = to_store;
		// reset writer
		if(++m_writer==BUF_SIZE) {
			m_writer = 0;
		}
		++m_items_in_buf; // one more space filled

		return e_buf_ok;
	}

	buf_status_t get(uint32_t & value) {
		if(m_items_in_buf==0) {
			return e_buf_empty;
		}

		value = buffer[m_reader];
		if(++m_reader==BUF_SIZE) {
			m_reader = 0;
		}
		--m_items_in_buf; // one more space available

		return e_buf_ok;
	}

	bool is_empty(void){
		return (m_items_in_buf==0);
	}

private:
	uint32_t	m_writer;
	uint32_t	m_reader;
	uint32_t	m_items_in_buf;
	uint32_t	buffer[BUF_SIZE];
};



#endif /* CIRC_BUF_H_ */
