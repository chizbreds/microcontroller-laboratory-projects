#include "api/Common.h"
#include "api/Print.h"
#include <Arduino.h>

const byte BUTTON_COUNT = 4;
const byte BUTTON_PINS[BUTTON_COUNT] = {2, 3, 4, 5};

const byte LED_COUNT = 7;
const byte LED_PINS[LED_COUNT] = {6, 7, 8, 9, 10, 11, 12};

const bool DIGIT_0[LED_COUNT] = {LOW, LOW, LOW, LOW, LOW, LOW, HIGH};
const bool DIGIT_1[LED_COUNT] = {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH,};
const bool DIGIT_2[LED_COUNT] = {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW};
const bool DIGIT_3[LED_COUNT] = {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW};
const bool DIGIT_4[LED_COUNT] = {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW};
const bool DIGIT_5[LED_COUNT] = {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW};
const bool DIGIT_6[LED_COUNT] = {LOW, HIGH, LOW, LOW, LOW, LOW, LOW};
const bool DIGIT_7[LED_COUNT] = {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH};
const bool DIGIT_8[LED_COUNT] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW};
const bool DIGIT_9[LED_COUNT] = {LOW, LOW, LOW, LOW, HIGH, LOW, LOW};
const bool DIGIT_A[LED_COUNT] = {LOW, LOW, LOW, HIGH, LOW, LOW, LOW};
const bool DIGIT_B[LED_COUNT] = {HIGH, HIGH, LOW, LOW, LOW, LOW, LOW};
const bool DIGIT_C[LED_COUNT] = {LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH};
const bool DIGIT_D[LED_COUNT] = {HIGH, LOW, LOW, LOW, LOW, HIGH, LOW};
const bool DIGIT_E[LED_COUNT] = {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW};
const bool DIGIT_F[LED_COUNT] = {LOW, HIGH, HIGH, HIGH, LOW, LOW, LOW};


byte isButtonActive[LED_COUNT] = {LOW, LOW, LOW, LOW};
byte buttonState[BUTTON_COUNT];
byte lastButtonState[BUTTON_COUNT] = {LOW, LOW, LOW, LOW};

unsigned long lastDebounceTime[LED_COUNT] = {0, 0, 0, 0};
const unsigned long debounceDelay = 25;

byte value = 0;

void buttonDebouncing();
void outputLEDValue();
void clearLED();
void printLED();

void setup() {

  for (byte i = 0; i < BUTTON_COUNT; i++) {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);

  }

  for (byte i = 0; i < LED_COUNT; i++) {
    pinMode(LED_PINS[i], OUTPUT);

    digitalWrite(LED_PINS[i], HIGH);

  }


}

void loop() {
  buttonDebouncing();

  outputLEDValue();

}

void printLED(const bool PRINTED_DIGIT[]) {
  for (byte i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_PINS[i], PRINTED_DIGIT[i]);

  }

}

void outputLEDValue() {

  clearLED();

  if (!isButtonActive[0] && !isButtonActive[1] && !isButtonActive[2] && !isButtonActive[3]) {
    printLED(DIGIT_0);

  } else if (isButtonActive[0] && !isButtonActive[1] && !isButtonActive[2] && !isButtonActive[3]) {
    printLED(DIGIT_1);
    
  } else if (!isButtonActive[0] && isButtonActive[1] && !isButtonActive[2] && !isButtonActive[3]) {
    printLED(DIGIT_2);

  } else if (isButtonActive[0] && isButtonActive[1] && !isButtonActive[2] && !isButtonActive[3]) {
    printLED(DIGIT_3);

  } else if (!isButtonActive[0] && !isButtonActive[1] && isButtonActive[2] && !isButtonActive[3]) {
    printLED(DIGIT_4);

  } else if (isButtonActive[0] && !isButtonActive[1] && isButtonActive[2] && !isButtonActive[3]) {
    printLED(DIGIT_5);
    
  } else if (!isButtonActive[0] && isButtonActive[1] && isButtonActive[2] && !isButtonActive[3]) {
    printLED(DIGIT_6);

  } else if (isButtonActive[0] && isButtonActive[1] && isButtonActive[2] && !isButtonActive[3]) {
    printLED(DIGIT_7);

  } else if (!isButtonActive[0] && !isButtonActive[1] && !isButtonActive[2] && isButtonActive[3]) {
    printLED(DIGIT_8);
    
  } else if (isButtonActive[0] && !isButtonActive[1] && !isButtonActive[2] && isButtonActive[3]) {
    printLED(DIGIT_9);

  } else if (!isButtonActive[0] && isButtonActive[1] && !isButtonActive[2] && isButtonActive[3]) {
    printLED(DIGIT_A);

  } else if (isButtonActive[0] && isButtonActive[1] && !isButtonActive[2] && isButtonActive[3]) {
    printLED(DIGIT_B);

  } else if (!isButtonActive[0] && !isButtonActive[1] && isButtonActive[2] && isButtonActive[3]) {
    printLED(DIGIT_C);

  } else if (isButtonActive[0] && !isButtonActive[1] && isButtonActive[2] && isButtonActive[3]) {
    printLED(DIGIT_D);
    
  } else if (!isButtonActive[0] && isButtonActive[1] && isButtonActive[2] && isButtonActive[3]) {
    printLED(DIGIT_E);

  } else {
    printLED(DIGIT_F);

  }


}

void clearLED() {
  for (byte i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_PINS[i], HIGH);

  }

}

void buttonDebouncing() {
  for (byte i = 0; i < BUTTON_COUNT; i++) {
    int reading = digitalRead(BUTTON_PINS[i]);

    if (reading != lastButtonState[i]) {
      lastDebounceTime[i] = millis();

    }

    if ((millis() - lastDebounceTime[i]) > debounceDelay) {

      if (reading != buttonState[i]) {
        buttonState[i] = reading;

        if (buttonState[i] == LOW) {

          isButtonActive[i] = !isButtonActive[i];

        }

      }

    }

    lastButtonState[i] = reading;

  }

}