const int nanoID = 1;
#include <Wire.h>


void request(){
  Wire.requestFrom(nanoID,6);
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

 request();
    delay(500);
 

}
