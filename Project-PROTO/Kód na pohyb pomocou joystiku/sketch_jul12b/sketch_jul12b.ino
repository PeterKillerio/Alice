int stp = 3;  //spoj na jeden krok
int dir = 4;  //spoj na smer pohybu
int ms1 = 5; //spoje na tvorenie krokov 
int ms2 = 6;
int sleep = 2;
int reset = 7;
int data;
int a = 0;  

void setup() {
  // put your setup code here, to run once:
pinMode(stp, OUTPUT);
pinMode(dir, OUTPUT);
pinMode(ms1, OUTPUT);
pinMode(ms2, OUTPUT);
pinMode(sleep, OUTPUT);
pinMode(reset, OUTPUT);

Serial.begin(9600);
delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:
data = analogRead(A0);
Serial.println(data);
digitalWrite(ms1, HIGH);
digitalWrite(ms2, HIGH);
digitalWrite(sleep, HIGH);
digitalWrite(reset, HIGH);

if (a <  200)  //sweep 200 step in dir 1
   {
    a++;
    digitalWrite(stp, HIGH);   
    delay(40);               
    digitalWrite(stp, LOW);  
    delay(40);              
   }
  else 
   {
    digitalWrite(dir, HIGH);
    a++;
    digitalWrite(stp, HIGH);  
    delay(40);               
    digitalWrite(stp, LOW);  
    delay(40);
    
  
    }

}
