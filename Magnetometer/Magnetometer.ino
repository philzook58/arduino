
const int analogInPin = A5;  // Analog input pin that the potentiometer is attached to
 
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
 
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}
 
void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
  // 1.3mV/G * 2500mV full range = 3250
  outputValue = map(sensorValue, 0, 1023, -3250, 3250);  
  
  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t B Field = ");      
  Serial.println(outputValue);   
 
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(200);                     
}
