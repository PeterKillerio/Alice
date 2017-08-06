const int nanoId = 1;
int number;
char identifier;

#include <Wire.h>

void transmit(){
  Wire.beginTransmission(nanoId);
  Wire.write(identifier);
  Wire.write(number);
  Wire.endTransmission();
  }


void setup() {

  Wire.begin();
  // put your setup code here, to run once:

Serial.begin(9600);

}

void loop() {

Serial.println("Enter identifier");
while(!Serial.available()){};
identifier = Serial.read();
Serial.print("You enterred: ");
Serial.println(identifier);
Serial.println("Ente number (0-255)");
while(!Serial.available()){};
number = Serial.parseInt();
Serial.print("You enterred: ");
Serial.println(number);

 transmit();

  delay(500);
}
