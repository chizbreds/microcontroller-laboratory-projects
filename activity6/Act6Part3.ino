#include <Arduino.h>
#include "api/Common.h"
#include <Servo.h>


const byte POT_PIN = A0;
const byte SERVO_PIN = 3;

Servo serv;
int pot_value;

void setup() {
  pinMode(SERVO_PIN, OUTPUT);

  serv.attach(SERVO_PIN);

  pot_value = analogRead(POT_PIN);
}

void loop() {
  pot_value = analogRead(POT_PIN);
  int servo_value = map(pot_value, 0, 1023, 0, 180);
  serv.write(servo_value);

}