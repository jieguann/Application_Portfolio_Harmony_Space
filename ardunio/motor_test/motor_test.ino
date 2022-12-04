
#include <SPI.h>
#include <ESP8266WiFi.h>

#include <Stepper.h>
#define STEPS 200
Stepper myStepper(STEPS, 5, 0, 4, 2);

char ssid[] = "Skylab";           // SSID of your home WiFi
char pass[] = "@DL0ct0b3r";            // password of your home WiFi

int state = 0;

unsigned long askTimer = 0;

IPAddress server(192,168,0,80);       // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(115200);               // only for debug
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
     pinMode(15,OUTPUT);// for EN1
  digitalWrite(15,HIGH);// enable EN1
  pinMode(13,OUTPUT);// for EN1
  digitalWrite(13,HIGH); // enable EN2
     myStepper.setSpeed(200);
  // initialize the serial port:
  Serial.begin(9600);
  }
/*  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());    // Network parameters
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());*/

}

void loop () {
  client.connect(server, 80);   // Connection to the server
  
  Serial.println(".");
  client.println("Hello server! Are you sleeping?\r");  // sends the message to the server
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: " + answer);
  client.flush();

 
    
  myStepper.step(-200);

delay(200);   
   myStepper.step(200);

  delay(200);                  // client will trigger the communication after two seconds
}
