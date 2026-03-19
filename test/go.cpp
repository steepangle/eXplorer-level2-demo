#include <Arduino.h>
// #include <FastLED.h>

#define PIN_LED_L 7
#define PIN_LED_R 8
#define PIN_LED_C 6

#define PIN_DIST_L A1
#define PIN_DIST_R A0
#define PIN_SENS_C A5
#define PIN_SENS_D A4

#define PIN_M1_F 3
#define PIN_M1_R 11
#define PIN_M2_F 10
#define PIN_M2_R 9

#define PIN_SPKR 5
#define PIN_S1 4
#define PIN_S2 2
#define PIN_RGB 13

#define PIN_RX 2
#define PIN_TX 3

// #define NUM_RGB_LEDS 2
// CRGB leds[NUM_RGB_LEDS];

bool blockIn = false;
int restCounter = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Booting ...");

  // FastLED.addLeds<NEOPIXEL, PIN_RGB>(leds, NUM_RGB_LEDS);

  delay(500);

  // S1, S2
  pinMode(2, INPUT);
  pinMode(4, INPUT);

  // OUT Pins 5 - 8
  for (int i = 5; i <= 8; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void go(char motor, char direction, int duration) {
  if (motor == 'R')
  {
    if (direction == 'F')
    {
      digitalWrite(PIN_M1_F, HIGH);
      delay(duration);
      digitalWrite(PIN_M1_F, LOW);
      blockIn = false;
    } else if (direction == 'B')
    {
      digitalWrite(PIN_M1_R, HIGH);
      delay(duration);
      digitalWrite(PIN_M1_R, LOW);
      blockIn = false;
    }
  } else if (motor == 'L')
  {
    if (direction == 'F')
    {
      digitalWrite(PIN_M2_F, HIGH);
      delay(duration);
      digitalWrite(PIN_M2_F, LOW);
      blockIn = false;
    } else if (direction == 'B')
    {
      digitalWrite(PIN_M2_R, HIGH);
      delay(duration);
      digitalWrite(PIN_M2_R, LOW);
      blockIn = false;
    }
  }
}

void loop()
{
  if (!blockIn)
  {
    if (digitalRead(PIN_S1))
    {
      blockIn = true;
      //go FWD no BREAK
      delay(500);
      digitalWrite(PIN_M2_F, HIGH);
      digitalWrite(PIN_M1_F, HIGH);
      delay(2000);
      digitalWrite(PIN_M2_F, LOW);
      digitalWrite(PIN_M1_F, LOW);
      digitalWrite(PIN_M2_R, LOW);
      digitalWrite(PIN_M1_R, LOW);

      blockIn = false;

      /*
      Serial.println("FWD Right");
      go('R', 'F', 1000);
      delay(500);
      Serial.println("FWD Left");
      go('L', 'F', 1000);
      */
    }
    else if (!digitalRead(PIN_S2))
    {
      blockIn = true;
      //go FWD
      delay(500);
      digitalWrite(PIN_M2_F, HIGH);
      digitalWrite(PIN_M1_F, HIGH);
      delay(2000);
      digitalWrite(PIN_M2_R, HIGH);
      digitalWrite(PIN_M1_R, HIGH);

      delay(2000);
      digitalWrite(PIN_M2_F, LOW);
      digitalWrite(PIN_M1_F, LOW);
      digitalWrite(PIN_M2_R, LOW);
      digitalWrite(PIN_M1_R, LOW);

      blockIn = false;

      /*
      delay(500);
      //go REV
      digitalWrite(PIN_M2_R, HIGH);
      digitalWrite(PIN_M1_R, HIGH);
      delay(2000);
      digitalWrite(PIN_M2_R, LOW);
      digitalWrite(PIN_M1_R, LOW);
      blockIn = false;
      */
    }
  }
}