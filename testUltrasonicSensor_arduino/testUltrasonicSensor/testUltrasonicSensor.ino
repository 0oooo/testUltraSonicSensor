#include <SoftwareSerial.h>
#include <stdio.h>
#include <NewPing.h>
#include <Servo.h>

const int trigPin = 2;
const int echoPin = 4;

long distance; 
//Timeout: the number of microseconds to wait for the pulse to start; default is one second (unsigned long)
//Here we are setting it to the equivalent to 1m (dont care if its more than a meter and we dont want to wait longer): 
//Speed of sounds = 340.29 per seconds ( or 1 000 000 ms)
// 1000 000 / 340.29 * 2 (times to go and come back) 
// => ~5877.3399 
long timeout = 5877.3399;  

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
  distance = pulseIn(echoPin, HIGH, timeout);
  distance = distance / 58;
}

void sonarTest(int trigPin, int echoPin){
  sonarSensor(trigPin, echoPin); 
  Serial.print(distance);
  Serial.println(" cm"); 
  delay(500); 
  }
