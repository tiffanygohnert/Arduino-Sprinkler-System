// constants won't change. They're used here to set pin numbers:
const int Wifiesp = 2;     // The signal from Esp GP0

int Zone1 = 12;    // Zone 1 Valve connected to digital pin 12
int Zone2 = 11;    // Zone 2 Valve connected to digital pin 11
int Zone3 = 10;    // Zone3 connected to digital pin 10
int Zone4 = 9;    // Zone4 connected to digital pin 9



// variables will change:
int WifiespState = 0;         // variable for reading the Wifiesp status
 
void setup() {
 digitalWrite(Zone4, LOW);
  // initialize the Zone pin as an output:
  pinMode(Zone1, OUTPUT);
  pinMode(Zone2, OUTPUT);
  pinMode(Zone3, OUTPUT);
  pinMode(Zone4, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(Wifiesp, INPUT);
   
}


void loop() {
  // read the state of the Wifi esp value:
  WifiespState = digitalRead(Wifiesp);

  // check if the Wifi has trigered. If it is, the WifiState is HIGH:
  if (WifiespState == HIGH) {
    // turn Zones on:
     for(int i = 0; i < 1; i += 1)
        {
     
     digitalWrite(Zone1, HIGH);   // set the Zone1 on
        delay(1000);                  // wait 
        digitalWrite(Zone1, LOW);    // set the Zone1 off
        delay(1.5);                  // wait 
        digitalWrite(Zone2, HIGH);   // set the Zone2 on
        delay(1000);                  // wait  
        digitalWrite(Zone2, LOW);    // set the Zone2 off
        delay(1.5);                  // wait for a second
        digitalWrite(Zone3, HIGH);   // set the Zone3 on
        delay(1000);                  // wait 
        digitalWrite(Zone3, LOW);    // set the Zone3 off
        delay(1.5);                   // wait 
        digitalWrite(Zone4, HIGH);   // set the Zone4 on
        delay(1000);                  // wait 
        digitalWrite(Zone4, LOW);    // set the Zone4 off
        delay(1.5);                  // wait
        }

    
  } else {
    // turn Zones off:
    digitalWrite(Zone1, LOW);
     digitalWrite(Zone2, LOW);
      digitalWrite(Zone3, LOW);
       digitalWrite(Zone4, LOW);
  }
}
