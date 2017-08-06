#include <Wire.h>

const int nanostepID = 1;

void setup() {
  // put your setup code here, to run once:

Wire.begin();


}

void loop() {


  Wire.beginTransmission(nanostepID);

  Wire.write('1');

  Wire.endTransmission();

  delay(2000);

  Wire.beginTransmission(nanostepID);

  Wire.write('0');

  Wire.endTransmission();

  delay(500);

  
  // put your main code here, to run repeatedly:

}
