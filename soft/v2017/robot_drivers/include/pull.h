#ifndef PULL_H
#define PULL_H

#ifdef __cplusplus
extern "C" {
#endif

enum {
  PULL_IN,
  PULL_OUT
};

int pull_init(void);
int pull_state(void);

#ifdef __cplusplus
}
#endif

#endif//PULL_H
