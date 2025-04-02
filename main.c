/*
 * Created by: Daki
 * Created on: Apr 2025
 * 
 * This program turns a servo 90 degrees, once within 50cm of an object
 * 
 */

# include <Servo.h>

// setting constants for sonar sensor
const int TRIG_PIN = 10;  
const int ECHO_PIN = 9; 
float duration, distance;

Servo servoNumber1;

void setup() {
    // defining sonar sensor and servo pins
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    Serial.begin(9600);
    servoNumber1.attach(2);
    servoNumber1.write(0);
}

void loop() {
    // Setting servo to 0 degrees
    servoNumber1.write(0);
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
	// finding distance with sonar
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);
  
  if (distance < 50) {
    // Turning servo 90 from 0 degrees if distance is less than 50cm
    servoNumber1.write(0);
    delay(500);
    servoNumber1.write(90);
    delay(500);
  }
}
