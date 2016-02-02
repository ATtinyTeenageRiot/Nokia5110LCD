#include "nokia5110LCD.h"
Nokia5110LCD nokiaLCD;

void setup() {
  nokiaLCD.lcdInit();
  nokiaLCD.lcdClear(false);
  nokiaLCD.lcdPrint(5, 0, "MANTICORE", false);
}

void loop() {
  // put your main code here, to run repeatedly:

}
