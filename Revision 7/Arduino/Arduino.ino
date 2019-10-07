
 


//=== function to print the command list:  ===========================
void printHelp(void){
  Serial.println("--- Command list: ---");  
  Serial.println("a -> Zone 1 on");
  Serial.println("b -> Zone 1 off");
  Serial.println("c -> Zone 2 on");
  Serial.println("d -> Zone 2 off");
  Serial.println("e -> Zone 3 on"); 
  Serial.println("f -> Zone 3 off");
  Serial.println("g -> Zone 4 on");
  Serial.println("h -> Zone 4 off");
  Serial.println("i -> All Zones 4 on");
  Serial.println("j -> All Zones 4 off");
  
  }


char rxChar= 0;         // RXcHAR holds the received command.

const int Zone1 = 12;     // Pin 12 is connected to the Zone1
const int Zone2 = 11;     // Pin 11 is connected to the Zone2
const int Zone3 = 10;     // Pin 10 is connected to the Zone3
const int Zone4 = 9;      // Pin 9 is connected to the Zone4

int i1 = 0;                    //Variable for all zone timer
int i2 = 0;                    //Variable for all zone timer
int i3 = 0;                    //Variable for all zone timer
int i4 = 0;                    //Variable for all zone timer


int AllTime = 300;                 //Water Time for AllZone

const int  buttonPin = 2;    // the pin that the pushbutton is attached to
  
//---------------- setup ---------------------------------------------
void setup(){
  Serial.begin(9600);         // Open serial port (9600 bauds).
  pinMode(Zone1, OUTPUT);     // Sets pin 12 as OUTPUT.
  pinMode(Zone2, OUTPUT);     // Sets pin 11 as OUTPUT.
  pinMode(Zone3, OUTPUT);     // Sets pin 10 as OUTPUT.
  pinMode(Zone4, OUTPUT);     // Sets pin 9 as OUTPUT.

  digitalWrite(Zone1, HIGH);    // Sets pin 12 as HIGH / Zone Off.
  digitalWrite(Zone2, HIGH);    // Sets pin 11 as HIGH / Zone Off.
  digitalWrite(Zone3, HIGH);    // Sets pin 10 as HIGH / Zone Off.
  digitalWrite(Zone4,HIGH);     // Sets pin 19 as HIGH / Zone Off.

  pinMode(buttonPin, INPUT);    //Sets button pin as input 

  
  Serial.flush();       // Clear receive buffer.
  printHelp();          // Print the command list.
}

//--------------- loop ----------------------------------------------- 
void loop(){

  
  if (Serial.available() >0){          // Check receive buffer.
    rxChar = Serial.read();            // Save character received. 
    
    Serial.flush();                    // Clear receive buffer.
  
      switch (rxChar) {
    
        case 'a':                       // If received 'a' 
                              
            if (digitalRead(Zone1) == HIGH){        // If Zone is Off:       
                 
                digitalWrite(Zone1,LOW);      // Turn On the Zone.
                Serial.println("Zone1 turned On");  

                while ( i1 <=300 && digitalRead(buttonPin)==HIGH){                  
                    delay(1000);
                    i1++;
                    Serial.println("Zone1 turned On");  
                    }
                    i1=0;
                    digitalWrite(Zone1,HIGH);      // Turn off the Zone.   
                    }
            else Serial.println("Zone1 already On!");   
            break;

        case 'b':                             // If received 'b' :               
                          
            if (digitalRead(Zone1) == LOW){       // If Zone1 is On:
            digitalWrite(Zone1,HIGH);       // Turn Off the Zone1.
            Serial.println("Zone1 turned Off");
            }
            else Serial.println("Zone1 already Off!");
            break;
        
        case 'c':                             // If received 'c' 
                              
            if (digitalRead(Zone2) == HIGH){        // If Zone2 is Off:
                digitalWrite(Zone2,LOW);      // Turn On the Zone2.
                Serial.println("Zone2 turned On");

                while ( i1 <=300 && digitalRead(buttonPin)==HIGH){                   
                delay(1000);
                i1++;
                Serial.println("Zone2 turned On");  
                }
                i1=0;
                digitalWrite(Zone2,HIGH);      // Turn off the Zone.
                }
            else Serial.println("Zone2 already On!");
            break;

        case 'd':                              // If received 'd' :
                         
            if (digitalRead(Zone2) == LOW){       // If Zone2 is On:
                digitalWrite(Zone2,HIGH);       // Turn Off the Zone2.
                Serial.println("Zone2 turned Off");
                }
           else Serial.println("Zone2 already Off!");
           break;

       case 'e':                              // If received 'e' 
                              
            if (digitalRead(Zone3) == HIGH){        // If Zone3 is Off:
            digitalWrite(Zone3,LOW);      // Turn On the Zone3.
            Serial.println("Zone3 turned On");

            while ( i1 <=300 && digitalRead(buttonPin)==HIGH){               
            delay(1000);
            i1++;
            Serial.println("Zone3 turned On");  
            }
            i1=0;
            digitalWrite(Zone3,HIGH);         // Turn off the Zone.
            }
            else Serial.println("Zone3 already On!");
            break;

    case 'f':                                 // If received 'f' :
                         
        if (digitalRead(Zone3) == LOW){       // If Zone3 is On:
            digitalWrite(Zone3,HIGH);         // Turn Off the Zone3.
            Serial.println("Zone3 turned Off");
            }
            else Serial.println("Zone3 already Off!");
            break;
            case 'g':                           // If received '4'
                                            
        if (digitalRead(Zone4) == HIGH){        // If Zone4 is Off:
            digitalWrite(Zone4,LOW);            // Turn On the Zone4.
            Serial.println("Zone4 turned On");
            while ( i1 <=300 && digitalRead(buttonPin)==HIGH){              
            delay(1000);
            i1++;
            Serial.println("Zone4 turned On");  
            }
            i1=0;
            digitalWrite(Zone4,HIGH);      // Turn off the Zone.
            }
            else Serial.println("Zone4 already On!");
            break;

    case 'h':       // If received 'h' :
                          
        if (digitalRead(Zone4) == LOW){       // If Zone4 is On:
          digitalWrite(Zone4,HIGH);       // Turn Off the Zone4.
          Serial.println("Zone4 turned Off");
          }
        else Serial.println("Zone4 already Off!");
        break;
        
    case 'i':                          // If received a 0:
          
         digitalWrite(Zone1,LOW);      // Turn on the Zone.
         while ( i1 <=AllTime && digitalRead(buttonPin)==HIGH){             
         delay(1000);
         i1++;
         Serial.println("Zone1 turned On");  
         }
         i1=0;
         digitalWrite(Zone1,HIGH);      // Turn off the Zone.
         digitalWrite(Zone2,LOW);      // Turn on the Zone.             
         while ( i1 <=AllTime && digitalRead(buttonPin)==HIGH){              
         delay(1000);
         i1++;
         Serial.println("Zone2 turned On");  
         }
         i1=0;
         digitalWrite(Zone2,HIGH);      // Turn off the Zone.
         digitalWrite(Zone3,LOW);      // Turn on the Zone.
         while ( i1 <=AllTime && digitalRead(buttonPin)==HIGH){           
         delay(1000);
         i1++;
         Serial.println("Zone3 turned On");  
         }
         i1=0;
         digitalWrite(Zone3,HIGH);      // Turn off the Zone.
         digitalWrite(Zone4,LOW);      // Turn on the Zone.
         while ( i1 <=AllTime && digitalRead(buttonPin)==HIGH){              
         delay(1000);
         i1++;
         Serial.println("Zone4 turned On");  
         }
         i1=0;
         digitalWrite(Zone4,HIGH);      // Turn off the Zone.                
         break;

    case 'j':                              // If received 'j' :
                         
  
          digitalWrite(Zone1,HIGH);       // Turn Off the Zone4.
          digitalWrite(Zone2,HIGH);       // Turn Off the Zone4.
          digitalWrite(Zone3,HIGH);       // Turn Off the Zone4.
          digitalWrite(Zone4,HIGH);       // Turn Off the Zone4.
          
          Serial.println("Zone4 turned Off");
  
          Serial.println("All Zones already Off!");
          break;
        
       default:                     
          Serial.print((char)rxChar);
     
    }
 }
}
// End of the Sketch.
