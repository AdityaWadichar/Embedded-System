#include <WiFi.h>
#include <HTTPClient.h>


const char* ssid     = "Aditya Network";
const char* password = "987654321";

const char* serverName = "https://api.thingspeak.com/update";
String apiKey = "R20ZU3URLYZSHXDE";


WiFiServer server(80);

void setup(){
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    pinMode(4, INPUT);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

int touch;

void loop(){
 if(WiFi.status()== WL_CONNECTED){
  HTTPClient http;
  http.begin(serverName);
  int touch = touchRead(4);
  if(touch<20) digitalWrite(2, HIGH);
  else digitalWrite(2, LOW);
  
  String DataSent = "api_key=" + apiKey + "&field1=" + String(touch);
  int Response = http.POST(DataSent);
  Serial.print(touch);
  Serial.print(" Response: ");
  Serial.println(Response);
  http.end();
 }
}
