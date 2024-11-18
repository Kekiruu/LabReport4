 //Goal:Become a Jedi
//theme:servo motor/Light sensor

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
  Serial.println(value);
  pos = map(value,80,190,0,180); //Min and Max value of the sensors
  myservo.write(pos); 

  delay(20); 

  

} 