#include<ESP8266WiFi.h>;
#include<WiFiClient.h>;
#include<ThingSpeak.h>;
const char *ssid ="vivo 1723";
const char *password="qwerty123";
WiFiClient client;
int val;
int LDRpin=A0;
unsigned long myChannelNumber=901286;
const char *myWriteAPIKEY="SKRDQWVBENQ1AKSL";
float vref=3.3;
float resolution=vref/1023;

void setup() {
Serial.begin(9600); // put your setup code here, to run once:
delay(10);
WiFi.begin(ssid,password);
ThingSpeak.begin(client);
}

void loop() {
  float temperature=analogRead(LDRpin);
  temperature={temperature*resolution};
  temperature*=100;
  Serial.print("temperature=");
  Serial.println(temperature);
  delay(1000);// put your main code here, to run repeatedly:
  ThingSpeak.writeField(myChannelNumber,1,val,myWriteAPIKEY);
  delay(100); 
}
