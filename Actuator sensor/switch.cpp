/* Switch Serial Program */ 
/* ===== Switch Methods ===== 
void begin(); 
uint8_t getPushKey(); // if no key is pressed it just returns 0 
uint8_t waitGetPushKey(); // will stop the loop until a key is pressed 
=========================== */ 
#include "RL_Switch.h" // include Switch library 
Switch pushSwitch; 	   // create a Switch object called ‘pushSwitch’ 

void setup() { 
pushSwitch.begin(); //initialise Switch module 
Serial.begin(57600); //initialise Serial Monitor 
}

void loop() { 
/*assign to variable ‘pushKey’ the pressed button number, otherwise pushKey will be assigned 0 (Please refer to Switch module material).*/ 

uint8_t pushKey = pushSwitch.getPushKey(); 
if(pushKey >= 0) 
{ // if pushKey is higher than 0 then a button is pressed 
Serial.print("Pushed : "); // print out “Pushed : “ 
Serial.println(pushKey); // print out the pressed button number 
delay(500); 
}
}
