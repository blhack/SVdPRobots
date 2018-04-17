// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

int offset = 0;

int break_speed = 500;
int max_speed = 500;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor1.setSpeed(break_speed);
  motor2.setSpeed(break_speed);
 
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void forward(int howLong) {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(break_speed);
  motor2.setSpeed(break_speed);
  delay(50);
  motor1.setSpeed(max_speed);
  motor2.setSpeed(max_speed+offset);
  delay(howLong);
  }

void backward(int howLong) {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor1.setSpeed(break_speed);
  motor2.setSpeed(break_speed);
  delay(50);
  motor1.setSpeed(max_speed);
  motor2.setSpeed(max_speed+offset);
  delay(howLong); 
}

void left(int howLong) {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor1.setSpeed(break_speed);
  motor2.setSpeed(break_speed);
  delay(50);
  motor1.setSpeed(max_speed);
  motor2.setSpeed(max_speed+offset);
  delay(howLong); 
}

void right(int howLong) {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(break_speed);
  motor2.setSpeed(break_speed);
  delay(50);
  motor1.setSpeed(max_speed);
  motor2.setSpeed(max_speed+offset);
  delay(howLong); 
}

void doStop(int howLong) {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  delay(howLong);
}

void loop() {
  forward(5000);
  doStop(3000);
}
