#include <Wire.h>
#include <Servo.h>
#include "Adafruit_TCS34725.h"

Servo leftMotor;
Servo rightMotor;

//Minimum possible speed is ~54
void setSpeedLeft(int speed){
  // speed is from 54 to 100, where 53 is off and 100 is maximum
  // 54 speed is the slowest. Found from testing
  // the following maps speed values of 0-100 to angles from 0-180,
  int angle = map(speed, 0, 100, 0, 180);

  // New Mapping for Motor Control
  leftMotor.write(angle);
}

void setSpeedRight(int speed){
  // speed is from 54 to 100, where 53 is off and 100 is maximum
  // 54 speed is the slowest. Found from testing
  // the following maps speed values of 0-100 to angles from 0-180,
  int angle = map(speed, 0, 100, 0, 180);

  // New Mapping for Motor Control
  rightMotor.write(angle);
}
void arm(){
  // arm the speed controller, modify as necessary for your ESC 
  stopMotors();
  delay(2000);
}

void moveForward(int forward)
{
  setSpeedLeft(forward);
  setSpeedRight(forward);
}

void stopMotors()
{
  setSpeedLeft(0);
  setSpeedRight(0);
}

void turnLeft(int right)
{
  setSpeedLeft(0);
  setSpeedRight(right);
}

void turnRight(int left)
{
  setSpeedLeft(left);
  setSpeedRight(0);
}


/* Example code for the Adafruit TCS34725 breakout library */

/* Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */
   
/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcsLeft = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 tcsRight = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_1X);


void setup(void) {
  
  Serial.begin(9600);

  /*
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
  */
  
  leftMotor.attach(9);
  rightMotor.attach(10);
  arm();
  //delay(2000);
  
}

// return true if sensor is activated
bool isOn(uint16_t r, uint16_t g, uint16_t b) {
  if ((r >= 10) && (g >= 10) && (b >= 10))
  {
      return true;
  }
  else
  {
      return false;
  }
}


void loop(void) {
  uint16_t rL, gL, bL, cL;
  uint16_t rR, gR, bR, cR;
  
  tcsLeft.getRawData(&rL, &gL, &bL, &cL);
  tcsRight.getRawData(&rR, &gR, &bR, &cR);
  
  // colorTemp = tcs.calculateColorTemperature(r, g, b);
  //lux = tcs.calculateLux(r, g, b);
  
  // red: 959 - 981
  // green: 896 - 921
  // blue: 744 - 770
 
  /*
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
  */

  bool leftSensor = isOn(rL,gL,bL);
  bool rightSensor = isOn(rR,gR,bR);

  /*
  Follows the Truth table
  L | R | Function
  ------------------
  0 | 0 | stop();
  0 | 1 | moveRight();
  1 | 0 | moveLeft();
  1 | 1 | moveForward();
  */
  
  if(leftSensor || rightSensor){
    moveForward(5);
  }else if (leftSensor || !rightSensor){
    turnLeft(5);
  }else if (!leftSensor || rightSensor){
    turnRight(5);
  } else {
    stopMotors();
  }
  
}

