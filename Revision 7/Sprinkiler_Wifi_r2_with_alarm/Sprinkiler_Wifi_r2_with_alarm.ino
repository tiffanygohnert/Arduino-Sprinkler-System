// Load library

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>


// Replace with your network credentials
const char* ssid     = "Ninja";
const char* password = "GOhnert2014";

const long utcOffsetInSeconds = -21600;

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state

String Zone1State = "off";
String Zone2State = "off";
String Zone3State = "off";
String Zone4State = "off";
String AllZoneState = "off";

char AllZoneon[6] = "i"; //String data
char AllZoneoff[6] = "j"; //String data
char Zone1on[6] = "a"; //String data
char Zone1off[6] = "b"; //String data
char Zone2on[6] = "c"; //String data
char Zone2off[6] = "d"; //String data
char Zone3on[6] = "e"; //String data
char Zone3off[6] = "f"; //String data
char Zone4on[6] = "g"; //String data
char Zone4off[6]= "h"; //String data

// Assign output variables to GPIO pins

  int gpio0Pin = 0; 
  int gpio2Pin = 2; 

// Define NTP Client to get time

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
int TimeHours = 0;
int TimeMinutes = 0; 
int TimeSeconds = 0;



char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; 


void setup() {

  
  Serial.begin(9600);
  // Initialize the output variables as outputs
  
  pinMode(gpio0Pin, OUTPUT);
  pinMode(gpio2Pin, OUTPUT);

  
  // Set outputs to LOW
  
  digitalWrite(gpio0Pin, LOW);
  digitalWrite(gpio2Pin, LOW);


  // Connect to Wi-Fi network with SSID and password
 // Serial.print("Connecting to ");
 // Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }
  // Print local IP address and start web server
 // Serial.println("");
 // Serial.println("WiFi connected.");
 // Serial.println("IP address: ");
  //Serial.println(WiFi.localIP());
  server.begin();

// Clock and alarm setup
timeClient.begin();

  
}





void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients


//Alarm Function
timeClient.update();


 //Serial.print(daysOfTheWeek[timeClient.getDay()]);
 // Serial.print(", ");
 // Serial.print(timeClient.getHours());
 // Serial.print(":");
 // Serial.print(timeClient.getMinutes());
 // Serial.print(":");
 // Serial.println(timeClient.getSeconds());
 // Serial.println(timeClient.getFormattedTime());




TimeHours = timeClient.getHours();
TimeMinutes = timeClient.getMinutes();
TimeSeconds = timeClient.getSeconds();

//Serial.print(TimeHours);
//Serial.print(":");
//Serial.print(TimeMinutes);
//Serial.print(":");
//Serial.print(TimeSeconds);
//Serial.println("");
//Serial.println(" ");

if( (TimeHours == 7) && (TimeMinutes == 30 && TimeSeconds == 0)){
       Serial.write(AllZoneon,6);
              AllZoneState = "on"; 
              digitalWrite(gpio2Pin, HIGH);
              delay(100); 
} 

  delay(1000);
 
  


  

  if (client) {                             // If a new client connects,
    //Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        //Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /0/on") >= 0) {
              
              Serial.write(Zone1on,6);
              Zone1State = "on";  
              digitalWrite(gpio2Pin, HIGH);            
              delay(100);
              
            } else if (header.indexOf("GET /0/off") >= 0) {
              Serial.write(Zone1off,6);
             Zone1State = "off";
             digitalWrite(gpio2Pin, LOW);
              delay(100);
              
            } else if (header.indexOf("GET /1/on") >= 0) {
              Serial.write(Zone2on,6);
              Zone2State = "on";
              digitalWrite(gpio2Pin, HIGH);
              delay(100);
              
            } else if (header.indexOf("GET /1/off") >= 0) {
            Serial.write(Zone2off,6);
            Zone2State = "off";
            digitalWrite(gpio2Pin, LOW);
            delay(100);
           
            } else if (header.indexOf("GET /2/on") >= 0) {
              Serial.write(Zone3on,6);
              Zone3State = "on";
              digitalWrite(gpio2Pin, HIGH);
              delay(100);
             
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.write(Zone3off,6);
             Zone3State = "off";
             digitalWrite(gpio2Pin, LOW);
             delay(100);
             
            } else if (header.indexOf("GET /3/on") >= 0) {
              Serial.write(Zone4on,6);
              Zone4State = "on"; 
              digitalWrite(gpio2Pin, HIGH);
              delay(100); 
              
            } else if (header.indexOf("GET /3/off") >= 0) {
              Serial.write(Zone4off,6);
            Zone4State = "off";
            digitalWrite(gpio2Pin, LOW);
            delay(100);
            
            }else if (header.indexOf("GET /4/on") >= 0) {
              Serial.write(AllZoneon,6);
              AllZoneState = "on"; 
              digitalWrite(gpio2Pin, HIGH);
              delay(100); 

            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.write(AllZoneoff,6);
              AllZoneState = "off";
              digitalWrite(gpio2Pin, LOW);
              delay(100);
            }

           
            
           // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            
            
            // Web Page Heading
            client.println("<body><h1>ESP8266 Web Server</h1>");
            
            // Display current state, and ON/OFF buttons for Zone 1  
            client.println("<p>Zone 1 - State " + Zone1State + "</p>");
            // If the output0State is off, it displays the ON button       
            if (Zone1State=="off") {
              client.println("<p><a href=\"/0/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/0/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for Zone 2  
            client.println("<p>Zone 2 - State " + Zone2State + "</p>");
            // If the output4State is off, it displays the ON button       
            if (Zone2State=="off") {
              client.println("<p><a href=\"/1/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/1/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");
           
            // Display current state, and ON/OFF buttons for Zone 3  
            client.println("<p>Zone 3 - State " + Zone3State + "</p>");
            // If the output2State is off, it displays the ON button       
            if (Zone3State=="off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for Zone 4  
            client.println("<p>Zone 4 - State " + Zone4State + "</p>");
            // If the output4State is off, it displays the ON button       
            if (Zone4State=="off") {
              client.println("<p><a href=\"/3/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/3/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");

             // Display current state, and ON/OFF buttons for All Zones 
            client.println("<p>All Zones - State " + AllZoneState + "</p>");
            // If the AllZoneState is off, it displays the ON button       
            if (AllZoneState=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");

            
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    //Serial.println("Client disconnected.");
   // Serial.println("");



   
   
  }
}
