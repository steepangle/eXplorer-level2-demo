#include <Arduino.h>

void setup()
{
    pinMode(3, OUTPUT);
}

void loop()
{
    analogWrite(3, 80);
}