int number = 0; //TENTO PROGRAM BERIE CISLO ZO SERIALCOM A VYPISE HO
                //(POCITACU)

void setup() {
  
Serial.begin(9600);
delay(20);
}

void loop() {
  
if (Serial.available()){
  number =  Serial.parseInt();
  Serial.println(number);
  delay(20);
  }
delay(10);

}
