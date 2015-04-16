#include "UC121902-TNARX-A.h"

UC121902_TNARX_A::Display display(2, 3, 4);

void setup() {
  display.begin();
  display.print("Percent!");
  delay(1000);
}

int i = 0;

void loop() {
  delay(1000);
  display.print("count:", i * 10);
  display.put('%', 11);
  display.flush();
  if (i < 100) {
    i++;
  }
}