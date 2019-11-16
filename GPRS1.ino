//#include<SoftwareSerial.h>
//SoftwareSerial Serial(10,9);
String DeviceID="test";
unsigned int TimeStamp=10;
String url;
void setup() 
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.println("********************************* NILESH *************************");
  Serial1.println("Initializing......");
  delay(3000);
}

void loop() 
{
  // Check communication of GSM module
  Serial.println("AT");
  updateSerial();
  delay(1000);

  Serial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(2000);
  updateSerial();

  Serial.println("AT+SAPBR=3,1,\"APN\",\"ideanet\"");
  delay(2000);
  updateSerial();

  Serial.println("AT+SAPBR=1,1");
  delay(5000);
  updateSerial();
 // delay(2000);

  Serial.println("AT+SAPBR=2,1");
  delay(5000);
  updateSerial();
  

  Serial.println("AT+HTTPINIT");
  delay(2000);
 updateSerial();

  

//  Serial.print("AT+HTTPPARA=\"URL\",\"https://swajal.in/rmsprod/CupDispensing.php?\"");
  url="AT+HTTPPARA=\"URL\",\"swajal.in/rmsprod/CupDispensing.php?Data1=";
  url=url+DeviceID;
  url=url+"&Data2=";
  url=url+String(TimeStamp);
  url=url+"\"";
  Serial1.println(url);
  Serial.println(url);
  delay(500);
  updateSerial();
 // delay(50);
 /* Serial.print("Data1=");
  delay(50);
  updateSerial();
  Serial.print(DeviceID);
 // delay(50);
  updateSerial();
  Serial.print("&Data2=");
 // delay(50);
  updateSerial();
  Serial.print(TimeStamp);
 // delay(50);
  updateSerial();
  Serial.println("\"");
  updateSerial();*/
  delay(2000);
   
  Serial.println("AT+HTTPPARA=\"CID\",1");
  updateSerial();
  delay(2000);
 
  Serial.println("AT+HTTPACTION=0");
  delay(3000);
  updateSerial();

 
  Serial.println("AT+HTTPTERM");  /* Terminate HTTP service */
  delay(5000);
  updateSerial();
  delay(5000);
 
  Serial.println("AT+SAPBR=0,1"); /* Close GPRS context */
  delay(5000);
  updateSerial();
  delay(5000);
}

void updateSerial()
{
    delay(500);
 /* while (Serial1.available()) 
  {
    Serial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }*/
  while(Serial.available()) 
  {
    Serial1.write(Serial.read());//Forward what Software Serial received to Serial Port
  }
}
