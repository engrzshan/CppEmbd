/// -----------------------------------------------------------------------------
// Copyright Feabhas Ltd 2012
// -----------------------------------------------------------------------------

// UART.cpp
// Definition of serial UART class

#include "UART.h"
#include "board.h"
#include "chip.h"
#include "uart_17xx_40xx.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::ostringstream;

const PINMUX_GRP_T UART::m_pinmuxing[] = {
	{0,  0,  IOCON_MODE_INACT | IOCON_FUNC2},	/* TXD3 */
	{0,  1,  IOCON_MODE_INACT | IOCON_FUNC2}	/* RXD3 */
};


UART::UART (uint32_t base_addr,
          baudRate baud,
          dataBits db,
          stopBits sb,
          parity pb)
	: 	m_base_addr(*(reinterpret_cast<LPC_USART_T *>(base_addr)))
{
  // Set pins as USART3
  setup_muxing();
  // Generic Initialization
  SystemCoreClockUpdate();
  Chip_UART_Init(&m_base_addr);
  Chip_UART_SetBaud(&m_base_addr, baud);
  Chip_UART_ConfigData(&m_base_addr, db|sb|pb);
  // Enable UART Transmit
  Chip_UART_TXEnable(&m_base_addr);
}

void UART::setup_muxing() {
	Chip_IOCON_SetPinMuxing(LPC_IOCON, UART::m_pinmuxing,
			sizeof(UART::m_pinmuxing) / sizeof(PINMUX_GRP_T));
}


uint8_t UART::read () const
{
  while((Chip_UART_ReadLineStatus(&m_base_addr) & UART_LSR_RDR) == 0){}
  return Chip_UART_ReadByte(&m_base_addr);
}
  

void UART::write (char c)
{
  while((Chip_UART_ReadLineStatus(&m_base_addr) & UART_LSR_THRE)==0) {}
  Chip_UART_SendByte(&m_base_addr, static_cast<unsigned char>(c));
}


void UART::write (const char* str)
{
  while (*str != '\0')
  {
    write (*str);
    str++;
  }
}

void UART::display(unsigned int value)
{
  // Use a stringStream object to build
  // a string out of the integer value
  ostringstream valString;
  valString << value;
  write(valString.str().c_str());
}

void UART::display(const char* str)
{
  write(str);
}

