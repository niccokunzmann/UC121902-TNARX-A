#include "UC121902-TNARX-A.h"

UC121902_TNARX_A::Display display;

void setup() {
  // put your setup code here, to run once:
  display.begin();
  int x = 100;
  display.eraseAll();
  display.print(1234567890L);
  delay(x);
  display.chan.turnOn();
  delay(x);
  display.mem.turnOn();
  delay(x);
  display.prog.turnOn();
  delay(x);
  display.sec.turnOn();
  delay(x);
  display.bell.turnOn();
  delay(x);
  display.bell.mute();
  delay(x);
  display.battery.halfFull();
  delay(x);
  display.battery.full();
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
