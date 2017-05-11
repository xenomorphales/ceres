#include "pull.h"

#include "periph/gpio.h"

#define PULL_PIN GPIO_PIN(PA, 12)

int pull_init(void) {
  gpio_init(PULL_PIN, GPIO_IN);
  return 0;
}

int pull_state(void) {
  int pull = gpio_read(PULL_PIN);
  if(pull == 1) {
    return PULL_OUT;
  }
  else {
    return PULL_IN;
  }
}
