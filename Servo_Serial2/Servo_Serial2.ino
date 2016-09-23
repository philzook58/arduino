#include <Servo.h>

Servo servoA, servoB;  // create servo object to control a servo


void setup()
{
  servoA.attach(9);
servoB.attach(10);  // attaches the servo on pin 9 to the servo object
    Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  
  
      if ( Serial.available()) {
    char ch = Serial.read();
    
    switch(ch) {
    case '0'...'9':
    //Pretty goddamn clever right here. Not mine.
    v = v * 10 + ch - '0';
    break;
    case 'a':
    servoA.write(v);
    v = 0;
    break;
    case 'b':
    servoA.write(v);
    v = 0;
    break;
    }
    }

}
