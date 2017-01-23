#include "QuadDecode_def.h"

#define NB_LEDS 5
const int leds[] = { 11, 12, 13, 20, 21 };

#define NB_BUTTONS 4
const int buttons[] = { 5, 6, 7 , 8 };

const int startPull = 2;

#define NB_GP2S 4
const int gp2s[] = { 0, 1, 2, 3 };
#define GP2_BLOCK_AT   1000 /*432*/ /*288*/
#define GP2_UNBLOCK_AT 1000 /*324*/ /*216*/

#define NB_MOTORS 2
const int motorPWMs[] = { 22, 23 };
const int motorDirs[] = { 26, 31 };

QuadDecode<1> encoder1;  // Template using FTM1
QuadDecode<2> encoder2;  // Template using FTM2

#define SPEED 125

void display(int n) {
  for(int i = 0; i <= NB_LEDS; ++i)
    digitalWrite(leds[i], ((1<<i) & n) ? HIGH : LOW);
}

static long long lastE[2] = { 0, 0 };
static long long curE[2] = { 0, 0 };

void updateEnc() {
  lastE[0] = curE[0];
  lastE[1] = curE[1];

  curE[0] = -encoder2.calcPosn();
  curE[1] = encoder1.calcPosn();
}

static long long lastErr[2] = { 0, 0 };
static float pidSpeeds[2][3] = {
  //    P     I     D
  {   0.5,   0.,  0.5 }, // Droit
  {   0.5,   0.,  0.5 }, // Gauche
};

void updateMotor(int m, int speed) {
  long long actualSpeed = curE[m] - lastE[m];
  long long err = speed - actualSpeed;
  
  long long P = pidSpeeds[m][0] * err;
  long long I = 0;
  long long D = pidSpeeds[m][2] * (err - lastErr[m]);

  long long cmd = P + I + D;

  if(m == 0) cmd = -cmd;
  
  analogWrite(motorPWMs[m], (abs(cmd) > 255) ? 255 : abs(cmd));
  digitalWrite(motorDirs[m], (cmd >= 0) ? HIGH : LOW);
  
  lastErr[m] = err;
}

long long lastErrAngle = 0;
static float pidAngle[3] = {
  //    P     I     D
      0.5,   0.,  0.5,
};

long long lastDistance = 0;
long long lastErrSpeed = 0;
static float pidSpeed[3] = {
  //    P     I     D
      0.5,   0.,  0.5,
};

void updateAngleSpeed(int angle, int speed) {
  long long actualAngle = (curE[1] - curE[0]) / 2;
  long long actualDistance = (curE[1] + curE[0]) / 2;

  long long errAngle = angle - actualAngle;

  long long PAngle = pidAngle[0] * errAngle;
  long long IAngle = 0;
  long long DAngle = pidAngle[2] * (errAngle - lastErrAngle);

  long long actualSpeed = lastDistance - actualDistance;

  long long errSpeed = speed - actualSpeed;

  long long PSpeed = pidSpeed[0] * errSpeed;
  long long ISpeed = 0;
  long long DSpeed = pidSpeed[2] * (errSpeed - lastErrSpeed);

  updateMotor(1, PSpeed + ISpeed + DSpeed + PAngle + IAngle + DAngle);
  updateMotor(0, PSpeed + ISpeed + DSpeed - PAngle - IAngle - DAngle);

  lastErrAngle = errAngle;
  lastDistance = actualDistance;
  lastErrSpeed = errSpeed;
}

void updateMotors(int speed) {
  updateMotor(0, speed);
  updateMotor(1, speed);
}

void setup() {
  // put your setup code here, to run once:
  delay(1000);

  for(int i = 0; i < NB_LEDS; ++i)
    pinMode(leds[i], OUTPUT);

  display(0x1F);

  for(int i = 0; i < NB_BUTTONS; ++i)
    pinMode(buttons[i], INPUT);

  pinMode(startPull, INPUT);

  for(int i = 0; i < NB_GP2S; ++i)
    pinMode(gp2s[i], INPUT);

  for(int i = 0; i < NB_MOTORS; ++i) {
    pinMode(motorPWMs[i], OUTPUT);
    pinMode(motorDirs[i], OUTPUT);
  }

  updateMotors(0);

  encoder1.setup();
  encoder2.setup();

  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  static int time = 0;
  static int step = 0;
  
  display(step);

  if(time >= 85000) {
    display(0x1F);
    while(1) {
      analogWrite(motorPWMs[0], 0);
      analogWrite(motorPWMs[1], 0);
    }
  }

  if(step == 0) {
    while(digitalRead(buttons[0]) == HIGH);
    step = 1;
  }
  else if(step == 1) {
    //while(digitalRead(buttons[1]) == HIGH);
    while(digitalRead(startPull) == LOW);
    time = 0;
    step = 2;
    encoder1.start();
    encoder2.start();
  }
  else if(step == 2) {
    int speed = SPEED;
    long long dist;
    static bool lastBlocked = false;
    int gp2Sum = 0;
    
    updateEnc();
    dist = curE[0] + curE[1];

    for(int i = 0; i < 2 && speed != 0; ++i)
      if(lastBlocked) {
        if(analogRead(gp2s[i]) <= GP2_UNBLOCK_AT)
          ++gp2Sum;
      }
      else {
        if(analogRead(gp2s[i]) >= GP2_BLOCK_AT)
          ++gp2Sum;
      }

    if(lastBlocked && gp2Sum < 2)
      speed = 0;
    else if(lastBlocked && gp2Sum == 2)
      lastBlocked = false;
    else if(!lastBlocked && gp2Sum > 0) {
      lastBlocked = true;
      speed = 0;
    }

    display(step | ((lastBlocked) ? 0b11000 : 0));
    
    //updateMotors(speed);
    updateAngleSpeed(0, speed);

    if(dist >= 1024*34)
      step = 3;
  }
  else if(step == 3) {
    updateEnc();
    updateMotors(0);
    if(time >= 80000)
      step = 4;
  }
  /*else if(step == 4) {
    // Toupie
    updateEnc();
    updateMotor(0, SPEED);
    updateMotor(1, -SPEED);
  }*/
  else {
    updateEnc();
    updateMotors(0);
  }
  
  delay(10);
  time += 10;
}

