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
  if(digitalRead(5) == 1){
    for(int led = 0; led <= 4; led++){
      digitalWrite(led,1);
      delay(500);
    }
    for(int led = 4; led >= 0; led--){
      digitalWrite(led,0);
      delay(500);
    }
  }
}