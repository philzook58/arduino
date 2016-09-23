//int speed1 = 0;
//int speed2 = 0;
//int dir1 = 1;
//int dir2 = 1;

int pwr = 8;
int gnd = 8;

int pwm1 =  3;
int dir1pin = 2;

void setup()
{
  // attaches the servo on pin 9 to the servo object
  digitalWrite(pwr, LOW);
  pinMode(pwr,OUTPUT);
  analogWrite(pwm1, 0); 
    Serial.begin(9600);
    pinMode(dir1pin, OUTPUT);
    digitalWrite(dir1pin, HIGH); 
     analogWrite(pwm1, 0);   
     digitalWrite(pwr, HIGH);
    
    
}


void loop() {
  // put your main code here, to run repeatedly:
   if (Serial.available()) {
    // read the most recent byte (which will be from 0 to 255):
    String val = Serial.readString();
    
   
    analogWrite(pwm1, val.toInt());
  }

}
