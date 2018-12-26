#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char *ssid = "Amit’s iPhone";
const char *password = "test1234";

void setup() {

  Serial.begin(115200);

  Serial.println("welcome to my web server");
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(" . ");
  }

  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
