#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(10);
  Serial.begin(57600);
  myservo.writeMicroseconds(1500);
    // set servo to mid-point
} 

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()==0){}
  int num=Serial.parseInt();
  myservo.writeMicroseconds(num);

}
