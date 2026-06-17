#include "api/Common.h"
#include <Arduino.h>

const int POT_PIN = A0; 
const int LED_PINS[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};

const int LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

int mappedValue = 0;
int sensorValue = 0;
int previousMappedValue = 0;

void turnOffLED();
void turnOnLED();

void setup() {
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(LED_PINS[i], OUTPUT);

    digitalWrite(LED_PINS[i], LOW);
  }

  Serial.begin(9600);

}

void loop() {
  sensorValue = analogRead(POT_PIN);

  mappedValue = map(sensorValue, 0 , 1023, 0, 10);

  if (mappedValue == 10) {

    mappedValue -= 1;
  }

  Serial.print("Analog Value: ");
  Serial.print(sensorValue);


  Serial.print("Mapped Value: ");
  Serial.println(mappedValue);

  if (mappedValue != previousMappedValue) {
    turnOffLED();

    turnOnLED();

    previousMappedValue = mappedValue;
  }

}

void turnOffLED() {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_PINS[i], LOW);

  }

}

void turnOnLED() {
  digitalWrite(LED_PINS[mappedValue], HIGH);

}