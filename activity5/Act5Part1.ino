#include "api/Common.h"
#include "avr/pgmspace.h"
#include <Arduino.h>

const byte ledPins[] = {12, 11, 10};
const byte ledPinsLen = sizeof(ledPins) / sizeof(ledPins[0]);

const byte buttonPins[] = {8, 7, 6};
const byte buttonPinsLen = sizeof(buttonPins) / sizeof(buttonPins[0]);

const byte buzzerPin = 3;

unsigned long millisSinceStart;
unsigned long millisSinceLastNote;

const unsigned int alarmTempo = 138;
const int wholeNote = (60000 * 4) / alarmTempo;

const unsigned int noteREST = 0;
const unsigned int noteB4 = 494;
const unsigned int noteC5 = 523;
const unsigned int noteCS5 = 554;
const unsigned int noteD5 = 587;
const unsigned int noteDS5 = 622;
const unsigned int noteE5 = 659;
const unsigned int noteF5 = 698;
const unsigned int noteFS5 = 740;
const unsigned int noteG5 = 784;
const unsigned int noteGS5 = 831;
const unsigned int noteA5 = 880;
const unsigned int noteAS5 = 932;
const unsigned int noteB5 = 988;
const unsigned int noteC6 = 1047;

int currentNote = 0;
int noteDuration;

bool isAlarmPlaying = false;

const int mainMelody[] PROGMEM = {
  noteC5, noteD5, noteDS5, noteF5,
  noteG5, noteC6, noteAS5, noteG5, noteC5, noteG5, noteF5, noteDS5, 
  noteD5, noteC5, noteD5, noteDS5, noteF5, noteG5, noteF5, noteDS5, 
  noteD5, noteC5, noteD5, noteDS5, noteD5, noteC5, noteB4, noteD5, 
  noteC5, noteD5, noteDS5, noteF5, noteG5, noteC6, noteAS5, noteG5,
  noteC5, noteG5, noteF5, noteDS5, noteD5, noteC5, noteD5, noteDS5, 
  noteF5, noteG5, noteF5, noteDS5, noteD5, noteREST, noteDS5, noteF5, 
  noteG5
};

int mainNotes[] = {
  //beginning
  8, 8, 8, 8, 4, 8, 8, 4, 4, 8, 
  8, 8, 8, 8, 8, 8, 8, 4,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 4, 8,
  8, 4, 4, 8, 8, 8, 8, 8,
  8, 8, 8, 4, 8, 8, 8, 8,
  4, 4, 4
};

int songDuration = sizeof(mainNotes) / sizeof(mainNotes[0]);

void playAlarm();
void checkSerialReceive();
void lightUpLEDs(byte ledToBlink);
void sendSerialMessage();


void setup() {

    Serial.begin(9600);

    for (int i = 0; i < ledPinsLen; i++) {
        pinMode(ledPins[i], OUTPUT);

    }

    for (int i = 0; i < ledPinsLen; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);

    }

    pinMode(buzzerPin, OUTPUT);

}

void loop() {
    millisSinceStart = millis();

    checkSerialReceive();

    sendSerialMessage();
    
    if (isAlarmPlaying) {
        playAlarm();

    }
    
}

void checkSerialReceive() {
    char serialInputValue = Serial.read();

    switch (serialInputValue) {
        case 'A':
            isAlarmPlaying = false;
            lightUpLEDs(ledPins[0]);

        break;
        case 'B':
            isAlarmPlaying = false;
            lightUpLEDs(ledPins[1]);

        break;
        case 'C':
            isAlarmPlaying = false;
            lightUpLEDs(ledPins[2]);

        break;
        case 'D':
            isAlarmPlaying = true;
            lightUpLEDs(0);
        break;

    }

}

void playAlarm () {

    if (millisSinceStart - millisSinceLastNote > noteDuration) {
        mainNotes[currentNote] > 0 ? noteDuration = wholeNote / mainNotes[currentNote] : noteDuration = (wholeNote / (abs(mainNotes[currentNote]))) * 1.5;

        tone(buzzerPin, pgm_read_word(&mainMelody[currentNote]), noteDuration * 0.9);

        if (currentNote >= songDuration) {
            currentNote = 0;
            isAlarmPlaying = false;

        } else {
            currentNote++;

        }

        millisSinceLastNote = millisSinceStart;
    }

}

void lightUpLEDs(byte ledToBlink) {
    for (int i; i < ledPinsLen; i++) {
        if (ledPins[i] == ledToBlink) {
            digitalWrite(ledToBlink, HIGH);

        } else {
            digitalWrite(ledPins[i], LOW);

        }

    }

}

void sendSerialMessage() {
    for (int i = 0; i < buttonPinsLen; i++) {
        if (!digitalRead(buttonPins[i])) {
            switch (i) {
                case 0:
                    Serial.println("Goltev");

                break;
                case 1:
                    Serial.println("Hello World");

                break;
                case 2:
                    Serial.println("We will be the last to suffer.");

                break;
            
            }

        }

    }

}