#include "gp2.hpp"

#include "periph/adc.h"

GP2::GP2(int id)
  : _id(id) {
  adc_init(id);
}

int GP2::get(void) {
  return adc_sample(_id, ADC_RES_8BIT);
}

GP2 GP2::gp2[4] = {
  GP2(0),
  GP2(1),
  GP2(2),
  GP2(3),
};
