/*
 * circ_buf.h
 *
 *  Created on: 6 Sep 2015
 *      Author: engrzshan
 */

#ifndef CIRC_BUF_H_
#define CIRC_BUF_H_

using namespace std;

template<typename T=int, uint32_t sz=10>
class CircBuf {
public:
	enum buf_st_t{
		e_buf_ok, e_buf_empty, e_buf_full
	};

	CircBuf();
	~CircBuf();
	buf_st_t add(T to_store);
	buf_st_t get(T & value);
	void flush();
	bool is_empty(void);

private:
	uint32_t	m_writer;
	uint32_t	m_reader;
	uint32_t	m_items_in_buf;
	//dynamically allocated buffer
	T *	const 	m_buffer;
};

template<typename T, uint32_t sz>
CircBuf<T, sz>::CircBuf()
	:	m_buffer(new T[sz]) {
	flush();
}

template<typename T, uint32_t sz>
CircBuf<T, sz>::~CircBuf(){
	delete[] m_buffer;
}

template<typename T, uint32_t sz>
typename CircBuf<T, sz>::buf_st_t CircBuf<T, sz>::add(T to_store) {
	if(m_items_in_buf==sz) {
		return e_buf_full;
	}

	m_buffer[m_writer] = to_store;
	// reset writer
	if(++m_writer==sz) {
		m_writer = 0;
	}
	++m_items_in_buf; // one more space filled

	return e_buf_ok;
}

template<typename T, uint32_t sz>
typename CircBuf<T, sz>::buf_st_t CircBuf<T, sz>::get(T & value) {
	if(m_items_in_buf==0) {
		return e_buf_empty;
	}

	value = m_buffer[m_reader];
	if(++m_reader==sz) {
		m_reader = 0;
	}
	--m_items_in_buf; // one more space available

	return e_buf_ok;
}

template<typename T, uint32_t sz>
void CircBuf<T, sz>::flush() {
	m_writer = 0;
	m_reader = 0;
	m_items_in_buf = 0;
}

template<typename T, uint32_t sz>
bool CircBuf<T, sz>::is_empty(void){
	return (m_items_in_buf==0);
}

#endif /* CIRC_BUF_H_ */
