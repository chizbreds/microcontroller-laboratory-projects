#include "api/Common.h"
#include <Arduino.h>

const int POT_PIN = A0; 
const int LED_PINS[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};

const int LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

int mappedValue = 0;
int sensorValue = 0;
int previousMappedValue = 0;

void turnOnLED();
void turnOffLED();

void setup() {
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(LED_PINS[i], OUTPUT);

    digitalWrite(LED_PINS[i], LOW);

  }

}

void loop() {
  sensorValue = analogRead(POT_PIN);

  mappedValue = map(sensorValue, 0 , 1023, 0, 9);

  if (mappedValue != previousMappedValue) {
    turnOffLED();

    turnOnLED();
  }

  previousMappedValue = mappedValue;

}

void turnOffLED() {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_PINS[i], LOW);

  }

}

void turnOnLED() {

  for (int i = 0; i < mappedValue + 1; i++) {
    digitalWrite(LED_PINS[i], HIGH);

  }

}