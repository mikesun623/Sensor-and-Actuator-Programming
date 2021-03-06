/*

 A simple web server that shows the value of the analogue input pins.

*/

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:

byte mac[] = { 0xAA, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 111);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):

EthernetServer server(80);
long timeKeeper = 0;

void setup() {
  // You can use Ethernet.init(pin) to configure the CS pin
  Ethernet.init(32); 

  // Open serial communications and wait for port to open:
  Serial.begin(57600);

  Serial.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start the server
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  
}


void loop() {

  if( millis() - timeKeeper > 10000UL) {

	timeKeeper = millis();
  	Serial.print("server is at ");
	Serial.println(Ethernet.localIP());
	Ethernet.MACAddress(mac);
	Serial.print(mac[0], HEX); Serial.print("-");
	Serial.print(mac[1], HEX); Serial.print("-");
	Serial.print(mac[2], HEX); Serial.print("-");
	Serial.print(mac[3], HEX); Serial.print("-");
	Serial.print(mac[4], HEX); Serial.print("-");
	Serial.println(mac[5], HEX);

  }

  // listen for incoming clients
  EthernetClient client = server.available();

  if (client) {

    Serial.println("new client");

    // an http request ends with a blank line
    boolean currentLineIsBlank = true;

    while (client.connected()) {

      if (client.available()) {

        char c = client.read();

        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply

        if (c == '\n' && currentLineIsBlank) {

          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");

          // output the value of each analog input pin A0 (LDR) and A1

          for (int analogChannel = 0; analogChannel < 2; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");
          }

          client.println("</html>");
          break;
        }

        if (c == '\n') {          
          currentLineIsBlank = true;
        } else if (c != '\r') {          
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);

    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
