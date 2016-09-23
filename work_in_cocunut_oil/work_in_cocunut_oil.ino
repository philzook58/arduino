#include <Servo.h>


Servo myservo;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(30);
  delay(1000);
  myservo.write(100);
  delay(1000);
}
