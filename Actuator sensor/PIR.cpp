volatile int state = 1;

void setup() {
Serial.begin(57600);
// attach interrupt 0 (so pin number is 2 should be wired)
attachInterrupt(0, interrupt, RISING);
}


void loop() {
Serial.println("Normal");
delay(1000);
Serial.print("state: ");
Serial.println(state);
}

void interrupt() {
// assign state as 1(true) if it is 0(false), vice versa
state = !state;
Serial.println("Interrupted");
}
