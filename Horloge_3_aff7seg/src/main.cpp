#include <Arduino.h>

void horloge_aff7seg(void);

int pin1 = 0x01;
int pinA = 0x01;
int pinF = 0x20;
int pin2 = 0x02;
int pin3 = 0x04;
int pinB = 0x02;

int pinE = 0x10;
int pinD = 0x08;
int pinDP = 0x80;
int pinC = 0x04;
int pinG = 0x40;
int pin4 = 0x08;

int tab7seg[10] = {
                  0b00111111, // 0
                  0b00000110, // 1
                  0b01011011, // 2
                  0b01001111, // 3
                  0b01100110, // 4
                  0b01101101, // 5
                  0b01111101, // 6
                  0b00000111, // 7
                  0b01111111, // 8
                  0b01101111  // 9
                  };



int mSeconde = 0;
int seconde = 0;
int minute = 0;
int heurs = 0;

void setup() {
  
  DDRA = 0xff;
  DDRB = 0x0f;
  PORTB = 0x0f;

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
    }
    bitSet(TIFR3,TOV3);
  }
  horloge_aff7seg();
}

void horloge_aff7seg(void){
  PORTB = 0b1110;
  PORTA = tab7seg[seconde%10];
  delay(10);
  PORTB = 0b1101;
  PORTA = tab7seg[seconde/10];
  delay(10);
  PORTB = 0b1011;
  PORTA = tab7seg[minute%10];
  delay(10);
  PORTB = 0b0111;
  PORTA = tab7seg[minute/10];
  delay(10);
}