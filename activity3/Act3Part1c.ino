#include "api/Common.h"
#include <Arduino.h>

const int POT_PIN = A0; 
const byte LED_PINS[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};

const byte LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

int mappedValue = 0;
int sensorValue = 0;
int previousMappedValue = 0;

const int PATTERN_1 = 0b0101010101;
const int PATTERN_2 = 0b1010101010;
const int PATTERN_3 = 0b0000011111;
const int PATTERN_4 = 0b1111100000;
const int PATTERN_5 = 0b1111111111;

void clearLEDs();
void turnOnLED(int pattern);
void mapAnalogValues();

void setup() {
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(LED_PINS[i], OUTPUT);

    digitalWrite(LED_PINS[i], LOW);
  }

}

void loop() {
  mapAnalogValues();

  if (mappedValue != previousMappedValue) {
    clearLEDs();

    switch (mappedValue) {
      case 0:
        turnOnLED(PATTERN_1);
        break;

      case 1:
        turnOnLED(PATTERN_2);

        break;

      case 2:
        turnOnLED(PATTERN_3);
        break;

      case 3:
        turnOnLED(PATTERN_4);
        break;

      default:
        break;

    }

    previousMappedValue = mappedValue;
  }

}

void mapAnalogValues() {
  sensorValue = analogRead(POT_PIN);

  mappedValue = map(sensorValue, 0 , 1023, 0, 4);
  
  if (mappedValue == 4) {
    mappedValue = 3;

  }

}

void clearLEDs() {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_PINS[i], LOW);

  }

}

void turnOnLED(int pattern) {

  for (int i = 9; i >= 0; i--) {
    int analogValue = bitRead(pattern, i);
    
    digitalWrite(LED_PINS[i], analogValue);
    
  }

}