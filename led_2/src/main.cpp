#include <Arduino.h>

#define led_1 0
#define led_2 1
#define led_3 2
#define led_4 3
#define led_5 4

void setup() {
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
}

void loop() {
  for (int led = 0; led <= 4; led++){
    digitalWrite(led,1);
    delay(1000);
  }
  for (int led = 0; led <= 4; led++){
    digitalWrite(led,0);
    delay(1000);
  }
}