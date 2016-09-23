void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(Serial.available() <= 0){}
  digitalWrite(13, HIGH); 
  Serial.read();
  while(Serial.available() <= 0){}
    Serial.read();
Serial.write("yo"); 
  digitalWrite(13, LOW); 

}
