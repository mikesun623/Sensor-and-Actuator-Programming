#include <RL_RFID.h>
#include <SPI.h>
RFID rfid; // make new object

void setup() 
{
Serial.begin(57600); // Initialize serial communications with the PC
rfid.PCD_Init(); // Init MFRC522
Serial.println(F("Scan PICC to see UID"));
}

void loop() 
{
// Look for new cards
if(!rfid.isNewCardPresent()) { return; }

// Select one of the cards
if(!rfid.readCardSerial()) { return; }

Serial.print(F("Card UID:"));

for(byte i = 0; i < rfid.uid.size; i++) 
{
if(rfid.uid.uidByte[i] < 0x10) Serial.print(F(" 0"));
else Serial.print(F(" "));

Serial.print(rfid.uid.uidByte[i], HEX);
} 

Serial.println(); 
}
