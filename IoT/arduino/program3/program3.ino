#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char *ssid = "Amit’s iPhone";
const char *password = "test1234";

// create the web server process
// and make it listen on port 80
ESP8266WebServer server(80);

void handleRoot() {
  Serial.println("Request is received for /");

  // send hello message
  server.send(200, "text/plain", "Hello client");
}

void setup() {
  Serial.begin(115200);

  Serial.println("welcome to my web server");
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(" . ");
  }
  
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  
  Serial.println("Server started listening on port 80");
}

void loop() {
  server.handleClient();

}
