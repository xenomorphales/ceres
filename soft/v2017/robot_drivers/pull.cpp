#include "pull.hpp"

#include "periph/gpio.h"

#define PULL_PIN GPIO_PIN(PA, 12)

Pull::Pull(void) {
  gpio_init(PULL_PIN, GPIO_IN);
}

Pull::State Pull::state(void) {
  int pull = gpio_read(PULL_PIN);
  if(pull == 1) {
    return OUT;
  }
  else {
    return IN;
  }
}
