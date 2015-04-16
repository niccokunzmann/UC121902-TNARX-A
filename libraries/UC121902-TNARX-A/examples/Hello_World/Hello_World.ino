#include "UC121902-TNARX-A.h"

UC121902_TNARX_A::Display display;

void setup() {
  display.begin();
  display.print("Hello :)");
  delay(1000);
}

int i = 0;

void loop() {
  delay(1000);
  display.print("count:", i);
  i++;
}