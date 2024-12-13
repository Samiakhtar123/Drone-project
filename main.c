#include <Servo.h>

// Define the pins for the ESCs
const int motor1Pin = 3; // Motor 1
const int motor2Pin = 5; // Motor 2
const int motor3Pin = 6; // Motor 3
const int motor4Pin = 9; // Motor 4

// Create Servo objects for each motor
Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

// Throttle variable
int throttle = 0;

void setup() {
  // Attach the motors to the corresponding pins
  motor1.attach(motor1Pin);
  motor2.attach(motor2Pin);
  motor3.attach(motor3Pin);
  motor4.attach(motor4Pin);

  // Initialize motors to zero throttle
  motor1.write(0);
  motor2.write(0);
  motor3.write(0);
  motor4.write(0);
  
  // Wait for ESCs to initialize
  delay(2000);
}

void loop() {
 // Example: Gradually increase throttle
  for (throttle = 0; throttle <= 180; throttle += 10) {
    setThrottle(throttle);
    delay(1000); // Wait for 1 second
  }

  // Example: Gradually decrease throttle
  for (throttle = 180; throttle >= 0; throttle -= 10) {
    setThrottle(throttle);
    delay(1000); // Wait for 1 second
  }
}

// Function to set throttle for all motors
void setThrottle(int throttleValue) {
  motor1.write(throttleValue);
  motor2.write(throttleValue);
  motor3.write(throttleValue);
  motor4.write(throttleValue);
}