// no light library required
// set the light measurement pin (must be analogue)
// will display value of light sensor.
const byte lightPin = A0;


void setup() 
{
  // setup serial comms
  Serial.begin(57600);

  // set the pin mode for input
  pinMode(lightPin, INPUT);
}

// take a light level reading every second
void loop() 
{	
  uint16_t lightLevel = 1024 - analogRead(lightPin);
  Serial.println(lightLevel);
  delay(1000); 

}
