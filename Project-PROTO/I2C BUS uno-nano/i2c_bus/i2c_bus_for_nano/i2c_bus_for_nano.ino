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
  char inChar;

  while(Wire.available() > 0){
    inChar = Wire.read();
    
    if (inChar == 'H'){
      digitalWrite(13,HIGH);
      delay (100);
      digitalWrite(13,LOW);
      delay(100);
      digitalWrite(13,HIGH);
      delay (100);
      digitalWrite(13,LOW);
      delay(100);
      digitalWrite(13,HIGH);
      delay (100);
      digitalWrite(13,LOW);
      delay(100);
      digitalWrite(13,HIGH);
      delay (100);
      digitalWrite(13,LOW);
      delay(100);
      }else if (inChar == 'L'){
        digitalWrite (13, LOW);
        }  
    }
  
  
  }
