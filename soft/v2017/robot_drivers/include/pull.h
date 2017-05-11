#ifndef PULL_H
#define PULL_H

enum {
  PULL_IN,
  PULL_OUT
};

int pull_init(void);
int pull_state(void);

#endif//PULL_H
