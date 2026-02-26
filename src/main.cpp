#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  Serial.println("Hello, World!");
  delay(5000);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}