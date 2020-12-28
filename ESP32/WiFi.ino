#include "WiFi.h"

const char* ssid = "Aditya-ESP";
const char* Password = "Aditya";

// ngrok for globa testing

WiFiServer server(80);
String html ="<!DOCTYPE html>\
<html>\
<body>\
<form>\
<button name=\"LED\" button value=\"ON\" type=\"submit\">LED ON</button> \
<button name=\"LED\" button value=\"OFF\" type=\"submit\">LED OFF</button> \
</form> \
</body \
</html>";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  WiFi.softAP(ssid, Password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP Address: ");
  Serial.print(IP);
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  if(client)
  {
    String request = client.readStringUntil('\r');
    if (request.indexOf("LED=ON")>=0)digitalWrite(2, HIGH);
    if (request.indexOf("LED=OFF")>=0)digitalWrite(2, LOW);
    client.print(html);
    request="";
  }
  
}
