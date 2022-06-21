#include <Arduino.h>

#define led_1 0
#define led_2 1
#define led_3 2
#define led_4 3
#define led_5 4
#define bouton 5

void setup() {
for (int led; led <= 4; led++){
  pinMode(led,OUTPUT);
}
pinMode(bouton,INPUT);
}

void loop() {
  if(digitalRead(bouton) == 1){
    digitalWrite(led_1,1);
  }else{
    digitalWrite(led_1,0);
  }
}