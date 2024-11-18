 //Goal:Make a voltmeter and show the value on a paper with the help of the servo 
//theme:servo motor 

#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 



int pos = 0;    // variable to store the servo position 
int pot = A0; //potentiemeter pin 
int value = 0; //potentiemeter Value 

  

void setup() { 

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600); 

} 

void loop() { 


  value = analogRead(pot); 
  int voltage = map(value,0,1023,0,500); 
  
  float volt = voltage/100.0; 
  Serial.println(volt); 

  pos = map(value,0,1023,0,180); 
  myservo.write(pos); 
  delay(15); 

  

} 