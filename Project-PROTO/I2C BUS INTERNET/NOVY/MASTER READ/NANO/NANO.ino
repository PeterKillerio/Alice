#include <Wire.h>
const int nanoID = 1;

void setup() {

Wire.begin(nanoID);
Wire.onRequest(requestEvent);


}

void loop() {

  delay(100);
}



void requestEvent(){
  Wire.write("hello");
  }
