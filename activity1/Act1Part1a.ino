/*
Activity 1 Part 1.a
Create a program that will light up a certain LED in different patterns where the
LEDs will light up one by one until are all lit then turn off one by one until all
are off.
*/

const int ledCount = 8;
int ledArray[ledCount] = {3, 4, 5, 6, 7, 8, 9, 10}

bool goingUp = true;

void setup() {
    for (int i = 0; i < ledCount; i++) {
        pinMode(ledArray[i], OUTPUT);

    }

}

void loop() {

    if (goingUp) {
        for (int i = 1; i < ledCount; i++) {
            digitalWrite(ledArray[i], HIGH);
            delay(500);

            digitalWrite(ledArray[i], LOW);

        }

        goingUp = false;

    } else {
        for (int i = ledCount - 2; i >= 0; i--) {
            digitalWrite(ledArray[i], HIGH);
            delay(500);

            digitalWrite(ledArray[i], LOW);


        }

        goingUp = true;
    }


}