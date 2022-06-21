#include <Arduino.h>

bool modifie_etat(bool etat);
void clignotement_led(void);

#define led_1 0
#define bouton 1
bool etat_led = 0;

void setup() {
  pinMode(led_1, OUTPUT);
  pinMode(bouton, INPUT);
}

void loop() {
  if (digitalRead(bouton) == 1){
    etat_led = modifie_etat(etat_led);
    while (digitalRead(bouton) == 0);
  }
  if(etat_led == 1){
    clignotement_led();
  }
}

bool modifie_etat(bool etat){
  return (etat+1);
}

void clignotement_led(void){
  digitalWrite(led_1,1);
  delay(200);
  digitalWrite(led_1,0);
  delay(200);
}