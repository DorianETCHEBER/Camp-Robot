/* ajout des bibliotheques */
#include <Arduino.h>

/* Initialisation des définition*/
void affSerialTime(void);

void aff7seg(long nb);
void zero();
void un();
void deux();
void trois();
void quatre();
void cinque();
void six();
void sept();
void huit();
void neuf();

/* Initialisation variables/constantes afficheur 7 segments */

/* map */
#define pin_1  22
#define pin_A  23
#define pin_F  24
#define pin_2  25
#define pin_3  26
#define pin_B  27
#define pin_E  28
#define pin_D  29
#define pin_DP 30
#define pin_C  31
#define pin_G  32
#define pin_4  33

int digit[4] = {0,0,0,0};

/* Initialisation variables/constantes timer */
long time_ms = 0;

void setup() {
  
  /* initialisation afficheurs 7 segements */
  for (int i = 0; i <= 12 ; i++){
    pinMode((22+i),OUTPUT);
  }

  /* initialisation Timer */
  TCCR1A = 0x00;
  TCCR1B = 0x03;
  TCNT1 = 3035;

  /* Initialisation port série */
  Serial.begin(9600);
  Serial.println("Initialisation Termine");
}

void loop() {
  if ((TIFR1 & 0x01) != 0){
    
    /* 65535 - 3035 = 62500 --> 0.004ms * 62500 = 250 ms */
    TCNT1 = 3035;

    /* affichage de l'horloge */
    time_ms +=252;
    affSerialTime();

    /* RAZ flag */
    TIFR1 += TOV1;
  }
  aff7seg(time_ms);
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

void aff7seg(long nb){

  digit[3] = (nb/1000)%10;
  digit[2] = (nb/10000)%6;
  digit[1] = (nb/60000)%10;
  digit[0] = (nb/600000)%6;

  for (int digitn = 0; digitn <= 3; digitn++){
    digitalWrite(pin_1,1);
    digitalWrite(pin_2,1);
    digitalWrite(pin_3,1);
    digitalWrite(pin_4,1);
    digitalWrite(pin_DP,0);

    switch (digitn){
      case 0 : digitalWrite(pin_1,0); break;
      case 1 : digitalWrite(pin_2,0); digitalWrite(pin_DP,1); break;
      case 2 : digitalWrite(pin_3,0); break;
      case 3 : digitalWrite(pin_4,0); break;
    }
    switch(digit[digitn]){
      default : zero(); break;
      case 0 : zero(); break;
      case 1 : un(); break;
      case 2 : deux(); break;
      case 3 : trois(); break;
      case 4 : quatre(); break;
      case 5 : cinque(); break;
      case 6 : six(); break;
      case 7 : sept(); break;
      case 8 : huit(); break;
      case 9 : neuf(); break;
    }
    delay(3);
  }
}

void zero(){
  /*
   _
  | |
  |_|
*/
  digitalWrite(pin_A,1);
  digitalWrite(pin_B,1);
  digitalWrite(pin_C,1);
  digitalWrite(pin_D,1);
  digitalWrite(pin_E,1);
  digitalWrite(pin_F,1);
  digitalWrite(pin_G,0);
}
void un(){
  /*
    
    |
    |
*/

  digitalWrite(pin_A,0);
  digitalWrite(pin_B,1);
  digitalWrite(pin_C,1);
  digitalWrite(pin_D,0);
  digitalWrite(pin_E,0);
  digitalWrite(pin_F,0);
  digitalWrite(pin_G,0);
}

void deux(){
  /*
   _
   _|
  |_
*/

  digitalWrite(pin_A,1);
  digitalWrite(pin_B,1);
  digitalWrite(pin_C,0);
  digitalWrite(pin_D,1);
  digitalWrite(pin_E,1);
  digitalWrite(pin_F,0);
  digitalWrite(pin_G,1);
}

void trois(){
  /*
   _
   _|
   _|
*/

  digitalWrite(pin_A,1);
  digitalWrite(pin_B,1);
  digitalWrite(pin_C,1);
  digitalWrite(pin_D,1);
  digitalWrite(pin_E,0);
  digitalWrite(pin_F,0);
  digitalWrite(pin_G,1);
}

void quatre(){
  /*
   
  |_|
    |
*/

  digitalWrite(pin_A,0);
  digitalWrite(pin_B,1);
  digitalWrite(pin_C,1);
  digitalWrite(pin_D,0);
  digitalWrite(pin_E,0);
  digitalWrite(pin_F,1);
  digitalWrite(pin_G,1);
}

void cinque(){
  /*
   _
  |_
   _|
*/

  digitalWrite(pin_A,1);
  digitalWrite(pin_B,0);
  digitalWrite(pin_C,1);
  digitalWrite(pin_D,1);
  digitalWrite(pin_E,0);
  digitalWrite(pin_F,1);
  digitalWrite(pin_G,1);
}

void six(){
  /*
   _
  |_
  |_|
*/

  digitalWrite(pin_A,1);
  digitalWrite(pin_B,0);
  digitalWrite(pin_C,1);
  digitalWrite(pin_D,1);
  digitalWrite(pin_E,1);
  digitalWrite(pin_F,1);
  digitalWrite(pin_G,1);
}

void sept(){
  /*
   _
    |
    |
*/

  digitalWrite(pin_A,1);
  digitalWrite(pin_B,1);
  digitalWrite(pin_C,1);
  digitalWrite(pin_D,0);
  digitalWrite(pin_E,0);
  digitalWrite(pin_F,0);
  digitalWrite(pin_G,0);
}

void huit(){
  /*
   _
  |_|
  |_|
*/

  digitalWrite(pin_A,1);
  digitalWrite(pin_B,1);
  digitalWrite(pin_C,1);
  digitalWrite(pin_D,1);
  digitalWrite(pin_E,1);
  digitalWrite(pin_F,1);
  digitalWrite(pin_G,1);
}

void neuf(){
  /*
   _
  |_|
   _|
*/

  digitalWrite(pin_A,1);
  digitalWrite(pin_B,1);
  digitalWrite(pin_C,1);
  digitalWrite(pin_D,1);
  digitalWrite(pin_E,0);
  digitalWrite(pin_F,1);
  digitalWrite(pin_G,1);
}