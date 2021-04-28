#include <RL_LCD.h>

/* available functions
   -------------------
  void clear();
  void home();
  void noDisplay();
  void display();
  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void printLeft();
  void printRight();
  void leftToRight();
  void rightToLeft();
  void shiftIncrement();
  void shiftDecrement();
  void noBacklight();
  void backlight();
  void autoscroll();
  void noAutoscroll();
  void createChar(uint8_t, uint8_t[]);
  void setCursor(uint8_t, uint8_t);
*/


LCD lcd(0x3F,16,2); // if this does not work then change to (0x27,16,2);

void setup()
{
  lcd.init();                      // initialize the lcd 
  //lcd.init();
  // Print a message to the LCD.
  //lcd.backlight();
}


void loop()
{
  lcd.setCursor(2,0);
  lcd.print("Hello, world!");
  lcd.setCursor(3,1);
  lcd.print("Arduino LCD");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(6,0);
  lcd.print("UTAS");
  lcd.setCursor(5, 1);
  lcd.print("KIT406");
  delay(2000);
}
