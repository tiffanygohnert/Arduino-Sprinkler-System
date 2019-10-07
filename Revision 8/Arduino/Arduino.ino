//=== function to print the command list:  ===========================
//void printHelp(void){
//  Serial.println("--- Command list: ---");  
//  Serial.println("a -> Zone 1 on");
//  Serial.println("b -> Zone 1 off");
//  Serial.println("c -> Zone 2 on");
//  Serial.println("d -> Zone 2 off");
//  Serial.println("e -> Zone 3 on"); 
//  Serial.println("f -> Zone 3 off");
//  Serial.println("g -> Zone 4 on");
//  Serial.println("h -> Zone 4 off");
 // Serial.println("i -> All Zones 4 on");
 // Serial.println("j -> All Zones 4 off");
  
//  }


char rxChar= 0;         // RXcHAR holds the received command.

const int Zone1 = 12;     // Pin 12 is connected to the Zone1
const int Zone2 = 11;     // Pin 11 is connected to the Zone2
const int Zone3 = 10;     // Pin 10 is connected to the Zone3
const int Zone4 = 9;      // Pin 9 is connected to the Zone4

const int GPIO2Pin = 2;   // Pin 2 is connected to the ESP82666 GPIO2 PIN
const int GPIO0 =3;       // Pin 3 is connected to the ESP82666 GPIO0 PIN

int i1 = 0;                    //Variable for all zone timer
int i2 = 0;                    //Variable for all zone timer
int i3 = 0;                    //Variable for all zone timer
int i4 = 0;                    //Variable for all zone timer

int ZoneSelect =0;              //Variable for selecting zone

//int AllTime = 300;                 //Water Time for AllZone
int Zone1Time = 300;
int Zone2Time = 300;
int Zone3Time = 300;
int Zone4Time = 300;

//const int  buttonPin = 2;    // the pin that the pushbutton is attached to
  
//---------------- setup ---------------------------------------------
void setup(){
  Serial.begin(9600);         // Open serial port (9600 bauds).
  pinMode(Zone1, OUTPUT);     // Sets pin 12 as OUTPUT.
  pinMode(Zone2, OUTPUT);     // Sets pin 11 as OUTPUT.
  pinMode(Zone3, OUTPUT);     // Sets pin 10 as OUTPUT.
  pinMode(Zone4, OUTPUT);     // Sets pin 9 as OUTPUT.

  pinMode(GPIO2Pin, INPUT);    //Sets button pin as input 
  pinMode(GPIO0, OUTPUT);    //Sets button pin as input

  digitalWrite(Zone1, HIGH);    // Sets pin 12 as HIGH / Zone Off.
  digitalWrite(Zone2, HIGH);    // Sets pin 11 as HIGH / Zone Off.
  digitalWrite(Zone3, HIGH);    // Sets pin 10 as HIGH / Zone Off.
  digitalWrite(Zone4,HIGH);     // Sets pin 19 as HIGH / Zone Off.
   digitalWrite(GPIO0,LOW);     // Sets pin 19 as HIGH / Zone Off.

  

  Serial.flush();       // Clear receive buffer.
//  printHelp();          // Print the command list.
}

//--------------- loop ----------------------------------------------- 
void loop(){

 
  if (Serial.available() >0){          // Check receive buffer.
    rxChar = Serial.read();            // Save character received. 
    
    Serial.flush();                    // Clear receive buffer.
  
      switch (rxChar) {
    
        case 'a':                       // If received 'a' 
                              
            if (digitalRead(Zone1) == HIGH){        // If Zone is Off:   
                digitalWrite(GPIO0,HIGH);           //Conformation Pin on
                Serial.println(rxChar);  
                digitalWrite(Zone1,LOW);      // Turn On the Zone.
                Serial.println("Zone1 turned On"); 
                

                while ( i1 <=Zone1Time && digitalRead(GPIO2Pin)==HIGH){                  
                delay(1000);
                i1++;
                //Serial.println("Zone1 turned On");  
                }
                i1=0;
                digitalWrite(Zone1,HIGH);      // Turn off the Zone.
                digitalWrite(GPIO0,LOW);           //Conformation Pin off
                Serial.println("Zone1 turned Off");   
                    }
            else Serial.println("Zone1 already On!");   
            break;

        case 'b':                             // If received 'b' :               
                         
            if (digitalRead(Zone1) == LOW){       // If Zone1 is On:
            Serial.println(rxChar);  
            digitalWrite(Zone1,HIGH);       // Turn Off the Zone1.
            digitalWrite(GPIO0,LOW);           //Conformation Pin off
            Serial.println("Zone1 turned Off");
            }
            else Serial.println("Zone1 already Off!");
            break;
        
        case 'c':                             // If received 'c' 
                              
            if (digitalRead(Zone2) == HIGH){        // If Zone2 is Off:
                Serial.println(rxChar);  
                digitalWrite(Zone2,LOW);      // Turn On the Zone2.
                digitalWrite(GPIO0,HIGH);     //Conformation Pin on
                Serial.println("Zone2 turned On");

               while ( i1 <=Zone2Time && digitalRead(GPIO2Pin)==HIGH){                   
               delay(1000);
               i1++;
                //Serial.println("Zone2 turned On");  
                }
                i1=0;
                digitalWrite(Zone2,HIGH);      // Turn off the Zone.
                digitalWrite(GPIO0,LOW);       //Conformation Pin off
                Serial.println("Zone2 turned Off");
                }
            else Serial.println("Zone2 already On!");
            break;

        case 'd':                                  // If received 'd' :
                         
            if (digitalRead(Zone2) == LOW){         // If Zone2 is On:
                Serial.println(rxChar);  
                digitalWrite(Zone2,HIGH);           // Turn Off the Zone2.
                digitalWrite(GPIO0,LOW);            //Conformation Pin off
                Serial.println("Zone2 turned Off");
                }
           else Serial.println("Zone2 already Off!");
           break;

       case 'e':                                    // If received 'e' 
                              
            if (digitalRead(Zone3) == HIGH){        // If Zone3 is Off:
             Serial.println(rxChar);  
            digitalWrite(Zone3,LOW);                // Turn On the Zone3.
            digitalWrite(GPIO0,HIGH);               //Conformation Pin on
            Serial.println("Zone3 turned On");

            while ( i1 <=Zone3Time && digitalRead(GPIO2Pin)==HIGH){               
            delay(1000);
            i1++;
            //Serial.println("Zone3 turned On");  
            }
            i1=0;
            digitalWrite(Zone3,HIGH);         // Turn off the Zone.
            digitalWrite(GPIO0,LOW);           //Conformation Pin off
            Serial.println("Zone3 turned Off");
            }
            else Serial.println("Zone3 already On!");
            break;

    case 'f':                                 // If received 'f' :
                         
        if (digitalRead(Zone3) == LOW){       // If Zone3 is On:
            Serial.println(rxChar);  
            digitalWrite(Zone3,HIGH);         // Turn Off the Zone3.
            digitalWrite(GPIO0,LOW);           //Conformation Pin off
            Serial.println("Zone3 turned Off");
            }
            else Serial.println("Zone3 already Off!");
            break;
            case 'g':                           // If received '4'
                                            
        if (digitalRead(Zone4) == HIGH){        // If Zone4 is Off         
            Serial.println(rxChar);  
            digitalWrite(Zone4,LOW);            // Turn On the Zone4.
            digitalWrite(GPIO0,HIGH);           //Conformation Pin on
            Serial.println("Zone4 turned On");
            while ( i1 <=Zone4Time && digitalRead(GPIO2Pin)==HIGH){              
            delay(1000);
            i1++;
            //Serial.println("Zone4 turned On");  
            }
            i1=0;
            digitalWrite(Zone4,HIGH);             // Turn off the Zone.
            digitalWrite(GPIO0,LOW);              //Conformation Pin off
            Serial.println("Zone4 turned Off");
            }
            else Serial.println("Zone4 already On!");
            break;

    case 'h':       // If received 'h' :
                          
        if (digitalRead(Zone4) == LOW){         // If Zone4 is On:
          Serial.println(rxChar);  
          digitalWrite(Zone4,HIGH);             // Turn Off the Zone4.
          digitalWrite(GPIO0,LOW);              //Conformation Pin off
          Serial.println("Zone4 turned Off");
          }
        else Serial.println("Zone4 already Off!");
        break;
        
   case 'i':                                       // If received a 0:
          
         digitalWrite(Zone1,LOW);                 // Turn on the Zone.
         //digitalWrite(GPIO0,HIGH);                 //Conformation Pin on
         Serial.println(rxChar);
         Serial.println("Zone1 turned On");
         while ( i1 <=Zone1Time && digitalRead(GPIO2Pin)==HIGH){             
         delay(1000);
         i1++;
         //Serial.println("Zone1 turned On");  
         }
         i1=0;
         digitalWrite(Zone1,HIGH);              // Turn off the Zone.
         digitalWrite(Zone2,LOW);               // Turn on the Zone. 
         Serial.println("Zone2 turned On");            
         while ( i1 <=Zone2Time && digitalRead(GPIO2Pin)==HIGH){              
         delay(1000);
         i1++;
        //Serial.println("Zone2 turned On");  
         }
         i1=0;
         digitalWrite(Zone2,HIGH);              // Turn off the Zone.
         digitalWrite(Zone3,LOW);               // Turn on the Zone.
         Serial.println("Zone3 turned On"); 
         while ( i1 <=Zone3Time && digitalRead(GPIO2Pin)==HIGH){           
         delay(1000);
         i1++;
         //Serial.println("Zone3 turned On");  
         }
         i1=0;
         digitalWrite(Zone3,HIGH);              // Turn off the Zone.
         digitalWrite(Zone4,LOW);               // Turn on the Zone.
         Serial.println("Zone4 turned On"); 
         while ( i1 <=Zone4Time && digitalRead(GPIO2Pin)==HIGH){              
         delay(1000);
         i1++;
         //Serial.println("Zone4 turned On");  
         }
         i1=0;
         digitalWrite(Zone4,HIGH);              // Turn off the Zone.
         //digitalWrite(GPIO0,LOW);               //Conformation Pin off

         //Delay for water to soak into ground before allowing an additional cycle. 
         while ( i1 <=610 && digitalRead(GPIO2Pin)==HIGH){              
         delay(1000);
         i1++;         
         }           
         break;

    case 'j':                                   // If received 'j' :
        Serial.println(rxChar);  
                         
  
          digitalWrite(Zone1,HIGH);             // Turn Off the Zone4.
          digitalWrite(Zone2,HIGH);             // Turn Off the Zone4.
          digitalWrite(Zone3,HIGH);             // Turn Off the Zone4.
          digitalWrite(Zone4,HIGH);             // Turn Off the Zone4.
          digitalWrite(GPIO0,LOW);              //Conformation Pin off
          
          Serial.println("Zone4 turned Off");
  
          Serial.println("All Zones already Off!");
          break;
         
    


   
        
       default:                     
          Serial.print((char)rxChar);
     
    }
 }
}
// End of the Sketch.
