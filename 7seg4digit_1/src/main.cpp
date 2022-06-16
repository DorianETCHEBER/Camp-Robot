#include <Arduino.h>

void aff7seg(int nb);
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

/* map */
#define pin_1 22
#define pin_A 23
#define pin_F 24
#define pin_2 25
#define pin_3 26
#define pin_B 27
#define pin_E 28
#define pin_D 29
#define pin_DP 30
#define pin_C 31
#define pin_G 32
#define pin_4 33

int digit[4] = {0,0,0,0};

void setup() {
  for (int i = 0; i <= 12 ; i++){
    pinMode((22+i),OUTPUT);
  }
}

void loop() {
  aff7seg(0);
}


void aff7seg(int nb){
  digit[0] = (nb)%10;
  digit[1] = (nb/10)%10;
  digit[2] = (nb/100)%10;
  digit[3] = (nb/1000)%10;

  for (int digitn = 0; digitn <= 3; digitn++){
    digitalWrite(pin_1,1);
    digitalWrite(pin_2,1);
    digitalWrite(pin_3,1);
    digitalWrite(pin_4,1);
    switch (digitn){
      case 0 : digitalWrite(pin_1,0); break;
      case 1 : digitalWrite(pin_2,0); break;
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
    delay(5);
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