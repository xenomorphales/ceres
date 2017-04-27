#include <stdio.h>
#include <math.h>

#include "motors.h"
#include "gyro.h"

#include "feetech.h"
#include "dynamixel.h"

#define MOVE (0)
#define ARM (!MOVE)

#if ARM
uint16_t state[3][5] = {
  {256,  80, 512, 270, 130}, // RETRACTED
  {512, 512, 512, 270, 130}, // DEPLOYED MIDDLE
  {512, 512, 100, 270, 130}, // DEPLOYED DOWN
};

uint16_t state2[3][5] = {
  {256,  80, 512, 270, 150}, // RETRACTED
  {512, 512, 512, 270, 150}, // DEPLOYED MIDDLE
  {512, 512, 100, 270, 150}, // DEPLOYED DOWN
};
#endif

int main(void) {
#if ARM
  uint8_t buffer[64];
  uart_half_duplex_t stream;
  
  uart_half_duplex_params_t params = {
    .uart = UART_DEV(1),
    .baudrate = 1000000,
    .dir = UART_HALF_DUPLEX_DIR_NONE,
  };
  
  int ret = uart_half_duplex_init(&stream, buffer, sizeof(buffer), &params);
  if(ret != UART_HALF_DUPLEX_OK) {
    puts("ERROR uart_half_duplex_init");
  }

  size_t curstate = 0;
  
  while(1) {
    char c = getchar();
    getchar();

    switch(c){
    case '0':
      if(curstate != 2){
	curstate = 0;
      };
      break;
    case '1':
      curstate = 1;
      break;
    case '2':
      if(curstate != 0){
	curstate = 2;
      };
      break;
    }

    printf("char : %c\n", c);
    printf("state : %i\n", curstate);
    
    for(int i = 10 ; i < 15 ; i++) {
      feetech_t dev;
      feetech_init(&dev, &stream, i);
      
      feetech_write8(&dev, SCS15_TORQUE_ENABLE, 1);
      feetech_write16(&dev, SCS15_GOAL_TIME, 512);
      feetech_write16(&dev, SCS15_GOAL_POSITION, state[curstate][i-10]);
    }
    
    for(int i = 20 ; i < 25 ; i++) {
      feetech_t dev;
      feetech_init(&dev, &stream, i);
      
      feetech_write8(&dev, SCS15_TORQUE_ENABLE, 1);
      feetech_write16(&dev, SCS15_GOAL_TIME, 512);
      feetech_write16(&dev, SCS15_GOAL_POSITION, state2[curstate][i-20]);
    }
    
    for(int i = 15 ; i < 17 ; i++) {
      dynamixel_t dev;
      dynamixel_init(&dev, &stream, i);
    }
  }
#endif

#if MOVE
  printf("motors_init : %i\n", motors_init());
  printf("gyro_init : %i\n", gyro_init());

  while (1) {
    const int a = gyro_get_angle_deg();
    printf("angle: %6i\n", a);

    int cmd_a = 0;
    int err_a = cmd_a-a;

    int cmd_d = 80;
    int err_d = cmd_d;

    motors_set_left(err_d + err_a);
    motors_set_right(err_d - err_a);
  }
#endif

  return 0;
}
