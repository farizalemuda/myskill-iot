#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper stepper1(stepsPerRevolution, 2, 3, 4, 5);
Stepper stepper2(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 20 rpm for one stepper, 90 rpm for another:
  stepper1.setSpeed(20);
  stepper2.setSpeed(90);

  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  stepper1.step(stepsPerRevolution);
  stepper2.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  stepper1.step(-stepsPerRevolution);
  stepper2.step(-stepsPerRevolution);
  delay(500);
}
