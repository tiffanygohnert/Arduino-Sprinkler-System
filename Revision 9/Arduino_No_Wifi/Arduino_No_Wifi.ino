
const int Zone1 = 12;     // Pin 12 is connected to the Zone1
const int Zone2 = 11;     // Pin 11 is connected to the Zone2
const int Zone3 = 10;     // Pin 10 is connected to the Zone3
const int Zone4 = 9;      // Pin 9 is connected to the Zone4

int i1 = 0;                    //Variable for all zone timer
int i2 = 0;                    //Variable for all zone timer
int i3 = 0;                    //Variable for all zone timer
int i4 = 0;                    //Variable for all zone timer
int iclock = 0;

//int AllTime = 1;                 //Water Time for AllZone
int Zone1Time = 1;
int Zone2Time = 1;
int Zone3Time = 1;
int Zone4Time = 1;

int Day = 0;
int Hour=0;
int Minutes=0;
int Seconds=0;

void setup() {

Serial.begin(9600);         // Open serial port (9600 bauds).
  pinMode(Zone1, OUTPUT);     // Sets pin 12 as OUTPUT.
  pinMode(Zone2, OUTPUT);     // Sets pin 11 as OUTPUT.
  pinMode(Zone3, OUTPUT);     // Sets pin 10 as OUTPUT.
  pinMode(Zone4, OUTPUT);     // Sets pin 9 as OUTPUT.
  
  digitalWrite(Zone1, HIGH);    // Sets pin 12 as HIGH / Zone Off.
  digitalWrite(Zone2, HIGH);    // Sets pin 11 as HIGH / Zone Off.
  digitalWrite(Zone3, HIGH);    // Sets pin 10 as HIGH / Zone Off.
  digitalWrite(Zone4,HIGH);     // Sets pin 19 as HIGH / Zone Off.

  
}

void loop(){
  Counter();
}


void Counter() {


while(Seconds <=60){
  delay(1);
  Seconds++;
  //Serial.println(Seconds);
}
Seconds = 0;

while(Minutes<=60){
  Minutes++;
  Serial.println("Minutes:");
  Serial.print(Minutes);
}

 Hour++;
 Serial.print("Hours:");
 Serial.println(Hour);
  if (Hour == 24){    
    AutoRun(); 
  }


}

void AutoRun (void){

          digitalWrite(Zone1,LOW);                 // Turn on the Zone.
         //digitalWrite(GPIO0,HIGH);                 //Conformation Pin on
   
         Serial.println("Zone1 turned On");
         while ( i1 <=Zone1Time){             
         delay(1000);
         i1++;
         //Serial.println("Zone1 turned On");  
         }
         i1=0;
         digitalWrite(Zone1,HIGH);              // Turn off the Zone.
         digitalWrite(Zone2,LOW);               // Turn on the Zone. 
         Serial.println("Zone2 turned On");            
         while ( i1 <=Zone2Time){              
         delay(1000);
         i1++;
        //Serial.println("Zone2 turned On");  
         }
         i1=0;
         digitalWrite(Zone2,HIGH);              // Turn off the Zone.
         digitalWrite(Zone3,LOW);               // Turn on the Zone.
         Serial.println("Zone3 turned On"); 
         while ( i1 <=Zone3Time){           
         delay(1000);
         i1++;
         //Serial.println("Zone3 turned On");  
         }
         i1=0;
         digitalWrite(Zone3,HIGH);              // Turn off the Zone.
         digitalWrite(Zone4,LOW);               // Turn on the Zone.
         Serial.println("Zone4 turned On"); 
         while ( i1 <=Zone4Time ){              
         delay(1000);
         i1++;
         //Serial.println("Zone4 turned On");  
         }
         i1=0;
         digitalWrite(Zone4,HIGH);              // Turn off the Zone.
         //digitalWrite(GPIO0,LOW);               //Conformation Pin off

        


Hour=0;
Counter();
  
}
