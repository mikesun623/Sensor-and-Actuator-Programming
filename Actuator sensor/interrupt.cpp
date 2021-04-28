// set pin numbers:
const int buttonPin = 3;    // the number of the pushbutton pin, change 
  // based on platform

// variables will change:
int buttonState = 0;        // variable for reading the pushbutton status

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
  Serial.begin(57600);
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {    
    Serial.println("HIGH");
  } 
  else {
    Serial.println("LOW");
  
  }
  delay(1000);
}
