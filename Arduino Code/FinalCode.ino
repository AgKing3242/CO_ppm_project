#include <Wire.h>
#include <SoftwareSerial.h>
#include <dht11.h>
#define DHT11PIN 4
#define RX 2
#define TX 3

float R0 = 8000.0;
float RL = 2000.0;
float RS;
float PPM_CO; 
String WIFI_SSID = "moto";
String WIFI_PASS = "12345678";
String API = "J9Z65PZG0BXLOLAS";
String HOST = "api.thingspeak.com";
String PORT = "80";
int countTrueCommand;
int countTimeCommand; 
boolean found = false;   

SoftwareSerial esp8266(RX,TX); 
dht11 DHT11;

void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  esp8266.begin(9600);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWJAP=\""+ WIFI_SSID +"\",\""+ WIFI_PASS +"\"",20,"OK");
}

void loop() {
  
 float raw_value=analogRead(A0);
 float voltage=raw_value*5.0;
 voltage=voltage/1023.0;
 RS=((5.0*RL)/voltage)-RL;
 PPM_CO = pow(10,(log10(RS/R0)-0.775)/(-0.324));
 int chk = DHT11.read(DHT11PIN);
 int temp=DHT11.temperature; 
 int hum=DHT11.humidity; 
 String getData="GET /update?api_key="+ API+"&field1="+temp+
 "&field2="+hum +"&field3="+PPM_CO+"&field4="+raw_value+"&field5="+RS/R0;
 sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 int dataLength = getData.length();
 int maxChunkSize = 120; 
 int numChunks = ceil(dataLength / (float)maxChunkSize);
  
  for (int i = 0; i < numChunks; i++) {
    int startIndex = i * maxChunkSize;
    int endIndex = min(startIndex + maxChunkSize, dataLength);
    String chunk = getData.substring(startIndex, endIndex);

    sendCommand("AT+CIPSEND=0," + String(chunk.length()+2), 4, ">");
    esp8266.println(chunk);
    delay(1000);
  }
 countTrueCommand++;
}
void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);
    if(esp8266.find(readReplay))
    {
      found = true;
      break;
    }
    countTimeCommand++;
  } 
  if(found == true)
  {
    Serial.println("OK");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  } 
  found = false;
 }
