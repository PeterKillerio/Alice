int stp = 9;  //spoj na jeden krok
int dir= 8;  //spoj na smer pohybu
int ms1 = 13; //spoje na tvorenie krokov 
int ms2 = 12;
int sleep = 10;
int reset = 11;



#include <AccelStepper.h>

// 2. pin je step
// 3. pin je dir
AccelStepper stepperX(1,stp,dir);
int TravelX;
void setup() {
  pinMode(sleep, OUTPUT);
  pinMode(reset, OUTPUT);
  // put your setup code here, to run once:
Serial.begin(9600);
delay(5);
///
  digitalWrite(sleep,HIGH);
  digitalWrite(reset, HIGH);
///
delay(5);
stepperX.setCurrentPosition(0);
stepperX.setMaxSpeed(600.0);
stepperX.setAcceleration(100.0);

}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()>0){
  TravelX = Serial.parseInt();
  Serial.print("Moving stepper into position: ");
  Serial.println(TravelX);
  stepperX.moveTo(TravelX);
  delay(1000);
  }
}
