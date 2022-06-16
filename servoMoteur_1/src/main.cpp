#include <Arduino.h>
#include <Servo.h>

/* Initialisation des éléments moteurs */
Servo moteur1;

#define tailleTab 4
int tabPositionMoteur[tailleTab] = {0,90,180,90};

void setup() {
  /* Initialisation moteur1 */
  moteur1.attach(22);
}

void loop() {

  for(int i =0; i < tailleTab; i++){
    moteur1.write(tabPositionMoteur[i]);
    delay(500);
  }
}