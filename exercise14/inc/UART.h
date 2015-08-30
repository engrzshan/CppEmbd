// -----------------------------------------------------------------------------
// Copyright Feabhas Ltd 2012
// -----------------------------------------------------------------------------

// UART.h
// Declaration of serial UART class

#ifndef UART_H
#define UART_H

#include <idisplay.h>
#include <stdint.h>
#include <chip.h>
#include <uart_17xx_40xx.h>

class UART : public I_DisplayNumeric
{
public:
  enum baudRate { b9600 = 9600, b38400 = 38400, b115k = 115200};
  enum dataBits {five = 0, six = 1, seven = 2, eight = 3};
  enum stopBits { one = (0<<2), two = (1<<2) };
  enum parity { off = (0 << 3), odd = (0<<4), even = (1<<4)};
    
  explicit UART (uint32_t base_addr,
                  baudRate baud = b115k,
                  dataBits db = eight,
                  stopBits sb = one,
                  parity pb = off);

  void setup_muxing();
    
  uint8_t read () const;
  void write (char);
  void write (const char*);
   
private:
  // Implementation:
  enum
  { 
    DLAB_BIT = 0x80,
    RDR_FLAG = 0x01,
    THRE_FLAG = 0x20
  };

  LPC_USART_T & m_base_addr;
  /* Pin muxing configuration */
  const static PINMUX_GRP_T m_pinmuxing[];
  // Interface realisation
  //
  virtual void display(unsigned int value);
  virtual void display(const char* str);

  UART(const UART&);
  UART& operator=(const UART&);
};


#endif // UART_H
