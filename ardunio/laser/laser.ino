#define DETECT 4 // pin 2 for  sensor
#define ACTION 8 // pin 8 for action to do someting
int detected = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Robojax.com Laser Module Test");
  pinMode(DETECT, INPUT);//define detect input pin
  pinMode(ACTION, OUTPUT);//define ACTION output pin

  // Laser sensor code for Robojax.com

}

void loop() {
     // Laser Sensor code for Robojax.com

   detected = digitalRead(DETECT);// read Laser sensor
 
  if( detected == HIGH)
  {
    digitalWrite(ACTION,HIGH);// set the buzzer ON
    Serial.println("Detected!");

  }else{
    digitalWrite(ACTION,LOW); // Set the buzzer OFF
    Serial.println("No laser");
     // Laser Sensor code for Robojax.com

  }
  delay(200);
}
