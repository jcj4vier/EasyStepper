#include <EasyStepper.h>

// Define pins and parameters for x-axis stepper motor
const byte XPUL_PIN = 2;
const byte XDIR_PIN = 5;
const byte XLIMITSWITCH_PIN = 9;
const int XMAX_SPEED = 1000; // Adjust as needed
const int XACCELERATION = 500; // Adjust as needed
const int XMAX_STEPS = 2000; // Adjust as needed

// Define pins and parameters for y-axis stepper motor
const byte YPUL_PIN = 3;
const byte YDIR_PIN = 6;
const byte YLIMITSWITCH_PIN = 10;
const int YMAX_SPEED = 800; // Adjust as needed
const int YACCELERATION = 400; // Adjust as needed
const int YMAX_STEPS = 1500; // Adjust as needed

// Define pins and parameters for z-axis stepper motor
const byte ZPUL_PIN = 4;
const byte ZDIR_PIN = 7;
const byte ZLIMITSWITCH_PIN = 11;
const int ZMAX_SPEED = 1200; // Adjust as needed
const int ZACCELERATION = 600; // Adjust as needed
const int ZMAX_STEPS = 2500; // Adjust as needed

// Create EasyStepper objects for x, y, and z axes
EasyStepper xAxis(XPUL_PIN, XDIR_PIN, XLIMITSWITCH_PIN);
EasyStepper yAxis(YPUL_PIN, YDIR_PIN, YLIMITSWITCH_PIN);
EasyStepper zAxis(ZPUL_PIN, ZDIR_PIN, ZLIMITSWITCH_PIN);

void setup() {
  // Set up each axis
  xAxis.easySetup(XMAX_SPEED, XACCELERATION, XMAX_STEPS);
  yAxis.easySetup(YMAX_SPEED, YACCELERATION, YMAX_STEPS);
  zAxis.easySetup(ZMAX_SPEED, ZACCELERATION, ZMAX_STEPS);

  // Return each axis to home position
  xAxis.returnToHome(XMAX_STEPS);
  yAxis.returnToHome(YMAX_STEPS);
  zAxis.returnToHome(ZMAX_STEPS);
}

void loop() {
  // Move each axis to a specific position
  xAxis.stepperMove(500); // Move x-axis to position 500 steps
  yAxis.stepperMove(800); // Move y-axis to position 800 steps
  zAxis.stepperMove(1200); // Move z-axis to position 1200 steps

  // Additional logic or movement as needed in your application
}

