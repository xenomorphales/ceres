#include "gp2.h"

#include "periph/adc.h"

int gp2_init(void) {
  adc_init(0);
  adc_init(1);
  adc_init(2);
  adc_init(3);
  return 0;
}

int gp2_value(int gp2) {
  return adc_sample(gp2, ADC_RES_8BIT);
}
