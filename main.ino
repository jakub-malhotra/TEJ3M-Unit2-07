// Uses a ultrasonic distance sensor to determine if a servo spins
// Created by: Jakub Malhotra
// Created on: October 2023

#include <Servo.h>

Servo servoNumber1;
const int trigPin = 10;
const int echoPin = 9;
float duration, distance;

// setup
void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    servoNumber1.attach(8);
    servoNumber1.write(0);
}

// loop
void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);

    if (distance > 50) {
        servoNumber1.write(90);
    } else {
        servoNumber1.write(0);
    }
    
}