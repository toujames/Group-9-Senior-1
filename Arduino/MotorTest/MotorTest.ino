#include <Servo.h>

Servo myservo;


void setSpeed(int speed){
  // speed is from 54 to 100, where 53 is off and 100 is maximum
  // 54 speed is the slowest. Found from testing
  // the following maps speed values of 0-100 to angles from 0-180,
  int angle = map(speed, 0, 100, 0, 180);

  // New Mapping for Motor Control
  myservo.write(angle); 
}

void arm(){
  // arm the speed controller, modify as necessary for your ESC 
  setSpeed(0); 
  delay(2000);
}

void setup()
{

  myservo.attach(9);
  arm();
  delay(2000);
}

void loop()
{

  setSpeed(54);

}#include <Servo.h>

Servo myservo;


void setSpeed(int speed){
  // speed is from 54 to 100, where 53 is off and 100 is maximum
  // 54 speed is the slowest. Found from testing
  // the following maps speed values of 0-100 to angles from 0-180,
  int angle = map(speed, 0, 100, 0, 180);

  // New Mapping for Motor Control
  myservo.write(angle); 
}

void arm(){
  // arm the speed controller, modify as necessary for your ESC 
  setSpeed(0); 
  delay(2000);
}

void setup()
{

  myservo.attach(9);
  arm();
  delay(2000);
}

void loop()
{

  setSpeed(54);

}
