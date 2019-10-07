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
  Serial.begin(115200);
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
  server.on("/socket1On", []() {
    server.send(200, "text/html", webPage);
     digitalWrite(gpio0Pin, LOW);
     digitalWrite(gpio2Pin, LOW);
     digitalWrite(gpio0Pin, HIGH);
     digitalWrite(gpio2Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
     delay(3000);
     digitalWrite(gpio2Pin, LOW);
     
  });
  server.on("/socket1Off", []() {
 server.send(200, "text/html", webPage);
    digitalWrite(gpio0Pin, LOW);
     digitalWrite(gpio2Pin, LOW);    
    digitalWrite(gpio0Pin, LOW);
    digitalWrite(gpio2Pin, HIGH);
    delay(500);
    digitalWrite(gpio2Pin, LOW);
    delay(1000);
  });
  server.on("/socket2On", []() {
    server.send(200, "text/html", webPage);
   digitalWrite(gpio0Pin, LOW);
    digitalWrite(gpio2Pin, LOW);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio2Pin, HIGH);
    delay(3000);
     digitalWrite(gpio2Pin, LOW);
  });
  server.on("/socket2Off", []() {
  server.send(200, "text/html", webPage);
    digitalWrite(gpio0Pin, LOW);
     digitalWrite(gpio2Pin, LOW);
    digitalWrite(gpio0Pin, LOW);
    digitalWrite(gpio2Pin, HIGH);
    delay(500);
    digitalWrite(gpio2Pin, LOW);
    delay(1000);
    
  });
   server.on("/socket3On", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(gpio0Pin, LOW);
     digitalWrite(gpio2Pin, LOW);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
     digitalWrite(gpio2Pin, HIGH);
    delay(3000);
     digitalWrite(gpio2Pin, LOW);
  });
  server.on("/socket3Off", []() {
  server.send(200, "text/html", webPage);
    digitalWrite(gpio0Pin, LOW);
     digitalWrite(gpio2Pin, LOW);
    digitalWrite(gpio0Pin, LOW);
    digitalWrite(gpio2Pin, HIGH);
    delay(500);
    digitalWrite(gpio2Pin, LOW);
    delay(1000);
  });
  
  server.on("/socket4On", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(gpio0Pin, LOW);
     digitalWrite(gpio2Pin, LOW);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio2Pin, HIGH);
    delay(3000);
     digitalWrite(gpio2Pin, LOW);
  });
  server.on("/socket4Off", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(gpio0Pin, LOW);
     digitalWrite(gpio2Pin, LOW);
    digitalWrite(gpio0Pin, LOW);
    digitalWrite(gpio2Pin, HIGH);
    delay(500);
    digitalWrite(gpio2Pin, LOW);
    delay(1000);
  });
  server.on("/socket5On", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(gpio0Pin, LOW);
     digitalWrite(gpio2Pin, LOW);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
     digitalWrite(gpio0Pin, HIGH);
    delay(100);
    digitalWrite(gpio0Pin, LOW);
    delay(500);
    digitalWrite(gpio2Pin, HIGH);
    delay(100);
     //digitalWrite(gpio2Pin, LOW);
  });
  server.on("/socket5Off", []() {
    server.send(200, "text/html", webPage);
    digitalWrite(gpio0Pin, LOW);
     digitalWrite(gpio2Pin, LOW);
    digitalWrite(gpio0Pin, LOW);
    digitalWrite(gpio2Pin, HIGH);
    delay(500);
    digitalWrite(gpio2Pin, LOW);
    delay(1000);
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
}
