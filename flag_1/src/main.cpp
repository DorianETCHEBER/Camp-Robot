/* ajout des bibliotheques */
#include <Arduino.h>

/* Initialisation des définition*/
void affSerialTime(void);

long time_ms = 0;

void setup() {
  Serial.begin(9600);
  
  TCCR1A = 0x00;
  TCCR1B = 0x03;
  TCNT1 = 3035;
}

void loop() {
  if ((TIFR1 & 0x01) != 0){
    
    /* 65535 - 3035 = 62500 --> 0.004ms * 62500 = 250 ms */
    TCNT1 = 3035;

    /* affichage de l'horloge */
    time_ms +=250;
    affSerialTime();

    /* RAZ flag */
    TIFR1 += TOV1;
  }
}

void affSerialTime(void){
  Serial.print("horloge : ");
  Serial.print(time_ms/60000);
  Serial.print("min ");
  Serial.print((time_ms/1000)%60);
  Serial.print("sec ");
  Serial.print(time_ms%1000);
  Serial.println("millisecondes");
}