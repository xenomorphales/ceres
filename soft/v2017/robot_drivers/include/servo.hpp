#ifndef SERVO_HPP
#define SERVO_HPP

#include "singleton.hpp"
#include "service.hpp"

#include "feetech.h"
#include "dynamixel.h"

class ServoBus : public Singleton<ServoBus>, public Service {
private:
  uint8_t _buffer[64];
  uart_half_duplex_t _stream;

public:
  ServoBus(void) {
    uart_half_duplex_params_t params = {};
    params.uart = UART_DEV(1);
    params.baudrate = 1000000;
    params.dir = UART_HALF_DUPLEX_DIR_NONE;

    int ret = uart_half_duplex_init(&_stream, _buffer, sizeof(_buffer), &params);
    if(ret != UART_HALF_DUPLEX_OK) {
      setState(ERROR);
    }

    setState(RUN);
  }

  inline uart_half_duplex_t& stream(void) {
    return _stream;
  }
};


#endif//SERVO_HPP
