
int xmov;
int ymov;
///////////
int stepMode1; // default je avg
int stepMode2; // default je avg
int state1;
int state2;

//DRUHY MOTOR
int stp2 = 9;  //spoj na jeden krok
int dir2 = 8;  //spoj na smer pohybu
int ms12 = 13; //spoje na tvorenie krokov 
int ms22 = 12;
int sleep2 = 10;
int reset2 = 11;

//PRVY MOTOR
int stp = 3;  //spoj na jeden krok
int dir = 2;  //spoj na smer pohybu
int ms1 = 7; //spoje na tvorenie krokov 
int ms2 = 6;
int sleep = 4;
int reset = 5;
/////////
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
    ///
     if (g == '+'){
    digitalWrite(dir2, HIGH);
    xmov = abs(c/(1.8/stepMode1));
    }else if (g == '-'){
      digitalWrite(dir2, LOW);
      xmov = abs(c/(1.8/stepMode1));
      }else if (g == '='){
    digitalWrite(dir, HIGH);
    ymov = abs(c/(1.8/stepMode2));
    }else if (g == '/'){
      digitalWrite(dir, LOW);
      ymov = abs(c/(1.8/stepMode2));
      }
      ///
    Serial.print(c);
    Serial.println();
  }
void requestEvent(){
  Serial.println ("You have been requested");
  Wire.write("m1");
  if (state1 == 1){
    Wire.write("1");
    }else{
      Wire.write("0");
      }
 
  Wire.write("m2");
  if (state2 == 1){
    Wire.write("1");
    }else{
      Wire.write("0");
      }
  }


void setup() {

  Wire.begin(nanoID);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
   //PRVY MOTOR
pinMode(stp, OUTPUT);
pinMode(dir, OUTPUT);
pinMode(ms1, OUTPUT);
pinMode(ms2, OUTPUT);
pinMode(sleep, OUTPUT);
pinMode(reset, OUTPUT);

//DRUHY MOTOR
pinMode(stp2, OUTPUT);
pinMode(dir2, OUTPUT);
pinMode(ms12, OUTPUT);
pinMode(ms22, OUTPUT);
pinMode(sleep2, OUTPUT);
pinMode(reset2, OUTPUT);

digitalWrite(reset, HIGH);
digitalWrite(reset2,HIGH);
digitalWrite(sleep, HIGH);
digitalWrite(sleep2,HIGH);
state1 = 1;
state2 = 1;



//SETUP NA DEFAULT MOODY
      //1.motor
      digitalWrite(ms1, HIGH);
      digitalWrite(ms2, LOW);
      stepMode1 = 2;
      //2.motor
      digitalWrite(ms12, HIGH);
      digitalWrite(ms22, LOW);
      stepMode2 = 2;

//
delay(500);


}

void loop() {
  while((ymov or xmov) > 0){
        if (ymov > 0){
          digitalWrite(stp2, HIGH);  
          }

       if (xmov > 0){
          digitalWrite(stp,HIGH);
       }
       delay(10); ///////////////

       if (ymov > 0){
          digitalWrite(stp2, LOW);  
          }

       if (xmov > 0){
          digitalWrite(stp,LOW);

        }
      if (ymov > 0){
        ymov--;
        }
      if (xmov > 0){
        xmov--;
        }
      delay (10);
      Serial.println("step");
      }
        delay(10);
      



  

}
