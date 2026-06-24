#include "api/Common.h"
#include <Arduino.h>

const byte BUTTON_PINS[] = {2, 3, 4, 5};
const byte BUTTON_PINS_COUNT = sizeof(BUTTON_PINS) / sizeof(BUTTON_PINS[0]);

const byte SEVEN_SEGMENT_PINS[] = {12, 11, 8, 7, 6, 9, 10};
const byte SEVEN_SEGMENT_PINS_COUNT = sizeof(SEVEN_SEGMENT_PINS) / sizeof(SEVEN_SEGMENT_PINS[0]);

const byte DIGIT_0 = 0b0000001;
const byte DIGIT_1 = 0b1001111;
const byte DIGIT_2 = 0b0010010;
const byte DIGIT_3 = 0b0000110;
const byte DIGIT_4 = 0b1001100;
const byte DIGIT_5 = 0b0100100;
const byte DIGIT_6 = 0b0100000;
const byte DIGIT_7 = 0b0001111;
const byte DIGIT_8 = 0b0000000;
const byte DIGIT_9 = 0b0000100;
const byte DIGIT_A = 0b0001000;
const byte DIGIT_B = 0b1100000;
const byte DIGIT_C = 0b0110001;
const byte DIGIT_D = 0b1000010;
const byte DIGIT_E = 0b0110000;
const byte DIGIT_F = 0b0111000;

const byte HEX_DIGITS[] = {
    DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4, DIGIT_5, DIGIT_6, DIGIT_7, DIGIT_8, DIGIT_9,
    DIGIT_A, DIGIT_B, DIGIT_C, DIGIT_D, DIGIT_E, DIGIT_F
};

const byte HEX_DIGITS_COUNT = sizeof(HEX_DIGITS) / sizeof(HEX_DIGITS[0]);

byte buttonValues = 0b0000;

void outputHexadecimal(char digit);
void printHexadecimalFromSerialRead();
void printHexadecimalFromButtons();

void setup() {
    for (int i = 0; i < BUTTON_PINS_COUNT; i++) {
        pinMode(BUTTON_PINS[i], INPUT_PULLUP);

    }

    for (int i = 0; i < SEVEN_SEGMENT_PINS_COUNT; i++) {
        pinMode(SEVEN_SEGMENT_PINS[i], OUTPUT);

    }

    Serial.begin(9600);

}

void loop() {
    printHexadecimalFromSerialRead();

    printHexadecimalFromButtons();

}


void outputHexadecimal(char digit) {
    for (int i = 0; i < SEVEN_SEGMENT_PINS_COUNT; i++) {
        bool currentBit = bitRead(digit, i);

        digitalWrite(SEVEN_SEGMENT_PINS[i], currentBit);

    }

}

void printHexadecimalFromSerialRead() {
    char read_character = Serial.read();
    
    switch (read_character) {
        case '0':
            outputHexadecimal(HEX_DIGITS[0]);

        break;
        case '1':
            outputHexadecimal(HEX_DIGITS[1]);

        break;
        case '2':
            outputHexadecimal(HEX_DIGITS[2]);

        break;
        case '3':
            outputHexadecimal(HEX_DIGITS[3]);

        break;
        case '4':
            outputHexadecimal(HEX_DIGITS[4]);

        break;
        case '5':
            outputHexadecimal(HEX_DIGITS[5]);

        break;
        case '6':
            outputHexadecimal(HEX_DIGITS[6]);

        break;
        case '7':
            outputHexadecimal(HEX_DIGITS[7]);

        break;
        case '8':
            outputHexadecimal(HEX_DIGITS[8]);

        break; 
        case '9':
            outputHexadecimal(HEX_DIGITS[9]);

        break;
        case 'A':
            outputHexadecimal(HEX_DIGITS[10]);

        break;
        case 'B':
            outputHexadecimal(HEX_DIGITS[11]);

        break;
        case 'C':
            outputHexadecimal(HEX_DIGITS[12]);

        break;
        case 'D':
            outputHexadecimal(HEX_DIGITS[13]);

        break;
        case 'E':
            outputHexadecimal(HEX_DIGITS[14]);

        break;
        case 'F':
            outputHexadecimal(HEX_DIGITS[15]);

        break;
    }

}

void printHexadecimalFromButtons() {
    for (int i = 0; i < BUTTON_PINS_COUNT; i++) {
        bool isButtonOn = !digitalRead(BUTTON_PINS[i]);
        bitWrite(buttonValues, i, isButtonOn);

    }

    Serial.println(buttonValues, HEX);

}
