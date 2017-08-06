#include <Wire.h>

const byte slaveId = 1;
void setup() {
  
Wire.begin(slaveId);
Wire.onReceive(receiveEvent);

pinMode(13, OUTPUT);
digitalWrite(13,LOW);
 
  // put your setup code here, to run once:

}

void loop() {
}

void receiveEvent(int howMany){
  int inChar;

  while(Wire.available() > 0){
    inChar = Wire.read();
    
    if (inChar == 1){
      digitalWrite(13,HIGH);
      
      }else if (inChar == 0){
        digitalWrite (13, LOW);
        }  
    }
  
  
  }
