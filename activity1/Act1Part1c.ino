#include <Arduino.h>

const int ledCount = 8;
int ledArray[ledCount] = {9, 8, 7, 6, 5, 4, 3, 2};

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledArray[i], OUTPUT);

  }

}

void loop() {
  for (int i = 0; i < ledCount/2; i++) {
    digitalWrite(ledArray[i], HIGH);
    digitalWrite(ledArray[ledCount-i-1], HIGH);

    delay(500);

    digitalWrite(ledArray[i], LOW);
    digitalWrite(ledArray[ledCount-i-1],LOW);

  }

}