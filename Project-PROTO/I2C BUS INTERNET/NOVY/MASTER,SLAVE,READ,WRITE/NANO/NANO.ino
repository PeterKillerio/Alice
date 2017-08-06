#include <Wire.h>
const int nanoID = 1;

void receiveEvent(int howMany){
  int c = 0;
  char g = 0;
  int kontrol = 1;
  while(0 < Wire.available()){
 if (kontrol == 1){
  g = Wire.read();
  kontrol = 0;
  }
    c = c + Wire.read();
    if (Wire.available()> 2){
    c = c*10;}
           
      }
    
    Serial.println("You received: ");
    Serial.print(g);
    Serial.print(c);
    Serial.println();
  }
void requestEvent(){
  Serial.println ("You have been requested");
  Wire.write("m11m21");
  }



void setup() {
Wire.begin(nanoID);
Wire.onRequest(requestEvent);
Wire.onReceive(receiveEvent);
Serial.begin(9600);

}

void loop() {
  delay(100);
}


