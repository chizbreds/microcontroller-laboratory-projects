#include <Arduino.h>
#include "api/Common.h"

const int ledCount = 7;
const int blinkDelay = 500;

int ledArray[ledCount] = {8, 7, 6, 5, 4, 3, 2};

bool digit_0[ledCount] = {LOW, LOW, LOW, LOW, LOW, LOW, HIGH};
bool digit_1[ledCount] = {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH,};
bool digit_2[ledCount] = {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW};
bool digit_3[ledCount] = {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW};
bool digit_4[ledCount] = {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW};
bool digit_5[ledCount] = {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW};
bool digit_6[ledCount] = {LOW, HIGH, LOW, LOW, LOW, LOW, LOW};
bool digit_7[ledCount] = {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH};
bool digit_8[ledCount] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW};
bool digit_9[ledCount] = {LOW, LOW, LOW, LOW, HIGH, LOW, LOW};
bool digit_a[ledCount] = {LOW, LOW, LOW, HIGH, LOW, LOW, LOW};
bool digit_b[ledCount] = {HIGH, HIGH, LOW, LOW, LOW, LOW, LOW};
bool digit_c[ledCount] = {HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW};
bool digit_d[ledCount] = {HIGH, LOW, LOW, LOW, LOW, HIGH, LOW};
bool digit_e[ledCount] = {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW};
bool digit_f[ledCount] = {LOW, HIGH, HIGH, HIGH, LOW, LOW, LOW};

void clearDisplay() {
  for (int i = 0; i <= ledCount; i++) {
    digitalWrite(ledArray[i], HIGH);

  }

}

void showDigit(bool digit[ledCount]) {

  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledArray[i], digit[i]);

  }

}

void setup() {

  for (int i = 0; i < ledCount; i++) {
    pinMode(ledArray[i], OUTPUT);

  }

}

void loop() {
  showDigit(digit_0);
  delay(blinkDelay);

  clearDisplay();
  delay(blinkDelay);

  showDigit(digit_1);
  delay(blinkDelay);

  clearDisplay();
  delay(blinkDelay);

  showDigit(digit_2);
  delay(blinkDelay);

  clearDisplay();
  delay(blinkDelay);
   
  showDigit(digit_3);
  delay(blinkDelay);

  clearDisplay();
  delay(blinkDelay);

  showDigit(digit_4);
  delay(blinkDelay);

  clearDisplay();
  delay(blinkDelay);

  showDigit(digit_5);
  delay(blinkDelay);

  clearDisplay();
  delay(blinkDelay);

  showDigit(digit_6);
  delay(blinkDelay);

  clearDisplay();
  delay(blinkDelay);
  
  showDigit(digit_7);
  delay(blinkDelay);

  clearDisplay();
  delay(blinkDelay);

  showDigit(digit_8);
  delay(blinkDelay);

  clearDisplay();
  delay(blinkDelay);
 
  showDigit(digit_9);
  delay(blinkDelay);

  clearDisplay();
  delay(blinkDelay);

}

