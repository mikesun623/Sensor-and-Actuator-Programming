/* RgbLed Library */
#include "RL_PWM.h" // include RGBLED module library

/* available functions
   -------------------
  void off(void);
  void red();      // red only
  void green();    // green only
  void blue();     // blue only
  void setRed(uint8_t n);
  void setGreen(uint8_t n);
  void setBlue(uint8_t n);
  void setAll(uint8_t r, uint8_t g, uint8_t b);
  
*/

PWMController pwmc; // create an RGBLED object
void setup()
{
    pwmc.begin(); // initialise the RGBLED module
}

void loop()
{
  pwmc.setAll (255,0,0); // Set the RGBLED so Red=255 Green=0 Blue=0
  delay(1000); // delay 1 second

  pwmc.setAll (0, 255,0); // Set the RGBLED so Red=0 Green=255 Blue=0
  delay(1000); // delay 1 second

  pwmc.setAll (0,0, 255); // Set the RGBLED so Red=0 Green=0 Blue=255
  delay(1000); // delay 1 second
}
