#ifndef LOCATOR_H
#define LOCATOR_H

int locator_init(void);

float locator_get_x(void);
float locator_get_y(void);

void locator_reset(float x, float y, float angle);

#endif//LOCATOR_H
