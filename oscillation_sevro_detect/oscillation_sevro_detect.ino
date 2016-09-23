
#include <Servo.h>


float amp = 10;
int val;
int oldval;
Servo myservo; 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);
  oldval = analogRead(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(0);
  myservo.write(90 +  int(amp*sin(t)));
  Serial.print(cos(t) * );
  t += 0.1;
  
  delay(100);
 
}
