#include <stdio.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PWM 0
#define MAX_PWM 4095

//#define SDA 3
//#define SCL 0
// PWM channels of pca9685 0-16
#define PWM_CHANNEL1 8
#define PWM_CHANNEL2 9
#define PWM_CHANNEL3 10
#define PWM_CHANNEL4 11

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setPWMMotors(int c1, int c2, int c3, int c4)
{
  // setPWM(channel, on_duty_cycle, off_duty_cycle)
  Serial.print(c1);
  Serial.print("\t");
  Serial.print(c2);
  Serial.print("\t");
  Serial.print(c3);
  Serial.print("\t");
  Serial.print(c4);
  Serial.println();

  pwm.setPWM(PWM_CHANNEL1, c1, MAX_PWM - c1);
  pwm.setPWM(PWM_CHANNEL2, c2, MAX_PWM - c2);
  pwm.setPWM(PWM_CHANNEL3, c3, MAX_PWM - c3);
  pwm.setPWM(PWM_CHANNEL4, c4, MAX_PWM - c4);
}

void initMotors()
{
  Wire.begin(); //SDA, SCL,400000);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(1600);
  Wire.setClock(400000);

  setPWMMotors(0, 0, 0, 0);
}
void intline() {
  // cambientrai= 36;
  // cambienphai =39;
  // cambiengiua =32;
  pinMode(36, INPUT);
  pinMode(39, INPUT);
  pinMode(32, INPUT);

}
void linefollow() {
  Serial.println("Doline");
  int L = digitalRead(36);
  int R = digitalRead(39);
  int M = digitalRead(32);
  Serial.println(L);
  if ( L == 1 && M == 0 && R == 1) {
    pwm.setPWM(8, 0, 1600);
    pwm.setPWM(9, 0, 0);
    pwm.setPWM(10, 0, 1600);
    pwm.setPWM(11, 0, 0);
    Serial.print("\ntien");
  }
  else if ( L == 0 && R == 1) {
    pwm.setPWM(8, 0, 1600);
    pwm.setPWM(9, 0, 0);
    pwm.setPWM(10, 0, 0);
    pwm.setPWM(11, 0, 0);
    Serial.print("\ntrai");
  }
  else if ( L == 1  && R == 0) {
    pwm.setPWM(8, 0, 0);
    pwm.setPWM(9, 0, 0);
    pwm.setPWM(10, 0, 1600);
    pwm.setPWM(11, 0, 0);
    Serial.print("\nphai");
  }
  else {
    pwm.setPWM(8, 4096, 0);
    pwm.setPWM(9, 4096, 0);
    pwm.setPWM(11, 4096, 0);
    pwm.setPWM(10, 4096, 0);
  }
}
//void lui() {
//  pwm.setPWM(8, 0, tocdo);
//  pwm.setPWM(9, 255, 0);
//  pwm.setPWM(10, 0, tocdo);
//  pwm.setPWM(11, 255, 0);
//}
//void tien() {
//  pwm.setPWM(8, 0, 1600);
//  pwm.setPWM(9, 0, 0);
//  pwm.setPWM(10, 0, 1600);
//  pwm.setPWM(11, 0, 0);
//}
//void trai() {
//  pwm.setPWM(8, 0, 1600);
//  pwm.setPWM(9, 0, 0);
//  pwm.setPWM(10, 0, 0);
// pwm.setPWM(11, 0, 0);
//}
//void phai() {
// pwm.setPWM(8, 0, 0);
// pwm.setPWM(9, 0, 0);
//pwm.setPWM(10, 0, 1600);
//pwm.setPWM(11, 0, 0);
//}
// /**
//  * Set speed and direction for 2 motors
//  *
//  * @param left_motor_speed: speed with direction for left motor. Range from -1 to 1. 1: max speed forward, -1: max speed reverse
//  * @param right_motor_speed: speed with direction for right motor. Range from -1 to 1. 1: max speed forward, -1: max speed reverse
//  */
// void setSpeed(float left_motor_speed, float right_motor_speed) {

//   int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

//   if (left_motor_speed > 0) {
//     c1 = max(MIN_PWM, min(int(abs(left_motor_speed) * MAX_PWM), MAX_PWM));
//   } else {
//     c2 = max(MIN_PWM, min(int(abs(left_motor_speed) * MAX_PWM), MAX_PWM));
//   }

//   if (right_motor_speed > 0) {
//     c3 = max(MIN_PWM, min(int(abs(right_motor_speed) * MAX_PWM), MAX_PWM));
//   } else {
//     c4 = max(MIN_PWM, min(int(abs(right_motor_speed) * MAX_PWM), MAX_PWM));
//   }

//   setPWMMotors(c1, c2, c3, c4);
// }
