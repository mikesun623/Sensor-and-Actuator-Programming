/* FND Library */
#include "RL_FND.h" // include FND module library

/* ===== FND Method =====
void begin(int addr1, int addr2);
void setFndVal(uint8_t addr, uint8_t reg, uint8_t val);
void setNum(uint8_t fndNum, uint8_t fndVal, uint8_t bDot=0);
void setAllNum(uint8_t num1, uint8_t num2, uint8_t num3, uint8_t num4);
void setAllNum(int num);
 ======================== */
 
FND fnd; // create an instance of the FND class class

void setup()
  {
  fnd.begin(); // initialise the FND module
  }

void loop()
  {
  uint8_t i; // declare variable i (uint8_t)
  fnd.setAllNum(0); // set all the numbers to 0
  for(i=0; i<7; i++) // loop from 0 to 6  
    {
    fnd.setNum(1, i); // set the first number on FND as i
    fnd.setNum(2, i+1); // set the first number on FND as i+1
    fnd.setNum(3, i+2); // set the first number on FND as i+2
    fnd.setNum(4, i+3); // set the first number on FND as i+3
    delay(1000); // 1 second delay
    }
  }
