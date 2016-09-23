#include <Servo.h>

Servo myservo;  // create servo object to control a servo


void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
   if (Serial.available()) {
    // read the most recent byte (which will be from 0 to 255):
    String val = Serial.readString();
    myservo.write(val.toInt());
    // set the brightness of the LED:
    //analogWrite(ledPin, brightness);
  }

}
