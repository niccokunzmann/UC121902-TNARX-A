#include "UC121902-TNARX-A.h"

UC121902_TNARX_A::Display display;

void setup() {
  // put your setup code here, to run once:
  display.begin();
  int x = 100;
  display.eraseAll();
  delay(x);
  display.CHAN.turnOn();
  delay(x);
  display.MEM.turnOn();
  delay(x);
  display.PROG.turnOn();
  delay(x);
  display.SEC.turnOn();
  delay(x);
  display.BELL.turnOn();
  delay(x);
  display.BELL_LINE.turnOn();
  delay(x);
  display.BATTERY_FIRST_HALF.turnOn();
  delay(500);
  display.BATTERY_SECOND_HALF.turnOn();
  for(int i = 0; i < 3; i++) {
    delay(300);
    display.eraseNumbers();
    delay(300);
    display.say("Hello !");
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
