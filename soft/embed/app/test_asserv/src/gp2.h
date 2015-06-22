#ifndef GP2_H
#define GP2_H

#include <stdint.h>

void gp2_init(void);

uint32_t gp2_get_lf(void);
uint32_t gp2_get_rf(void);
uint32_t gp2_get_lb(void);
uint32_t gp2_get_rb(void);

#endif//GP2_H
