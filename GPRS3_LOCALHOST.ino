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

  mySerial.println("AT+SAPBR=3,1,\"APN\",\"internet\"");
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

  mySerial.println("AT+HTTPPARA=\"URL\",\"GET /info.php?request=hello\"");
  delay(2000);
  updateSerial();

/*  mySerial.println("AT+HTTPDATA=7,10000");
  delay(1000);
  updateSerial();

  mySerial.println("Data1=1");
  delay(3000);
  updateSerial();*/

  mySerial.println("AT+HTTPACTION=1");
  delay(3000);
  updateSerial();

  mySerial.println("AT+HTTPREAD");
  delay(1000);
  updateSerial();
  delay(2000);
 
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
