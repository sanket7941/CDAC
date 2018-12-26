/*  IP:port/redled?state=on */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char *ssid = "Amit’s iPhone"; //WiFi name
const char *password = "test1234";  // Wifi password

// create the web server process
// and make it listen on port 80
ESP8266WebServer server(80);

void handleRoot() {
  Serial.println("Request is received for /");

  // send hello message
  server.send(200, "text/plain", "Hello client");
}

void handleRedLEDOn() {
  Serial.println("Request is received for /redled");
  digitalWrite(16, HIGH);

  server.send(200, "text/html", "<h1>RED LED turned ON</h1>");
}

void handleRedLEDOff() {
  Serial.println("Request is received for /redled");
  digitalWrite(16, LOW);

  server.send(200, "text/html", "<h1>RED LED turned OFF</h1>");
}

void setup() {
  Serial.begin(115200);

  pinMode(16, OUTPUT);

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
  server.on("/redled/on", handleRedLEDOn);
  server.on("/redled/off", handleRedLEDOff);

  server.begin();

  Serial.println("Server started listening on port 80");
}

void loop() {
  server.handleClient();
}
