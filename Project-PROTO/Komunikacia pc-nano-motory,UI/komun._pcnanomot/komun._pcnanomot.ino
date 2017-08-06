int stepMode1; // default je avg
int stepMode2; // default je avg
int state1;
int state2;

String command = "";

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



void mood1(){
  Serial.println("Enter number: 1-beast,2-avg,4/8-precis(1/4,1/8)");
  while(!Serial.available()){}
    int number = Serial.parseInt();
    Serial.print("You chose: ");
    Serial.println(number);
  if (number == 1){
    digitalWrite(ms1, LOW);
    digitalWrite(ms2, LOW);
    stepMode1 = 1;
    }else if (number == 2){
      digitalWrite(ms1, HIGH);
      digitalWrite(ms2, LOW);
      stepMode1 = 2;
      }else if (number == 4){
        digitalWrite(ms1, LOW);
        digitalWrite(ms2, HIGH);
        stepMode1 = 4;
        }else if (number == 8){
          digitalWrite(ms1, HIGH);
          digitalWrite(ms2, LOW);
          stepMode1 = 8;
          }else{
            Serial.println("You enterred wrong number: 1-beast,2-avg,4/8-precis(1/4,1/8)");
            }
  
  }
void mood2(){
  Serial.println("Enter number: 1-beast,2-avg,4/8-precis(1/4,1/8)");
  while(!Serial.available()){}
    int number = Serial.parseInt();
    Serial.print("You chose: ");
    Serial.println(number);
  if (number == 1){
    digitalWrite(ms12, LOW);
    digitalWrite(ms22, LOW);
    stepMode2 = 1;
    }else if (number == 2){
      digitalWrite(ms12, HIGH);
      digitalWrite(ms22, LOW);
      stepMode2 = 2;
      }else if (number == 4){
        digitalWrite(ms12, LOW);
        digitalWrite(ms22, HIGH);
        stepMode2 = 4;
        }else if (number == 8){
          digitalWrite(ms12, HIGH);
          digitalWrite(ms22, LOW);
          stepMode2 = 8;
          }else{
            Serial.println("You enterred wrong number: 1-beast,2-avg,4/8-precis(1/4,1/8)");
            }
  
  }

void movement(){
  Serial.println("Zadajte pocet stupnov pre 1. motor: +/-");
  while(!Serial.available()){}
    int xmov = Serial.parseInt();
    Serial.print("You entered for xmov: ");
      Serial.println(xmov);
     
    Serial.println("Zadajte pocet stupnov pre 2. motor: +/-");
    delay(5);
    while(!Serial.available()){}
      int ymov = Serial.parseInt();
      Serial.print("You entered for ymov: ");
      Serial.println(ymov);
      
  if (ymov > 0){
    digitalWrite(dir2, HIGH);
    }else if (ymov < 0){
      digitalWrite(dir2, LOW);
      }
  if (xmov > 0){
    digitalWrite(dir, HIGH);
    }else if (xmov < 0){
      digitalWrite(dir, LOW);
      }


      xmov = abs(xmov/(1.8/stepMode1));
      ymov = abs(ymov/(1.8/stepMode2));
      
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
      Serial.println("!STOP!");
      
      
  }
 void turnoff(){
  Serial.println("Which motor do you want to turn off.(1,2,12,0)");
  while(!Serial.available()){}
  int akt = Serial.parseInt();
  Serial.print("You chose to turn off: ");
  Serial.println(akt);
  if (akt == 1){
    digitalWrite(reset, LOW);
    state1 = 0;
    }else if (akt == 2){
      digitalWrite(reset2, LOW);
      state2 = 0;
      }else if (akt == 12){
        digitalWrite(reset, LOW);
        digitalWrite(reset2, LOW);
        state1 = 0;
        state2 = 0;
  }else if (akt == 0){
    }else{
      Serial.println("You enterred wrong number.");
      }
  }

void turnon(){
  Serial.println("Which motor do you want to turn on.(1,2,12,0)");
  while(!Serial.available()){}
  int akt = Serial.parseInt();
  Serial.print("You chose to turn on: ");
  Serial.println(akt);
  if (akt == 1){
    digitalWrite(reset, HIGH);
    state1 = 1;
    }else if (akt == 2){
      digitalWrite(reset2, HIGH);
      state2 = 1;
      }else if (akt == 12){
        digitalWrite(reset, HIGH);
        digitalWrite(reset2, HIGH);
        state1 = 1;
        state2 = 1;
  }else if (akt == 0){
    }else{
      Serial.println("You enterred wrong number.");
      }
  }

void motors(){
  Serial.print("State of the first motor is: ");
  if (state1 == 1){
    Serial.print("ON. ");
    }else{
      Serial.print("OFF. ");}
  Serial.print("State of the second motor is: ");
   if (state2 == 1){
    Serial.println("ON. ");
    }else{
      Serial.println("OFF. ");}
  }  

void actions(){
  Serial.println("Enter your action please: movement,mood2,mood1,turnoff,turnon,motors");
  while(!Serial.available()){}
  command = Serial.readString();
  if (command == "movement"){
  Serial.println("You chose 'movement'");
  movement();
  }else if (command == "mood1"){
    Serial.println("You chose 'mood1'");
    mood1();
    }else if (command == "mood2"){
      Serial.println("You chose 'mood2'");
      mood2();
      }else if (command == "turnoff"){
        turnoff();
        }else if (command == "turnon"){
          turnon();
          }else if (command == "motors"){
            motors();
            }else{
              Serial.print("Wrong action");}
      }
  

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

digitalWrite(reset, LOW);
digitalWrite(reset2,LOW);
digitalWrite(sleep, HIGH);
digitalWrite(sleep2,HIGH);
state1 = 0;
state2 = 0;

Serial.begin(9600);

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

actions();
  
  

}
