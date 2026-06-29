#include <Arduino.h>
#include "api/Common.h"
#include "pins_arduino.h"
#include <L293D.h>

const byte POTENTIOMETER_PIN = A0;
const byte MOTOR_SPEED_PIN = 3;
const byte MOTOR_INPUT_1_PIN = 7;
const byte MOTOR_INPUT_2_PIN = 6;

bool isMotorSpinCounterClockwise = false;
bool isMotorOn = false;

int potentiometerValue;

void setMotorDirection();

L293D motor(MOTOR_INPUT_1_PIN, MOTOR_INPUT_2_PIN, MOTOR_SPEED_PIN);

void setup() {
  Serial.begin(9600);

  motor.begin(true);

  pinMode(POTENTIOMETER_PIN, INPUT);

}

void loop() {

  setMotorDirection();
  potentiometerValue = map(analogRead(POTENTIOMETER_PIN), 0, 1024, 0, 100);

  Serial.println(potentiometerValue);

  if (!isMotorOn) {
    motor.SetMotorSpeed(0);

  } else if (isMotorSpinCounterClockwise) {
    motor.SetMotorSpeed(potentiometerValue * -1);

  } else {
    motor.SetMotorSpeed(potentiometerValue);

  }

}

void setMotorDirection() {

  char serialValue = Serial.read();

  switch (serialValue) {
    case 'A':
      isMotorOn = true;
      isMotorSpinCounterClockwise = true;

    break;

    case 'B':
      isMotorOn = true;
      isMotorSpinCounterClockwise = false;

    break;

    case 'C':
      isMotorOn = false;

    break;

    default:
    break;

  }

}