#ifndef ARM_H
#define ARM_H

typedef enum {
  ARM_DISABLED,
  ARM_RETRACTED,
  ARM_DEPLOYED,
  ARM_MOVING,
  ARM_ERROR
} arm_state_t;

int arm_init(void);

void arm_left_deploy(void);
void arm_left_deploy_set_angles(float angle1, float angle2);
void arm_left_retract(void);
arm_state_t arm_left_state(void);

void arm_right_deploy(void);
void arm_right_deploy_set_angles(float angle1, float angle2);
void arm_right_retract(void);
arm_state_t arm_right_state(void);

#endif//ARM_H
