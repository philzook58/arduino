
  int ledPin = 13; 
  
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:

 if (Serial.available()) {
    // read the most recent byte (which will be from 0 to 255):
    char val = (char) Serial.read();
    
    
    if(val == 'L'){
     digitalWrite(ledPin, HIGH);   // sets the LED on
      delay(1000);                  // waits for a second
      digitalWrite(ledPin, LOW); 
    }
    // set the brightness of the LED:
    //analogWrite(ledPin, brightness);
  }
}
