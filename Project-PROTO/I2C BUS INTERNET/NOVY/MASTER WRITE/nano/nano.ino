const int stepperId = 1;
#include <Wire.h>
void setup() {

  Wire.begin(stepperId);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

   delay(100);
  
  
  // put your main code here, to run repeatedly:

}

void receiveEvent(int howMany){
  int c = 0;
  char g = 0;
  while(1 < Wire.available()){
    c = c + Wire.read();
    if (Wire.available()> 2){
    c = c*10;}else{
      g = Wire.read();
      
      }
    
     
    
    }
    Serial.print(c);
    Serial.print(g);
    Serial.println();
 
  }
  
