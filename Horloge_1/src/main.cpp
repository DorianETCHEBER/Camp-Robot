#include <Arduino.h>

void affichage_Serial(void);

int seconde = 0;
int minute = 0;
int heurs = 0;

void setup() {
  Serial.begin(9600);
  TCCR0B = 0x01;
}

void loop() {
  affichage_Serial();
  delay(100);
  seconde += 1;
  if(seconde == 60){
    minute += 1;
    seconde = 0;
    if (minute == 60){
      minute = 0;
      heurs += 1;
    }
  }
}

void affichage_Serial(void){
  Serial.print("horloge : ");
  Serial.print(heurs);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(seconde);
}