#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// Set the static IP address
IPAddress ip(192, 168, 0, 111);

// initialize the library instance:
EthernetClient client;


char server[16] = "192.168.0.1";
char url[2000];






// last time you connected to the server, in milliseconds
unsigned long lastConnectionTime = 0;           

// delay between updates, in milliseconds
const unsigned long postingInterval = 10000UL;


void setup() {

  // Ethernet.init(pin) to configure the CS pin
  Ethernet.init(32);  

  // start serial port:
  Serial.begin(57600);

  Ethernet.begin(mac, ip);
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());

  // give the Ethernet shield a second to initialize:
  delay(1000);
}


void loop() {

  // if there's an incoming data from the net connection,
  // send it out through serial port.  This is for debugging
  // purposes only:

  if(client.find("\r\n\r\n"))  {
    while (client.available()) {
      char c = client.read();
      //Serial.print("Char : ");
      Serial.print(c);
      
      if(c == '1') {Serial.println(" Even");}
      else if(c == '0') {Serial.println(" Odd");}
    }
  }

  // if ten seconds have passed since your last connection,
  // then connect again and send data:
  if (millis() - lastConnectionTime > postingInterval) {
  
    Serial.print("\n===============================\nMy IP address: ");
    Serial.println(Ethernet.localIP());
    httpRequest();
  
  }

}



// this method makes an HTTP connection to the server:
void httpRequest() {
  // close any connection before sending a new request.
  
  client.stop();

  // if there's a successful connection:
  if (client.connect(server, 80)) {


    memset(url, '\0', 2000); 

    sprintf(url, "GET /alacritas_direct.php?acc=amaiti&call=kit717/test.php&num=%lu HTTP/1.1", random(1, 100));

    Serial.println(url);
    
    delay (10);
    

    Serial.println("connecting...");


    // send the HTTP GET request:
    client.println(url);
    client.println("Host: 192.168.0.1");
    client.println("User-Agent: arduino-ethernet");
    client.println("Connection: close");
    client.println();


    // note the time that the connection was made:
    lastConnectionTime = millis();

  } else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
  }
}
