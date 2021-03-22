#include <Servo.h>

Servo SD;

#define S1    A1
#define S2    A2

#define PIN_ECHO1  11
#define PIN_TRIG1  12

#define MAB  2
#define MAA  3
#define MBB  4
#define MBA  5


void setup() {
  Serial.begin(9600);
  Serial.println("Слава Кайзеру");
  SD.attach(20);
  SD.write(0);
  
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
  if (cm <= 30){
    return 1;
  }
  else{
   return 0;
  }
}


void search(){
  while(digitalRead(S1) ==0 || digitalRead(S2) == 0){
    left();
  }
}
void cargo(){
  for (int i = 0; i <=80; i = i +10){
    SD.write(i);
    delay(300);
  }
  delay(1000);
  SD.write(0);
}
void forward(){
  digitalWrite(MAA, 1);
  digitalWrite(MAB, 0);
  digitalWrite(MBA, 1);
  digitalWrite(MBB, 0);
  delay(100);
}


void left(){
  digitalWrite(MAA, 1);
  digitalWrite(MAB, 0);
  digitalWrite(MBA, 0);
  digitalWrite(MBB, 1);
  delay(100);
}

void right(){
  digitalWrite(MAA, 0);
  digitalWrite(MAB, 1);
  digitalWrite(MBA, 1);
  digitalWrite(MBB, 0);
  delay(100);
}

void back(){
  digitalWrite(MAA, 0);
  digitalWrite(MAB, 1);
  digitalWrite(MBA, 0);
  digitalWrite(MBB, 1);
  delay(100);
}

void data(){
  if(Serial.read==1){
    return 1;
  }
}

void maykosnvkl(){
}

void maykosnvikl(){
}
void maykstartvkl(){
}
void maykstartvikl(){
}

void loop() {
  #Сюда нужно вставить кусок кода который будет ждать передачи координат( 1 ) по блютуз
  maykstartvikl();
  maykosnvkl();
  while(data == 0){
    delay(100);
  }
  search();
  while (dist()==0){
    forward();
  }
  cargo();
  maykosnvikl();
  maykstartvikl();
  search();
  while (dist()==0){
    forward();
  }  
}
