#include <SoftwareSerial.h>
SoftwareSerial gsmSerial(8,7);

int MyValue1;
void setup() 
{

  gsmSerial.begin(9600);
  Serial.begin(9600);
  

}

void loop() 
{

  MyValue1= random(50,500);
  

  Connect2Server();
  Field1(MyValue1);
  EndConnection();
 

}

void Connect2Server()
{
 
  gsmSerial.println("AT");
  delay(1000);
 
  gsmSerial.println("AT+CPIN?");
  delay(1000);
 
  gsmSerial.println("AT+CREG?");
  delay(1000);
 
  gsmSerial.println("AT+CGATT?");
  delay(1000);
 
  gsmSerial.println("AT+CIPSHUT");
  delay(1000);
 
  gsmSerial.println("AT+CIPSTATUS");
  delay(2000);
 
  gsmSerial.println("AT+CIPMUX=0");
  delay(2000);
 
  ShowSerialData();
 
  gsmSerial.println("AT+CSTT=\"airtelgsm.com\"");//start task and setting the APN,
  delay(1000);
 
  ShowSerialData();
 
  gsmSerial.println("AT+CIICR");//bring up wireless connection
  delay(3000);
 
  ShowSerialData();
 
  gsmSerial.println("AT+CIFSR");//get local IP adress
  delay(2000);
 
  ShowSerialData();
 
  gsmSerial.println("AT+CIPSPRT=0");
  delay(3000);
 
  ShowSerialData();
  
  gsmSerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  delay(6000);
 
  ShowSerialData();
 
  gsmSerial.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();


}

void Field1(int data)
{

  String str="GET <api_keyof_thingspeak>" + String(data);
  gsmSerial.println(str);
  delay(2000);
  ShowSerialData();
  gsmSerial.println((char)26);
  delay(4000);
  gsmSerial.println();

  ShowSerialData(); 

}

void EndConnection()
{

  gsmSerial.println("AT+CIPSHUT");
  delay(100);
  ShowSerialData();

}

void ShowSerialData()
{

  while (gsmSerial.available()!=0)
  Serial.write(gsmSerial.read());
  

  
}
