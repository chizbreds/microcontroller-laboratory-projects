#include <Arduino.h>
#include "api/Common.h"

const int LED_COUNT = 4;
const int LED_ARRAY[LED_COUNT] = {8, 6, 4, 2};

int counter = 0;
int COUNTER_MAX = 15;

void blinkLEDArray() {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_ARRAY[i], bitRead(counter, LED_COUNT - i - 1));

  }

}

void setup() {
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(LED_ARRAY[i], OUTPUT);

  }

}

void loop() {
  if (counter > COUNTER_MAX) {
    blinkLEDArray();
    delay(500);

    counter = 0;
  } else {
    blinkLEDArray();
    delay(500);

    counter++;
  }
  

}

