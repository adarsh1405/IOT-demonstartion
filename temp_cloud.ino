#include<ESP8266WiFi.h>;
#include<WiFiClient.h>;
#include<ThingSpeak.h>;
const char *ssid ="vivo 1723";
const char *password="qwerty123";
int val;
int LDRpin=A0;
WiFiClient client;
unsigned long myChannelNumber=901192;
const char *myWriteAPIKEY="WWSCV2P903ZR9DTO";
void setup() {
Serial.begin(9600);
delay(10);
WiFi.begin(ssid,password);
ThingSpeak.begin(client);
  // put your setup code here, to run once:
}
void loop() {
val=analogRead(LDRpin);
Serial.println(val);
delay(1000);
ThingSpeak.writeField(myChannelNumber,1,val,myWriteAPIKEY);
delay(100); 
  // put your main code here, to run repeatedly:
}
