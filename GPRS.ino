#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,9);

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("********************************* NILESH *************************");
  Serial.println("Initializing......");
  delay(3000);
}

void loop() 
{
  // Check communication of GSM module
  mySerial.println("AT");
  updateSerial();
  delay(1000);

  mySerial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(2000);
  updateSerial();

  mySerial.println("AT+SAPBR=3,1,\"APN\",\"airtelnet\"");
  delay(2000);
  updateSerial();

  mySerial.println("AT+SAPBR=1,1");
  delay(5000);
  updateSerial();
  delay(2000);

  mySerial.println("AT+SAPBR=2,1");
  delay(5000);
  updateSerial();
  

  mySerial.println("AT+HTTPINIT");
  delay(2000);
  updateSerial();

  mySerial.println("AT+HTTPPARA=\"CID\",1");
  delay(2000);
  updateSerial();

  mySerial.println("AT+HTTPPARA=\"URL\",\"api.thingspeak.com/update\"");
  delay(2000);
  updateSerial();

  mySerial.println("AT+HTTPDATA=40,10000");
  delay(2000);
  updateSerial();

  mySerial.println("api_key=IB6KJ0OQ0NEZ6KD4&field1=nileshvy");
  delay(3000);
  updateSerial();

  mySerial.println("AT+HTTPACTION=1");
  delay(3000);
  updateSerial();

 
  mySerial.println("AT+HTTPTERM");  /* Terminate HTTP service */
  delay(5000);
  updateSerial();
  delay(5000);
 
  mySerial.println("AT+SAPBR=0,1"); /* Close GPRS context */
  delay(5000);
  updateSerial();
  delay(5000);
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
