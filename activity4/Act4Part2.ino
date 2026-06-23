#include "api/Common.h"
#include <Arduino.h>

const byte leftMotorDirectionPin = 3;
const byte rightMotorDirectionPin = 2;

const byte leftButtonPin = 12;
const byte rightButtonPin = 11;

const int potsPin = A2;
const byte motorSpeedPin = 6;

unsigned long msSinceStart = 0;

unsigned long msSinceLastSerialWrite = 0;
const unsigned long SERIAL_WRITE_INTERVAL = 75;

bool isLeftButtonOn = false;
bool isRightButtonOn = false;

int potentiometerValue;
bool isButtonPressed, isRightButtonPressed;

void uploadSerialData();
void readAndSetButtonData();

void setup() {

    analogWriteResolution(10);
    analogReadResolution(10);

    Serial.begin(9600);

    pinMode(leftMotorDirectionPin, OUTPUT);
    pinMode(rightMotorDirectionPin, OUTPUT);

    pinMode(leftButtonPin, INPUT_PULLUP);
    pinMode(rightButtonPin, INPUT_PULLUP);

}

void loop() {
    msSinceStart = millis();

    readAndSetButtonData();

    analogWrite(motorSpeedPin, analogRead(potsPin));

    if (msSinceStart - msSinceLastSerialWrite > SERIAL_WRITE_INTERVAL) {
        uploadSerialData();


        msSinceLastSerialWrite = msSinceStart;
    }

    
}

void uploadSerialData() {
    Serial.print("Pots Value: ");
    Serial.println(analogRead(potsPin));

}

void readAndSetButtonData() {

    if (isLeftButtonOn != digitalRead(leftButtonPin) || isRightButtonOn != digitalRead(rightButtonPin)) {
        isLeftButtonOn = (!digitalRead(leftButtonPin)) ? true : false;
        isRightButtonOn = (!digitalRead(rightButtonPin)) ? true : false;

        digitalWrite(leftMotorDirectionPin, isLeftButtonOn);
        digitalWrite(rightMotorDirectionPin, isRightButtonOn);

    }


}
