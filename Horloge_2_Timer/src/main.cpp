#include <Arduino.h>

void horloge_print(void);

int mSeconde = 0;
int seconde = 0;
int minute = 0;
int heurs = 0;

void setup() {
  

  // Fréquence à 16 000 000 Hz
  //CLKPR = 0b10000000;
  //CLKPR = 0b00000000; 

  TCCR3A = 0x00;
  TCCR3B = 0x04;

  TCNT3 = 0;
  Serial.begin(9600);
  Serial.println("Initialisation Termine");
}

void loop() {
  if ((TIFR3 & 0x01) != 0)
  {
    mSeconde += 1049;
    if (mSeconde >= 1000){
      mSeconde = mSeconde%1000;
      seconde += 1;
      if (seconde == 60){
        seconde = 0;
        minute += 1;
        if (minute == 60){
          minute = 0;
          heurs += 1;
        }
      }
      horloge_print();
    }
    bitSet(TIFR3,TOV3);
  }
}

void horloge_print(void){
  Serial.print("Horloge : ");
  Serial.print(heurs);
  Serial.print("h ");
  Serial.print(minute);
  Serial.print("min ");
  Serial.print(seconde);
  Serial.print("sec ");
  Serial.println(mSeconde);
}