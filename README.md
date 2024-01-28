# EasyStepper Library

## Overview

The EasyStepper library is designed to simplify the programming of stepper motors using the AccelStepper library. It provides a set of functions for easy setup, homing, and movement of stepper motors, along with safety features and straightforward syntax.

## Features

- **Simple Syntax:** Easy to use functions for stepper motor setup and movement.
- **Safety Features:** Integration with limit switches for safer motor control.
- **Advanced Functions:** Includes functions for homing and moving to specific positions.

## Installation

1. Download the EasyStepper library ZIP file.
2. In the Arduino IDE, go to `Sketch -> Include Library -> Add .ZIP Library...`.
3. Select the downloaded ZIP file.

## Getting Started

```cpp
#include <EasyStepper.h>

// Define pins and parameters for x-axis stepper motor
const byte XPUL_PIN = 2;
const byte XDIR_PIN = 5;
const byte XLIMITSWITCH_PIN = 9;
const int XMAX_SPEED = 1000;
const int XACCELERATION = 500;
const int XMAX_STEPS = 2000;

// Create EasyStepper object for x-axis
EasyStepper xAxis(XPUL_PIN, XDIR_PIN, XLIMITSWITCH_PIN);

void setup() {
  // Set up x-axis
  xAxis.easySetup(XMAX_SPEED, XACCELERATION, XMAX_STEPS);
  xAxis.returnToHome(XMAX_STEPS);
}

void loop() {
  // Move x-axis to a specific position
  xAxis.stepperMove(500);
}
