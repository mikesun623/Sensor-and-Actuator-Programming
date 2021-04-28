/* Buzzer Library */ 
/* ===== Buzzer Method ===== 
void begin(int pinNum); 
void On(uint8_t bOn); 
void On(); 
void Off(); 
void setFreq(int freq); 
uint8_t getIsOn(); 
=========================== */ 
#include "Buzzer.h" 
// include Buzzer module library 
#define BUZ_PIN 11 
// define the pin number 
Buzzer buzzer; 
// create a buzzer object 

void setup() { 
buzzer.begin(BUZ_PIN); 
// initialise the Buzzer module 
} 
void loop() { 
buzzer.On(); 
// Set the Buzzer ON 
delay(1000); 
// delay 1 second 
buzzer.Off(); 
// Set the Buzzer OFF 
delay(2000); 
// delay 2 second 
} 
