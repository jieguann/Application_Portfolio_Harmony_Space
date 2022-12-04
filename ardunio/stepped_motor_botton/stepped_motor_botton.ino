#include <Stepper.h>

const int stepsPerRevolution = 64;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 14, 12, 13, 15);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(200);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:



  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
    myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
    myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
    myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
    myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
    myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
    myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);
   myStepper.step(-200);
  delay(100);


    myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
     myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
   myStepper.step(200);
  delay(100);
  
}
