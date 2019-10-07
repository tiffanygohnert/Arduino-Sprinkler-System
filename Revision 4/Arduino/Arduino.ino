// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int  buttonPin2 = 3;


const int Zone1 = 12;    // Zone 1 Valve connected to digital pin 12
const int Zone2 = 11;    // Zone 2 Valve connected to digital pin 11
const int Zone3 = 10;    // Zone3 connected to digital pin 10
const int Zone4 = 9;    // Zone4 connected to digital pin 9
const int Reset = 7; 
//Timeing Variable constants won't change :
unsigned long interval = 100000; // the time we need to wait

// Variables will change:
unsigned long previousMillis = 0;        // will store last time LED was updated

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int buttonPushCounter2 = 0;   // counter for the number of button presses
int buttonState2 = 0;         // current state of the button
int lastButtonState2 = 0;     // previous state of the button

int Zone1State = LOW;
int Zone2State = LOW;
int Zone3State = LOW;
int Zone4State = LOW;


void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  // initialize the LED as an output:
 
  pinMode(Zone1, OUTPUT);
  pinMode(Zone2, OUTPUT);
  pinMode(Zone3, OUTPUT);
  pinMode(Zone4, OUTPUT);
  pinMode(Reset, OUTPUT);

digitalWrite(Reset, LOW);
digitalWrite(Zone1, Zone1State);
  
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {

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
    
if (buttonPushCounter  == 1 && buttonPushCounter2 == 1 ) {
unsigned long currentMillis = millis(); // grab current time
digitalWrite(Zone1,HIGH); // sets the LED based on ledState


 
// check if "interval" time has passed (interval milliseconds)
        if ((unsigned long)(currentMillis - previousMillis) >= interval) {
  
      Serial.println("Zone 1 off"); 
      digitalWrite(Zone1,LOW);
      Serial.println(currentMillis);
      previousMillis = millis();
      buttonPushCounter = 0;
      buttonPushCounter2 = 0;
   
      }
}
else if  (buttonPushCounter  == 1 && buttonPushCounter2 >= 2 ){
digitalWrite(Zone1,LOW); // sets the LED based on ledState
buttonPushCounter = 0;
buttonPushCounter2 = 0;
//previousMillis = 0;
digitalWrite(Reset, HIGH);
delay(1000);
 } 
if (buttonPushCounter  == 2 && buttonPushCounter2 == 1 ) {
unsigned long currentMillis = millis(); // grab current time
digitalWrite(Zone2,HIGH); // sets the LED based on ledState


 
// check if "interval" time has passed (interval milliseconds)
        if ((unsigned long)(currentMillis - previousMillis) >= interval) {
  
      Serial.println("Zone 2 off"); 
      digitalWrite(Zone2,LOW);
      //Serial.println(currentMillis);
      previousMillis = millis();
      buttonPushCounter = 0;
       buttonPushCounter2 = 0;
   
      }
}
else if   (buttonPushCounter  == 2 && buttonPushCounter2 >= 2 ){
digitalWrite(Zone2,LOW); // sets the LED based on ledState
buttonPushCounter = 0;
buttonPushCounter2 = 0;
//previousMillis = 0;
digitalWrite(Reset, HIGH);
delay(1000);
 } 

 
if (buttonPushCounter  == 3 && buttonPushCounter2 == 1 ) {
unsigned long currentMillis = millis(); // grab current time
digitalWrite(Zone3,HIGH); // sets the LED based on ledState


 
// check if "interval" time has passed (interval milliseconds)
        if ((unsigned long)(currentMillis - previousMillis) >= interval) {
  
      Serial.println("Zone 3 off"); 
      digitalWrite(Zone3,LOW);
      //Serial.println(currentMillis);
      previousMillis = millis();
      buttonPushCounter = 0;
       buttonPushCounter2 = 0;
   
      }
}
else if (buttonPushCounter  == 3 && buttonPushCounter2 >= 2 ){
digitalWrite(Zone3,LOW); // sets the LED based on ledState
buttonPushCounter = 0;
buttonPushCounter2 = 0;
//previousMillis = 0;
digitalWrite(Reset, HIGH);
delay(1000);
 } 
if (buttonPushCounter  == 4 && buttonPushCounter2 == 1 ) {
unsigned long currentMillis = millis(); // grab current time
digitalWrite(Zone4,HIGH); // sets the LED based on ledState


 
// check if "interval" time has passed (interval milliseconds)
        if ((unsigned long)(currentMillis - previousMillis) >= interval) {
  
      Serial.println("Zone 4 off"); 
      digitalWrite(Zone4,LOW);
      //Serial.println(currentMillis);
      previousMillis = millis();
      buttonPushCounter = 0;
       buttonPushCounter2 = 0;
   
      }
}
else if (buttonPushCounter  == 4 && buttonPushCounter2 >= 2 ){
digitalWrite(Zone4,LOW); // sets the LED based on ledState
buttonPushCounter = 0;
buttonPushCounter2 = 0;
//previousMillis = 0;
digitalWrite(Reset, HIGH);
delay(1000);
 } 
//if (buttonPushCounter  == 5 && buttonPushCounter2 == 1 ) {
//unsigned long currentMillis = millis(); // grab current time
//digitalWrite(Zone1,HIGH); // sets the LED based on ledState

 
// check if "interval" time has passed (interval milliseconds)
       // if ((unsigned long)(currentMillis - previousMillis) >= interval) {
  
     // Serial.println("Zone 1 off"); 
    //  digitalWrite(Zone1,LOW);
      //Serial.println(currentMillis);
     // previousMillis = millis();
     // buttonPushCounter = 0;
      // buttonPushCounter2 = 0;
   
     // }


//}
//else if (buttonPushCounter  == 5 && buttonPushCounter2 >= 2 ){
//digitalWrite(Zone1,LOW); // sets the LED based on ledState
//buttonPushCounter = 0;
//buttonPushCounter2 = 0;
//previousMillis = 0;
//digitalWrite(Reset, HIGH);
 }      
      
           
      
     
