#include <SoftwareSerial.h>
#include <stdio.h>
#include <NewPing.h>
#include <Servo.h>

const int trigPin = 2;
const int echoPin = 4;

long distance; 

void setup() {
  // initialize serial communication:
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  Serial.println("===============");
  sonarTest(trigPin, echoPin);
}

void sonarSensor(int trigPin, int echoPin) { 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(200); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100); // Added this line
  digitalWrite(trigPin, LOW);
  distance = pulseIn(echoPin, HIGH);
  distance = distance / 58;
}

void sonarTest(int trigPin, int echoPin){
  sonarSensor(trigPin, echoPin); 
  Serial.print(distance);
  Serial.println(" cm"); 
  delay(500); 
  }
