
/* joystick.ino */ 
#define JOY_X 68 
#define JOY_Y 69 
#define JOY_SEL 9 
int xCenterPos = 0; 
int yCenterPos = 0; 
int xyTH = 100; 

void setup() { 
pinMode(JOY_X, INPUT); 
pinMode(JOY_Y, INPUT); 
pinMode(JOY_SEL, INPUT); 
xCenterPos = analogRead(JOY_X); 
yCenterPos = analogRead(JOY_Y); 
Serial.begin(115200); 
}

void loop() {
 
if(analogRead(JOY_X) < xCenterPos - xyTH) { 
Serial.print("LEFT"); 
} else if(analogRead(JOY_X) > xCenterPos + xyTH) { 
Serial.print("RIGHT"); 
} else { 
Serial.print("CENTER"); 
}

Serial.print(" "); 

if(analogRead(JOY_Y) < yCenterPos - xyTH) { 
Serial.println("UP"); 
} else if(analogRead(JOY_Y) > yCenterPos + xyTH) { 
Serial.println("DOWN"); 
} else { 
Serial.println("CENTER"); 
}

if(digitalRead(JOY_SEL) == LOW) { 
Serial.println("Button Pushed"); 
}
delay(500); 
}
