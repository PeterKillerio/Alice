int xx = 0;
int yy = 2;
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

//PRVY MOTOR 
int spustac = 0;
int kontrol = 0;
//DRUHY MOTOR
int spustac2 = 0;
int kontrol2 = 0;

//int button = 12;


int xova = 0;
int data1 = 500;
int data2 = 500;
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

//pinMode(button, OUTPUT);

Serial.begin(9600);
delay(500);
}

void loop() {


//PRVY MOTOR
  digitalWrite(ms1, HIGH);
  digitalWrite(ms2, LOW);

  
//DRUHY MOTOR
  digitalWrite(ms12, HIGH);
  digitalWrite(ms22, LOW);


data1 = analogRead(xx);
data2 = analogRead(yy);
Serial.print(" //x coordinations: ");
Serial.print(data1);
Serial.print(" //y coordinations: ");
Serial.println(data2);

//PRVY MOTOR
if (data1 < 490){
  digitalWrite(dir, HIGH);
  }
if (data1 > 510){
  digitalWrite(dir, LOW);
  }
  
//DRUHY MOTOR
if (data2 < 490){
  digitalWrite(dir2, HIGH);
  }
if (data2 > 510){
  digitalWrite(dir2, LOW);
  }

//POHYB PRE 1 AJ 2 MOTOR
if ((spustac == 1)||(spustac2 == 1)){
if (spustac == 1){
  digitalWrite(stp, HIGH);
}
if (spustac2 == 1){
  digitalWrite(stp2, HIGH);
}
  delay(10);
if (spustac == 1){
  digitalWrite(stp, LOW);
}  
if (spustac2 == 1){
  digitalWrite(stp2, LOW);
} 
  delay(10);

  }
// PRVY MOTOR
if ((data1 > 525)&&(kontrol == 0)){
  spustac = 1;
   digitalWrite(sleep,HIGH);
  digitalWrite(reset, HIGH);
   delay( 10 );
   kontrol = 1;
  }
else if ((data1 < 490)&&(kontrol == 0)){
  spustac = 1;
   digitalWrite(sleep,HIGH);
  digitalWrite(reset, HIGH);
   delay( 10 );
   kontrol = 1;
  }else if ((data1 > 490)&&(data1 < 525)&&(kontrol == 1)){
    spustac = 0;
    digitalWrite(sleep, LOW);
  digitalWrite(reset, LOW);
  kontrol = 0;
  delay( 10 );
 
    }
//DRUHY MOTOR 

if ((data2 > 525)&&(kontrol2 == 0)){
  spustac2 = 1;
   digitalWrite(sleep2,HIGH);
  digitalWrite(reset2, HIGH);
   delay( 10 );
   kontrol2 = 1;
  }
else if ((data2 < 490)&&(kontrol2 == 0)){
  spustac2 = 1;
   digitalWrite(sleep2,HIGH);
  digitalWrite(reset2, HIGH);
   delay( 10 );
   kontrol2 = 1;
  }else if ((data2 > 490)&&(data2 < 525)&&(kontrol2 == 1)){
    spustac2 = 0;
    digitalWrite(sleep2, LOW);
  digitalWrite(reset2, LOW);
  kontrol2 = 0;
  delay( 10 );
 
    }
}
