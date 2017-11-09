#include <Stepper.h>
#define STEPS 48 //Pasos del Motor

Stepper stepperHor(STEPS, 8, 9, 10, 11);
Stepper stepperVert(STEPS, 4, 5, 6, 7);

int anterior10 = 0;
int anterior11 = 0;

void setup() {
  //velocidad en RPM
  stepperHor.setSpeed(100);
  stepperVert.setSpeed(100);
}

void loop() {
  int pote10 = analogRead(0);
  int pote11 = analogRead(0);
  int pasosHor = ((pote10 - anterior10)-512);
  int pasosVert = ((pote11 - anterior10)-512);
  
  stepperHor.step(pasosHor/2);
  anterior10 = pote10;

  stepperVert.step(pasosVert/2);
  anterior11 = pote11;
}
