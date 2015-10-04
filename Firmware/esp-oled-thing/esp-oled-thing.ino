#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>

#define SSID "xxxx"                                  // insert your SSID
#define PASS "xxxxx"                                   // insert your password

ESP8266WebServer server(80);

String form =
  "<p>"
  "<center>"
  "<h1>Hello World!</h1>"
  "</center>";

void setup(){
	Serial.begin(115200);
	Serial.println("hello");
	
	while (WiFi.status() != WL_CONNECTED) {         // Wait for connection
		delay(500);
		Serial.print(".");
	}
	// Set up the endpoints for HTTP server,  Endpoints can be written as inline functions:
	server.on("/", []() {
		server.send(200, "text/html", form);
	});
	
	server.on("/msg", handle_msg);                  // And as regular external functions:
	server.begin();

	Serial.print("SSID : ");                        // prints SSID in monitor
	Serial.println(SSID);                           // to monitor          

	char result[16];
	sprintf(result, "%3d.%3d.%3d.%3d", WiFi.localIP()[0], WiFi.localIP()[1], WiFi.localIP()[2], WiFi.localIP()[3]);
	Serial.println();Serial.println(result);
    
}

void loop()
{
	server.handleClient();                                  //check for messages from client
}


void handle_msg() {
 
  server.send(200, "text/html", form);    // Send same page so they can send another msg

  // Display msg on Oled
  String msg = server.arg("msg");
  Serial.println(msg);
  String decodedMsg = msg;
  // Restore special characters that are misformed to %char by the client browser
  decodedMsg.replace("+", " ");      
  decodedMsg.replace("%21", "!");  
  decodedMsg.replace("%22", "");  
  decodedMsg.replace("%23", "#");
  decodedMsg.replace("%24", "$");
  decodedMsg.replace("%25", "%");  
  decodedMsg.replace("%26", "&");
  decodedMsg.replace("%27", "'");  
  decodedMsg.replace("%28", "(");
  decodedMsg.replace("%29", ")");
  decodedMsg.replace("%2A", "*");
  decodedMsg.replace("%2B", "+");  
  decodedMsg.replace("%2C", ",");  
  decodedMsg.replace("%2F", "/");   
  decodedMsg.replace("%3A", ":");    
  decodedMsg.replace("%3B", ";");  
  decodedMsg.replace("%3C", "<");  
  decodedMsg.replace("%3D", "=");  
  decodedMsg.replace("%3E", ">");
  decodedMsg.replace("%3F", "?");  
  decodedMsg.replace("%40", "@"); 
}
