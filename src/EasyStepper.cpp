#include "EasyStepper.h"

EasyStepper::EasyStepper(byte pulPin, byte dirPin, byte limitSwitchPin, int direction)
  : stepper(AccelStepper::DRIVER, pulPin, dirPin) {
  this->limitSwitchPin = limitSwitchPin;
  stepper.setPinsInverted(false, false, true); // Invert the direction and enable the driver
  stepper.setAcceleration(0); // Default acceleration value, can be adjusted
  stepper.setMaxSpeed(1000.0); // Default max speed value, can be adjusted
  stepper.setCurrentPosition(0);
  pinMode(limitSwitchPin, INPUT_PULLUP); // Assuming the limit switch is connected to ground when pressed
}

void EasyStepper::easySetup(int maxSpeed, int acceleration, int maxSteps) {
  stepper.setMaxSpeed(maxSpeed);
  stepper.setAcceleration(acceleration);
  stepper.setCurrentPosition(0);
}

void EasyStepper::returnToHome(int maxSteps) {
  if (digitalRead(limitSwitchPin) == LOW) {
    stepper.moveTo(maxSteps);
    while (digitalRead(limitSwitchPin) == LOW) {
      stepper.run();
      delay(1);
    }
  }
  stepper.setCurrentPosition(0);
}

void EasyStepper::stepperMove(int steps) {
  stepper.moveTo(steps);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
    delay(1);
  }
}
