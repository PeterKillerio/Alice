const int nanoID = 1;
String command = "";
int number;
char identifier;
#include <Wire.h>
void transmit(){
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
  Wire.beginTransmission(nanoID);
  Wire.write(identifier);
  Wire.write(number);
  Wire.endTransmission();
  delay(5);
  }



void request(){
  Wire.requestFrom(nanoID,6);
  Serial.print("You received: ");
  while(Wire.available()){
    char c = Wire.read();
    Serial.print(c);
    }
    Serial.println();
}


void setup() {
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  Serial.println("Enter your action: (transmit,receive)");
  while(!Serial.available()){}
if(Serial.available() > 0){
  command = Serial.readString();
  Serial.print("You enterred: ");
  Serial.println(command);
  if(command == "transmit"){
    transmit();
    }else if (command == "receive"){
      request();
      }else{
        Serial.println("You enterred wrong action.");
        }
  
  }
    delay(500);
 

}
