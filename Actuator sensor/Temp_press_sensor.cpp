#include <RL_PressureTemp.h>

#include<Wire.h>
PTSensor pt;
float pressure;
float temperature;
int altimeter;      
void setup() 
{
  Serial.begin(57600);
  pt.begin();
}


void loop() 
{
  // read values from the sensor:
  
  pressure = pt.readPressure() / 100;
  temperature = pt.readTemperature();
  altimeter = pt.readAltitude(1007.0); 

  // change to your locations average barrometric pressure
  // print values to serial monitor:

  Serial.print(F("Pressure: "));
  Serial.print(pressure);
  Serial.print(" hPa");
  Serial.print("\t");
  Serial.print(("Temp: "));
  Serial.print(temperature);
  Serial.print(" C");
  Serial.print("\t");
  Serial.print("Altimeter: ");
  Serial.print(altimeter); 
  Serial.println(" m");
  delay(5000); //Update every 5 sec

}
