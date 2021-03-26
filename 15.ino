#include <Servo.h>

Servo SD;

#define S1    22
#define S2    24

#define PIN_ECHO1  9
#define PIN_TRIG1  8

#define MAB  2
#define MAA  3
#define MBB  4
#define MBA  5


void setup() {
  Serial.begin(9600);
  Serial.println("Слава Кайзеру");
  Serial1.begin(9600);
  Serial3.begin(9600);
  Serial1.write('z');
  
  SD.attach(10);
  SD.write(70);
  
  pinMode(PIN_ECHO1,INPUT);
  pinMode(PIN_TRIG1,OUTPUT);
  
  pinMode(MAA, OUTPUT);
  pinMode(MAB, OUTPUT);
  pinMode(MBB, OUTPUT);
  pinMode(MBA, OUTPUT);
  
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
}

int dist() {
  long duration;
  uint8_t cm;
    
  digitalWrite(PIN_TRIG1, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG1, LOW);
  duration = pulseIn(PIN_ECHO1, HIGH);
  cm = (duration / 2) / 29.1;
  if (cm <= 10){
    return 1;
  }
  else{
   return 0;
  }
}


void search(){
  while(digitalRead(S1) == 1 || digitalRead(S2) == 1){
    left();
    delay(50);
    stoped();
    delay(50);
  }
}
void cargo(){
  SD.write(0);
  delay(1500);
  SD.write(65);
  delay(1000);
}
void forward(){
  digitalWrite(MAA, 1);
  digitalWrite(MAB, 0);
  digitalWrite(MBA, 1);
  digitalWrite(MBB, 0);
}


void left(){
  digitalWrite(MAA, 1);
  digitalWrite(MAB, 0);
  digitalWrite(MBA, 0);
  digitalWrite(MBB, 1);
}

void right(){
  digitalWrite(MAA, 0);
  digitalWrite(MAB, 1);
  digitalWrite(MBA, 1);
  digitalWrite(MBB, 0);
}

void back(){
  digitalWrite(MAA, 0);
  digitalWrite(MAB, 1);
  digitalWrite(MBA, 0);
  digitalWrite(MBB, 1);
}

void stoped(){
  digitalWrite(MAA, 0);
  digitalWrite(MAB, 0);
  digitalWrite(MBA, 0);
  digitalWrite(MBB, 0);
}

bool data(){
  
  if (Serial3.available()){
    
   char Data = Serial3.read();
  if(Data == '1'){
    return true;
  }
  else{
    return false;
  }
  }
  return false;
}



void loop() {
  while(data() == false){
    delay(100);
  }
  Serial1.write('x');
  search();
  while (dist()==0){
    forward();
  }
  stoped();
  cargo();
  Serial1.write('y');
  search();
  while (dist()==0){
    forward();
  }
  stoped();
  Serial1.write('z');
}
