//TENTO PROGRAM SA SNAZI VYTVORIT ALGORITMUS POHYBU
//POMOCOU UDAJOV ZO SERIALCOM

int number = 0; //pocet krokov
//DRUHY MOTOR
int stp2 = 9;  //spoj na jeden krok
int dir2 = 8;  //spoj na smer pohybu
int ms12 = 13; //spoje na tvorenie krokov 
int ms22 = 12;
int sleep2 = 10;
int reset2 = 11;


int kroky = 0;
int smer = 0;
//PRVY MOTOR
int stp = 3;  //spoj na jeden krok
int dir = 2;  //spoj na smer pohybu
int ms1 = 7; //spoje na tvorenie krokov 
int ms2 = 6;
int sleep = 4;
int reset = 5;


void setup() {
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



Serial.begin(9600);
delay(500);

}

void loop() {
number = 0;
smer = 0;
if (Serial.available()){
kroky = Serial.parseInt();
Serial.println(kroky);
}
digitalWrite(sleep, HIGH);
digitalWrite(reset, HIGH);
digitalWrite(ms1, HIGH);
digitalWrite(ms2, HIGH);
digitalWrite(dir, LOW);


delay(20);

while (kroky > 0){
  
  digitalWrite(stp, HIGH);
  delay(10);
  digitalWrite(stp,LOW);
  delay(10);
  kroky--;
}





}
