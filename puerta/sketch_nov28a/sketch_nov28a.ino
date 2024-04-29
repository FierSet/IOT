#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


#define echo D7
#define tring D6

const char* ssid = "sid";   //enter your wi-fi name
const char* password = "pass";    //enter the wifi password

const String serverName = "http://host";
int duracion;
int distancia;

unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;

int bufer = 0;

WiFiClient client;
void setup() 
{
  pinMode(echo,INPUT);
  pinMode(tring,OUTPUT);
  Serial.begin(9600);
  Serial.println("Inicio");
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
  Serial.print("my ip: ");
  Serial.println(WiFi.localIP());
  
}

void loop() 
{
  digitalWrite(tring,HIGH);
  delay(1);
  digitalWrite(tring,LOW);
  duracion = pulseIn(echo,HIGH);
  distancia = duracion/58.2;
  Serial.println(distancia);
  
  if(bufer != distancia)
  {
    Serial.println("cambio");
    bufer = distancia;
    subir();
  }
  
    delay(3000);
 }

 void subir()
 {
  if ((millis() - lastTime) > timerDelay) 
  {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;

      String serverPath = serverName + "";
      
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverPath.c_str());
  
      // If you need Node-RED/server authentication, insert user and password below
      //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
        
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else 
    {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
