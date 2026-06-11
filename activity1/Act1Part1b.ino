/*
Activity 1 Part 1.b
Create a program that will light up LEDs one after the other.
are off.
*/

const int ledCount = 8;
int ledArray[ledCount] = {3, 4, 5, 6, 7, 8, 9, 10}

void setup() {
    for (int i = 0; i < ledCount; i++) {
        pinMode(ledArray[i], OUTPUT);

    }

}

void loop() {
    for (int i = 0; i < ledCount; i++) {
        digitalWrite(ledArray[i], HIGH);
        delay(500);

        digitalWrite(ledArray[i], LOW);
    }

}