#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "FS.h"

#define NB_TRYWIFI        10    // Nbr de tentatives de connexion au réseau WiFi - Number of try to connect to WiFi network
#define DELAY_NEXT_EVENT  60    // délai entre deux événements en secondes - delay before new event in second 
#define DEEP_SLEEP        false
const char* ssid = "Ninja";
const char* password = "GOhnert2014";

WiFiClient espClient;
WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

int lastEvent;
int start = millis();
long int _now = 0;

bool loadLastEvent(){
  File f = SPIFFS.open("/lastEvent.txt", "r");
  if (!f) {
    Serial.println("Failed to open file");
    return false;
  }
  lastEvent = f.readStringUntil('\n').toInt();
  return true;
}

bool saveLastEvent(){
  File f = SPIFFS.open("/lastEvent.txt", "w");
  if (!f) {
      Serial.println("file open failed");
      return false;
  }
  f.println(_now);
  f.close();
  return true;
}

long int timeSpent(){
  loadLastEvent();
  timeClient.forceUpdate();
  _now = timeClient.getEpochTime();
  int timeSpent = _now - lastEvent;
  Serial.println("Time spent since last alarm (s): ");Serial.print(timeSpent);
  return timeSpent;
}
void runEvent(){
    
  if ( timeSpent() >= DELAY_NEXT_EVENT ) {
    Serial.println("RUN EVENT");
    saveLastEvent();
  } 
}

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.print("Startup reason:");Serial.println(ESP.getResetReason());

  SPIFFS.begin();

  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi.");
  int _try = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("..");
    delay(500);
    _try++;
    if ( _try >= NB_TRYWIFI ) {
        Serial.println("Impossible to connect WiFi network, go to deep sleep");
        ESP.deepSleep(10e6);
    }
  }
  Serial.println("Connected to the WiFi network");
  
  // Démarrage du client NTP - Start NTP client
  timeClient.begin();
   
  
  if ( DEEP_SLEEP){ 
    runEvent();
    Serial.println("Go to deep sleep");
    ESP.deepSleep(10e6);
  }  
}

void loop() {
  if ( !DEEP_SLEEP ){
    timeClient.update();
    Serial.println(timeClient.getFormattedTime());
    delay(10000); 
  }
}
