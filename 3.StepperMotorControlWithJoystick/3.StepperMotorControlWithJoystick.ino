//Goal:Make joystick control the stepper motor
//Theme:analog input/output
#include <Stepper.h>
// Define number of steps per revolution (adjust as per your stepper motor)
#define STEPS 32
// Define stepper motor control pins
#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8
// Initialize stepper library
Stepper stepper(STEPS, IN4, IN2, IN3, IN1);
// Joystick input pin (connected to A0)
#define joystick A0
// Define a deadzone range for the joystick
#define JOYSTICK_DEADZONE_LOW 485
#define JOYSTICK_DEADZONE_HIGH 535
void setup() {
  // Initialize the serial monitor for debugging
  Serial.begin(9600);
}
void loop() {
  // Read the analog value from the joystick's X-axis
  int val = analogRead(joystick);
  // Print joystick value for debugging (you can remove this later)

  if (val > JOYSTICK_DEADZONE_LOW && val < JOYSTICK_DEADZONE_HIGH) {
    // Stops the motor 
    stepper.setSpeed(0); // Set speed to 0 (stop the motor)
  }
  else if (val >= JOYSTICK_DEADZONE_HIGH) {
    // Move the motor forward (clockwise direction)
    int speed = map(val, JOYSTICK_DEADZONE_HIGH, 1023, 5, 500); // Map joystick value to speed
    stepper.setSpeed(speed); // Set the motor speed
    stepper.step(1); // Move motor 1 step forward
  }
  else if (val <= JOYSTICK_DEADZONE_LOW) {
    // Move the motor backward (counterclockwise direction)
    int speed = map(val, 0, JOYSTICK_DEADZONE_LOW, 5, 500); // Map joystick value to speed
    stepper.setSpeed(speed); // Set the motor speed
    stepper.step(-1); // Move motor 1 step backward
  }
 
  delay(10);
}
