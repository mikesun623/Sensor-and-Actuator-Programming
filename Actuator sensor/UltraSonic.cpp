/* UltraSonic Library */
/* ===== UltraSonic Method =====
void begin(int pinNum);
int ReadDistanceMilimeter(); // mm
int ReadDistanceCentimeter(); // cm
int ReadDistanceInche(); // inch
=============================== */

#include "RL_Ultrasonic.h" // include ultrasonic sensor module library
UltraSonic ultra; // create an instance of the UltraSonic class
int UltraDistance; // declare the variable (integer) UltraDistance

void setup()
{
  ultra.begin(); // set the begin function of ultrasonic module
  Serial.begin(57600); // set the begin function of Serial monitor
}

void loop()
{

  // read in the distance and store it in UltraDistance
  UltraDistance = ultra.ReadDistanceMilimeter();
  // display variable UltraDistance.
  Serial.print(UltraDistance);
  // display the distance unit “mm” 
  Serial.println(" mm");
  // delay 1 second
  delay(1000);

}
