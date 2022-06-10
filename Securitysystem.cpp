// Team : "Angry Nerds"
// Participants: Bhavesh Jain, Riya Bansal


// password for first gate: 8898#
// password for first gate: 6798#
// password for first gate: 567CD#
// password for first gate: CDB97#
// entering # completes the password

//start server motor
#include<Servo.h>
Servo Myservo1;
Servo Myservo2;
Servo Myservo3;
Servo Myservo4;

//variables i need
String password="";
int pos;

// for lcd display
#include <LiquidCrystal.h>
LiquidCrystal lcd = LiquidCrystal(A0, A1, A2, A3, A4, A5);

// for buzzer
const int buzzer = 13; //buzzer to arduino pin 13
String buzzerstat="OFF";

// for key pad
#include <Keypad.h>
String pass[] = {"no","8898#","6798#","567CD#","CDB97#"};


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[ROWS] = {1,2,3,4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,6,7,8}; //connect to the column pinouts of the keypad
//creating an object of class keypad
Keypad inputkeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char inputkey; //variable for key input
void setup()
{
  Myservo1.attach(9);  // attaching server motor 1 to pin 9
  Myservo2.attach(10); // attaching server motor 1 to pin 10
  Myservo3.attach(11); // attaching server motor 1 to pin 11
  Myservo4.attach(12); // attaching server motor 1 to pin 12
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 13 as an output
  Serial.begin(9600);
  lcd.begin(16, 2);  // lcd used is of dimentions 16 X 2
}

void loop()
{
          
          Myservo1.write(0); // server motor 1 is 0 degree deviated

          Myservo2.write(0); // server motor 2 is 0 degree deviated

          Myservo3.write(0); // server motor 3 is 0 degree deviated

          Myservo4.write(0); // server motor 4 is 0 degree deviated

  
  		  lcd.clear(); // LCD display shows nothing
          lcd.print("ENTER PASSWORD"); // LCD display shows ENTER PASSWORD
          delay(2000);
          lcd.clear(); // LCD display shows nothing
  

  
  for(int i=1; i<5; i++){
    password="";
  	inputkey='t';
    while(inputkey!='#'){  // To ensure password is submitted by entering #
    	inputkey= inputkeypad.getKey();
      if (inputkey){
        
      	password+=inputkey;
        Serial.println(inputkey);
        Serial.println(password);
        lcd.print("*"); 
        
      }
    

     }  
      if (password==pass[i]){
        lcd.clear();
        lcd.print("ACCESS GRANTED");
        delay(2000);
        lcd.clear();
        if(i==1){
          Serial.println("gate one open");
             for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees in steps of 1 degree
             Myservo1.write(pos);              // tell servo to go to position in variable 'pos'
             delay(5); 
               
             }}
        
          
          
        if(i==2){
          lcd.clear();
          lcd.print("ACCESS GRANTED");
          delay(2000);
          lcd.clear();
          Serial.println("gate 2 open");
             for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
             Myservo2.write(pos);              // tell servo to go to position in variable 'pos'
             delay(5);
             
             }}       
          
          if(i==3){
            lcd.clear();
            lcd.print("ACCESS GRANTED");
            delay(2000);
            lcd.clear();
          Serial.println("gate 3 open");
             for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degree in steps of 1 degree
             Myservo3.write(pos);              // tell servo to go to position in variable 'pos'
             delay(5);
             
             } }        
        
        if(i==4){
          lcd.clear();
          lcd.print("ACCESS GRANTED");
          delay(2000);
          lcd.clear();
          Serial.println("gate 4 open");
             for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
             Myservo4.write(pos);// tell servo to go to position in variable 'pos'
             
             delay(5);
               
             }}
         
        
      }else{
        buzzerstat="ON"; // if any of the above condition fails the buzzer starts
        Serial.println("fail");
        break;
      }
  
  }
  
  
  //buzzer
  if (buzzerstat=="ON"){
    lcd.clear();
    lcd.print("ACCESS DENIED");
    delay(2000);
    lcd.clear();
    
    while(true){
    Serial.println("!!!!");


    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // Stop sound for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);        // Stop sound for 1 sec
    }
    
    
    
  }
}