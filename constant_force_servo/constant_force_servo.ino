
int threshold = 300;

#include <Servo.h>
#include <PID_v1.h>


#define PIN_INPUT 0

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);


Servo myservo; 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  myPID.SetOutputLimits(0, 180);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //myservo.write(val);
  Input = analogRead(PIN_INPUT)
  if(Input < 300){
    myPID.SetMode(MANUAL);
  }
  else{
    myPID.SetMode(AUTOMATIC);
  }
  
  myPID.Compute();
  myservo.write(val) 
}
  
  
