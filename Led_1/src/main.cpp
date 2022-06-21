#include <Arduino.h>

#define led_1 0
#define led_2 1
#define led_3 2
#define led_4 3
#define led_5 4


void setup() {
  pinMode(led_1,OUTPUT);
}

void loop() {
  digitalWrite(led_1,1);
  delay(1000);
  digitalWrite(led_1,0);
  delay(1000);
}