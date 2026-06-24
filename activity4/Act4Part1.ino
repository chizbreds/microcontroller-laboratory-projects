#include "api/Common.h"
#include <Arduino.h>


const byte buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

const byte buzzerPin = 13;

byte currentlyPressedButton = 0;

const byte buttonPinsLen = sizeof(buttonPins) / sizeof(buttonPins[0]);

const unsigned int buttonFrequency[buttonPinsLen] = {1046, 1175, 1318, 1397, 1568, 1760, 1979, 2093};

void setup() {

    Serial.begin(9600);

    for (int i = 0; i < buttonPinsLen; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);

    }

    pinMode(13, OUTPUT);
    

}

void loop() {
    for (int i = 0; i < buttonPinsLen; i++) {

        if (!digitalRead(buttonPins[i])) {
            tone(buzzerPin, buttonFrequency[i]);
            delay(50);

            currentlyPressedButton = buttonPins[i];

        } else if (currentlyPressedButton == buttonPins[i] && digitalRead(currentlyPressedButton)) {

            tone(buzzerPin, 0);
        }

    }

}