#include "api/Common.h"
#include <Arduino.h>

const int POT_PIN = A0; 

const byte LED_PINS[] = {5, 4, 8, 9, 10, 6, 7};
const byte LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

int mappedValue = 0;
int sensorValue = 0;
int previousMappedValue = 0;

const byte DIGIT_0 = 0b0111111;
const byte DIGIT_1 = 0b0000110;
const byte DIGIT_2 = 0b1011011;
const byte DIGIT_3 = 0b1001111;
const byte DIGIT_4 = 0b1100110;
const byte DIGIT_5 = 0b1101101;
const byte DIGIT_6 = 0b1111101;
const byte DIGIT_7 = 0b0000111;
const byte DIGIT_8 = 0b1111111;
const byte DIGIT_9 = 0b1101111;

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
        turnOnLED(DIGIT_0);
        break;

      case 1:
        turnOnLED(DIGIT_1);

        break;

      case 2:
        turnOnLED(DIGIT_2);
        break;

      case 3:
        turnOnLED(DIGIT_3);
        break;

      case 4:
        turnOnLED(DIGIT_4);
        break;

      case 5:
        turnOnLED(DIGIT_5);
        break;

      case 6:
        turnOnLED(DIGIT_6);
        break;

      case 7:
        turnOnLED(DIGIT_7);
        break;

      case 8:
        turnOnLED(DIGIT_8);
        break;

      case 9:
        turnOnLED(DIGIT_9);
        break;


      default:
        break;

    }

    previousMappedValue = mappedValue;
  }

}

void mapAnalogValues() {
  sensorValue = analogRead(POT_PIN);

  mappedValue = map(sensorValue, 0 , 1023, 0, 10);
  
  if (mappedValue == 10) {
    mappedValue = 9;

  }

}

void clearLEDs() {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_PINS[i], LOW);

  }

}

void turnOnLED(int pattern) {

  for (int i = 7; i >= 0; i--) {
    int binaryValue = bitRead(pattern, i);
    
    digitalWrite(LED_PINS[i], !binaryValue);
    
  }

}