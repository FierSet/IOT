#include <ESP8266WiFi.h>

#define POT A0 // LED at GPIO4 D2

const char* ssid = "Note Ruben";   //enter your wi-fi name
const char* password = "dmgf4069";    //enter the wifi password


const char WEBSITE[] = "http://192.168.79.103/";

int potencia = 0;

void setup() 
{
  Serial.begin(115200);  
  // Connect to WiFi networ
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  Serial.print("Conecting");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() 
{
  potencia = analogRead(POT);
  potencia = map(potencia, 0, 1024, 0, 180);
  
  Serial.println(potencia);
  
  if(client.connect(WEBSITE,80))
  {
    client.print("GET /?value=" + (String)potencia);
    client.println(" HTTP/1.1");
    client.println("Host: ");
    client.println(WEBSITE);
    client.println("User-Agent: ESP8266/1.0");
    client.println("Connection: close");
    client.println();
  }
  delay(250);
  
}
