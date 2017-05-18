#ifndef LOCATOR_H
#define LOCATOR_H

#ifdef __cplusplus
extern "C" {
#endif

int locator_init(void);

float locator_get_x(void);
float locator_get_y(void);

void locator_reset(float x, float y, float angle);

#ifdef __cplusplus
}
#endif

#endif//LOCATOR_H
