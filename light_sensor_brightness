// no light library required
// set the light measurement pin (must be analogue)
//display differnet values depending on brightness

// sensor reading can fluctuate
// so sometimes we may have to take an average of a few hundred readings to //get a good reading

float sum = 0;
int count = 0;

void setup() {

  // setup serial comms
  Serial.begin(57600);
  // set the pin mode for input
  pinMode(A0, INPUT);
}


void loop() {
  
  sum += analogRead(A0);
  count++;
  
  if(count > 100) {
   Serial.println(sum / 100.0);
   count = 0;
   sum = 0;
  }
  
  delay(10);
}
