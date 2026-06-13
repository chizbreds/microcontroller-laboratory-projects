#include <Arduino.h>
#include "api/Common.h"

const int blinkDelay = 250;

int buttonLeftPin = 6;
int buttonMiddlePin = 5;
int buttonRightPin = 3;

int buzzerPin = 2;

int redLEDPin = 12;
int blueLEDPin = 10;
int greenLEDPin = 8;

int LEDPinArray[3] = {redLEDPin, blueLEDPin, greenLEDPin};

void blink() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LEDPinArray[i], HIGH);
  }

  delay(blinkDelay);

  for (int i = 0; i < 3; i++) {
    digitalWrite(LEDPinArray[i], LOW);
  }

}

void runningLight() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LEDPinArray[i], HIGH);
    delay(blinkDelay);
    digitalWrite(LEDPinArray[i], LOW);

  }

}

void buzzBuzzer() {
  tone(buzzerPin, 1900);
  delay(blinkDelay);

  tone(buzzerPin, 0);
  delay(blinkDelay);

}

void setup() {
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

  pinMode(buttonLeftPin, INPUT);
  pinMode(buttonMiddlePin, INPUT);
  pinMode(buttonRightPin, INPUT);

}

void loop() {
  if (digitalRead(buttonLeftPin)){
    blink();

  } else if (digitalRead(buttonMiddlePin)) {
    for (int i = 0; i < 3; i++) {
      runningLight();

    }

  } else if (digitalRead(buttonRightPin)) {
    for (int i = 0; i < 5; i++) {
      buzzBuzzer();
    }

  }

}

