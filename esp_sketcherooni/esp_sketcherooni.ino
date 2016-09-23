#include <ArduinoJson.h>


#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); //RX TX


bool insidejson = false;
char json[50];
int jsonindex = 0;
void setup() {
  // put your setup code here, to run once:
  //mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
  Serial.println("AT+RST");
  delay(3000);
  Serial.println("AT+CWMODE=3");
  delay(100);
  Serial.println("AT+CWJAP=\"Fuck Mountain\",\"awwwwwwww yeahhhhhhhh\"" );
  //AT+CWJAP="Fuck Mountain","awwwwwwww yeahhhhhhhh"
  //Serial.println("ready");
  delay(1000);
  //mySerial.println("AT+CIFSR");
  //Serial.println("AT+CIPSTART=\"TCP\",\"45.55.243.197\",80");
  delay(100);
  initRequest();
  
}

void initRequest(){
  Serial.println("AT+CIPSTART=\"TCP\",\"45.55.243.197\",80");
  delay(100);
  Serial.println("AT+CIPSEND=26");
  Serial.println("GET /location HTTP/1.0");
  Serial.println("");
}

// 45.55.243.97
//AT+CIPSTART=4,"TCP","google.com",80 
//AT+CIPSTART="TCP","45.55.243.197",80

StaticJsonBuffer<200> jsonBuffer;

void processjson(){

  
JsonObject& root = jsonBuffer.parseObject(json);


double x    = root["x"];
double y   = root["y"];
Serial.println( x );
}

void loop() {
  // put your main code here, to run repeatedly:
/*
  while (mySerial.available())
    Serial.write(mySerial.read());
  while (Serial.available())
    mySerial.write(Serial.read());
    */
    
    if ( Serial.available()) {
    char ch = Serial.read();
    if( ch == '{'){
      insidejson = true;
    }
    if(insidejson){
      json[jsonindex]=ch;
      jsonindex++;
    }
    if( ch == '}'){
      insidejson = false;
      json[jsonindex]='\0';
      jsonindex=0;
      processjson();
      initRequest();
      
    }
    
    }
}
