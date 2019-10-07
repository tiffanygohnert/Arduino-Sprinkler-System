// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int  buttonPin2 = 3;


const int Zone1 = 12;    // Zone 1 Valve connected to digital pin 12
const int Zone2 = 11;    // Zone 2 Valve connected to digital pin 11
const int Zone3 = 10;    // Zone3 connected to digital pin 10
const int Zone4 = 9;    // Zone4 connected to digital pin 9

const int Reset1 = 4;
const int Reset2 = 5;
const int Reset4 = 7; 
const int Reset3 = 8;

//Timeing Variable constants won't change :
unsigned long interval = 10000; // The time we need to water zone
int AllTime=300;
// Variables will change:
unsigned long previousMillis = 0;        // Variable for storing a time stamp

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int buttonPushCounter2 = 0;   // counter for the number of button presses
int buttonState2 = 0;         // current state of the button
int lastButtonState2 = 0;     // previous state of the button

int RunZone = 0;               //Variable for zone selection
int i1 = 0;                    //Variable for all zone timer
int i2 = 0;                    //Variable for all zone timer
int i3 = 0;                    //Variable for all zone timer
int i4 = 0;                    //Variable for all zone timer



void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  // initialize the LED as an output:
 
  pinMode(Zone1, OUTPUT);
  pinMode(Zone2, OUTPUT);
  pinMode(Zone3, OUTPUT);
  pinMode(Zone4, OUTPUT);


//digitalWrite(Zone1, Zone1State);
  
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
 digitalWrite(Zone1, HIGH);
 digitalWrite(Zone2, HIGH);
 digitalWrite(Zone3, HIGH);
 digitalWrite(Zone4, HIGH);

  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      //Serial.println("B1 on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      //Serial.println("B1 off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;


  buttonState2 = digitalRead(buttonPin2);

  // compare the buttonState to its previous state
  if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter2++;
      //Serial.println("B2 on");
      Serial.print("number of button2 pushes: ");
      Serial.println(buttonPushCounter2);
    } else {
      // if the current state is LOW then the button went from on to off:
      //Serial.println("B2 off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  
  // save the current state as the last state, for next time through the loop
  lastButtonState2 = buttonState2;
  }
    
// Determine what zone will run from the number of times the wifi chip sends a signal 
RunZone = buttonState;

if (buttonPushCounter ==1) {
  RunZone =Zone1;
}
else if (buttonPushCounter ==2) {
  RunZone =Zone2;
}

else if (buttonPushCounter ==3) {
  RunZone =Zone3;
}
else if (buttonPushCounter ==4) {
  RunZone =Zone4;
}
//else if (buttonPushCounter ==5) {
 // RunZone =AllZones;


//Program Cycle

if (buttonPushCounter  >= 1 && buttonPushCounter  <= 4 && buttonPushCounter2 == 1 ) {

unsigned long currentMillis = millis(); // grab current time

digitalWrite(RunZone,LOW); // sets the Sprinkler Zone On
Serial.println("Zone 1 ON");

// check if "interval" time has passed (interval milliseconds)
        if ((unsigned long)(currentMillis - previousMillis) >= interval) {
  
      //Serial.println("Zone 1 off"); 
      digitalWrite(RunZone,HIGH);
      Serial.println(currentMillis-previousMillis);
      previousMillis = millis();
    
      buttonPushCounter = 0;
      buttonPushCounter2 = 0;
   
      }
}

else if (buttonPushCounter  == 5 && buttonPushCounter2 == 1 ) {

digitalWrite(Zone1, LOW);   // set the Zone1 on
Serial.println("Zone 1 on");
   while ( i1 <= AllTime && digitalRead(buttonPin2)==HIGH){
   Serial.println(i1);    
   delay(1000);
   i1++;
   }
   i1=0;
   digitalWrite(Zone1, HIGH);    // set the Zone1 off
   delay(1.5);                  // wait 
   
   digitalWrite(Zone2, LOW);   // set the Zone2 on
   Serial.println("Zone 2 on"); 
    while ( i2 <= AllTime && digitalRead(buttonPin2)==HIGH){
    Serial.println(i2);    
   delay(1000);
   i2++;
   }                 // wait
   i2=0;
   digitalWrite(Zone2, HIGH);    // set the Zone2 off
   delay(1.5);                  // wait for a second
   
   digitalWrite(Zone3, LOW);   // set the Zone3 on 
   Serial.println("Zone 3 on");
   while ( i3 <= AllTime && digitalRead(buttonPin2)==HIGH){
    Serial.println(i3);    
   delay(1000);
   i3++;
   }                 // wait 
   i3=0;
   digitalWrite(Zone3, HIGH);    // set the Zone3 off
   delay(1.5);                   // wait 
   
   digitalWrite(Zone4, LOW);   // set the Zone4 on
    while ( i4 <= AllTime && digitalRead(buttonPin2)==HIGH){
    Serial.println(i4);    
   delay(1000);
   i4++;
   }                 // wait   
   i4=0;
   digitalWrite(Zone4, HIGH);    // set the Zone4 off
   Serial.println("Zone 4 on");
   delay(1.5);                  // wait
   buttonPushCounter = 0;
   buttonPushCounter2 = 0;
   previousMillis = millis();   
}

else if  (buttonPushCounter  >= 1 && buttonPushCounter2 >= 2 ){
digitalWrite(RunZone,HIGH); // sets the Sprinkler Zone off
buttonPushCounter = 0;
buttonPushCounter2 = 0;
previousMillis = millis();

 }
}
