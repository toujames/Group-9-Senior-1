#include <SoftwareServo.h>

//SoftwareServo myservo;
SoftwareServo myservo;

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
}

void loop()
{
   myservo.write(100);
   
//   setSpeed(54);

/**  for (int i=0; i<37; i++)
    {
      setSpeed(i*5);
      delay(800);
    }
**/  
}
