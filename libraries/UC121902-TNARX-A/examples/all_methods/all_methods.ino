#include "UC121902-TNARX-A.h"

UC121902_TNARX_A::Display display;

void setup() {
  // put your setup code here, to run once:
  display.begin();
  int x = 100;
  display.eraseAll();
  display.print(1234567890L);
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
  delay(x);
  display.BATTERY_SECOND_HALF.turnOn();
  for(int i = 0; i < 3; i++) {
    delay(300);
    display.eraseText();
    delay(300);
    display.print("Hello !");
  }
  delay(x);
  display.print("a:", 55);
}

void loop() {
  // put your main code here, to run repeatedly:

}
