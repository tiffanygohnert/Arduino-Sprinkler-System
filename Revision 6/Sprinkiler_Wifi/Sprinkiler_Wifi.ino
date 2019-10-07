/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com
  Code Update Feb. 12, 2016 David Connolly
*********/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

MDNSResponder mdns;

//Prepare String Data
  char Zone1on[] = "Z1on"; //Zone1 String data
  char Zone2on[] = "Z2on"; //Zone2 String data
  char Zone3on[] = "Z3on"; //Zone3 String data
  char Zone4on[] = "Z4on"; //Zone4 String data
  char Zone5on[] = "Z5on"; //Zone5 String data

  char Zone1off[] = "Z1off"; //Zone1 String data
  char Zone2off[] = "Z2off"; //Zone2 String data
  char Zone3off[] = "Z3off"; //Zone3 String data
  char Zone4off[] = "Z4off"; //Zone4 String data
  char Zone5off[] = "Z5off"; //Zone5 String data


// Replace with your network credentials
  const char* ssid = "Ninja";
  const char* password = "GOhnert2014";
  int gpio0Pin = 0;
  int gpio2Pin = 2;

ESP8266WebServer server(80);

String webPage = "";

void setup(void) {

  webPage += "<h1>1905 E Heather Oaks Web Server</h1><p>Zone #1 <a href=\"socket1On\"><button>ON</button></a>&nbsp;<a href=\"socket1Off\"><button>OFF</button></a></p>";
  webPage += "<p>Zone #2 <a href=\"socket2On\"><button>ON</button></a>&nbsp;<a href=\"socket2Off\"><button>OFF</button></a></p>";
  webPage += "<p>Zone #3 <a href=\"socket3On\"><button>ON</button></a>&nbsp;<a href=\"socket3Off\"><button>OFF</button></a></p>";
  webPage += "<p>Zone #4 <a href=\"socket4On\"><button>ON</button></a>&nbsp;<a href=\"socket4Off\"><button>OFF</button></a></p>";
  webPage += "<p>All Zones <a href=\"socket5On\"><button>ON</button></a>&nbsp;<a href=\"socket5Off\"><button>OFF</button></a></p>";

  // preparing GPIOs
  pinMode(gpio0Pin, OUTPUT);
  pinMode(gpio2Pin, OUTPUT);
  digitalWrite(gpio0Pin, LOW);
  digitalWrite(gpio2Pin, LOW);

  delay(1000);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  

  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  server.on("/", []() {
   server.send(200, "text/html", webPage);
  });
  
  server.on("/socket1Off", []() {
  server.send(200, "text/html", webPage);
  Serial.write(Zone1off,50); //Write the serial data
  delay(1000);
   
  });
  server.on("/socket2On", []() {
    server.send(200, "text/html", webPage);
    Serial.write(Zone2on,50); //Write the serial data
    delay(1000);
  });
  server.on("/socket2Off", []() {
  server.send(200, "text/html", webPage);
  Serial.write(Zone2off,50); //Write the serial data
  delay(1000);
    
  });
   server.on("/socket3On", []() {
    server.send(200, "text/html", webPage);
    Serial.write(Zone3on,50); //Write the serial data
    delay(1000);
  });
  server.on("/socket3Off", []() {
    server.send(200, "text/html", webPage);
    Serial.write(Zone3off,50); //Write the serial data
    delay(1000);
  });
  
  server.on("/socket4On", []() {
    server.send(200, "text/html", webPage);
    Serial.write(Zone4on,50); //Write the serial data
    delay(1000);
  });
  server.on("/socket4Off", []() {
    server.send(200, "text/html", webPage);
    Serial.write(Zone4off,50); //Write the serial data
    delay(1000);
  });
  server.on("/socket5On", []() {
    server.send(200, "text/html", webPage);
    Serial.write(Zone5on,50); //Write the serial data
    delay(1000);
  });
  server.on("/socket5Off", []() {
    server.send(200, "text/html", webPage);
   Serial.write(Zone5off,50); //Write the serial data
    delay(1000);
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
server.on("/socket1On", []() {
    server.send(200, "text/html", webPage);
    Serial.write(Zone1on,50); //Write the serial data
  delay(1000);
     
  });
  
}
