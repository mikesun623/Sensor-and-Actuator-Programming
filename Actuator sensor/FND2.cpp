#include "RL_FND.h" // include FND module library

FND fnd; // declare the class FND as fnd
int valFND; // declare variable valFND (integer)
void setup()
  {
  fnd.begin(); // initialise the FND module 
  }
void loop()
  {
  valFND = 9999; // set ass_val to 9999;
  displayValue_FND(); // call the function displayValue_FND();
  delay(500); // 0.5 second delay
  }

// create a function to manage printing to the FND
void displayValue_FND()
  {
  byte tmp = 0; // declare tmp and assign as 0
  // display the ‘thousands’ digit of valFND
  tmp = valFND / 1000;
  fnd.setNum(1, tmp); // 1st digit of FND module
  // display the ‘hundreds’ digit of valFND
  tmp = (valFND % 1000) / 100;
  fnd.setNum(2, tmp); // 2nd digit of FND module
  // display the ‘tens’ digit of valFND
  tmp = ((valFND % 1000) % 100) / 10;
  fnd.setNum(3, tmp); // 3rd digit of FND module
  // display the ‘units’ digit of valFND
  tmp = ((valFND % 1000) % 100) % 10;
  fnd.setNum(4, tmp); // 4th digit of FND module 
  }
