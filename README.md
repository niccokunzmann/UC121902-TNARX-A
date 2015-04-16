UC121902-TNARX-A
================

![](Pollin/G120586.JPG)

A Library to control the Samsumg UC121902-TNARX-A LCD module with the Arduino. You can buy it from [Pollin](http://www.pollin.de/shop/dt/MzE0OTc4OTk-/Bauelemente_Bauteile/Aktive_Bauelemente/Displays/LCD_Modul_SAMSUNG_UC121902_TNARX_A.html).

Installation
------------

See [http://www.arduino.cc/en/Guide/Libraries](http://www.arduino.cc/en/Guide/Libraries) chapter "Manual installation" for installation instructions.

Connect to Arduino
------------------

![](Pollin/Beschriftet.jpg)

CE, CK and DI are connected to pins on the Arduino. Default values are CE=2, CK=3, DI=4.

Hello World
-----------

    #include "UC121902-TNARX-A.h"
    
    UC121902_TNARX_A::Display display(2, 3, 4);
    
    void setup() {
      display.begin();
      display.print("Hello :)");
      delay(1000);
    }
    
    int count = 0;
    
    void loop() {
      delay(1000);
      display.print("count:", count);
      count++;
    }

Small Handbook
--------------

###Initialization

    UC121902_TNARX_A::Display display(CE, CK, DI);
    UC121902_TNARX_A::Display display(); // CE == 2, CK == 3, DI == 4

You can choose one of the lines. You can rename them to use multiple displays.

###Printing

    display.print("String");
	display.print(1234567890L);
    display.print("variable:", variable);
    display.print(character, position);

Unknown characters are replaced by '?'.
You can also use `put` and `flush`:

    display.put("String");
	display.put(1234567890L);
    display.put(character, position);
    display.flush();

`put` does not send commands to the display. `flush` sends the current state to the display.

### Symbols

    display.CHAN
    display.MEM
    display.PROG
    display.SEC
    display.BELL
    display.BELL_LINE
    display.BATTERY_FIRST_HALF
    display.BATTERY_SECOND_HALF

Each of them is a switch and has these methods:

    display.BELL.turnOn();
    display.BELL.turnOff();
    display.BELL.isOn();
    display.BELL.isOff();
    display.BELL.toggle();

License
-------

MIT License, see the License file. Subfolders (Pollin) may have different licenses.
