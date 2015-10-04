#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>

#define SSID "Weed!"                                  // insert your SSID
#define PASS "nofreewifi@10"                                   // insert your password

ESP8266WebServer server(80);

void setup(){
	Serial.begin(115200);
	Serial.println("hello");
    
}

void loop()
{
	 //server.handleClient();                                  //check for messages from client
}
