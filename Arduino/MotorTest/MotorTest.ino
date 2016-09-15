#include <Servo.h> 

Servo myservo;

void arm(){
  // arm the speed controller, modify as necessary for your ESC 
  
  setSpeed(0); 
  delay(2000); //delay 1 second, some speed controllers may need longer
}

void setSpeed(int speed){
  // speed is from 54 to 100, where 53 is off and 100 is maximum
  // 54 speed is the slowest. Found form testing
  // the following maps speed values of 0-100 to angles from 0-180,
  int angle = map(speed, 0, 100, 0, 180);
  myservo.write(angle); 
}

void setup()
{
  myservo.attach(9);
  arm(); 
}
void loop()
{
  setSpeed(54); 
  delay(5000); // stop the motor for 5 seconds
}
