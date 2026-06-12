#include <Arduino.h>

const int ledCount = 8;
const int ledDelay = 100;

int ledArray[ledCount] = {9, 8, 7, 6, 5, 4, 3, 2};


bool isTurningOn = true;

void setup() {

  for (int i = 0; i < ledCount; i++) {
    pinMode(ledArray[i], OUTPUT);

  }

}

void loop() {

  if (isTurningOn) {
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(ledArray[i], HIGH);

      delay(ledDelay);

    }

    isTurningOn = false;

  } else {
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(ledArray[i], LOW);

      delay(ledDelay);

    }

    isTurningOn = true;

  }

}