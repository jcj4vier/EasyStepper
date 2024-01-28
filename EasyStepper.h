#ifndef EASYSTEPPER_H
#define EASYSTEPPER_H

#include <AccelStepper.h>

class EasyStepper {
public:
  // Constructor
  EasyStepper(byte pulPin, byte dirPin, byte limitSwitchPin, int direction = 1);

  // Function to set up the stepper motor
  void easySetup(int maxSpeed, int acceleration, int maxSteps);

  // Function to return the stepper motor to the home position using a limit switch
  void returnToHome(int maxSteps);

  // Function to move the stepper motor to a specified number of steps
  void stepperMove(int steps);

private:
  AccelStepper stepper;
  byte limitSwitchPin;
};

#endif
