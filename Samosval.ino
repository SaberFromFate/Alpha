#include <Servo.h>

Servo SD;

int B1       = A0;

int S1       = A1;
int S2       = A2;

int PIN_ECHO1 = 11;
int PIN_TRIG1 = 12;
int PIN_ECHO2 = 13;
int PIN_TRIG2 = 14;

int MAB       =  2;
int MAA       =  3;
int MBB       =  4;
int MBA       =  5;

bool state    =  0;

long duration1,cm1,cm2,duration2;


void setup() {
  Serial.begin(9600);
  Serial.println("Слава Кайзеру");
  SD.attach(20);
  SD.write(0);
  
  pinMode(PIN_ECHO1,INPUT);
  pinMode(PIN_TRIG1,OUTPUT);
  pinMode(PIN_ECHO2,INPUT);
  pinMode(PIN_TRIG2,OUTPUT);
  
  pinMode(MAA, OUTPUT);
  pinMode(MAB, OUTPUT);
  pinMode(MBB, OUTPUT);
  pinMode(MBA, OUTPUT);
  
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
}

void dist1() {
  digitalWrite(PIN_TRIG1, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG1, LOW);
  duration1 = pulseIn(PIN_ECHO1, HIGH);
  cm1 = (duration1 / 2) / 29.1;
  if (cm1 <= 30){
    state = 1;
  }
  delay(100);
}

void dist2() {
  digitalWrite(PIN_TRIG2, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG2, LOW);
  duration2 = pulseIn(PIN_ECHO2, HIGH);
  cm2 = (duration2 / 2) / 29.1;
  if (cm2 <= 30){
    state = 1;
  }
  delay(100);
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
  digitalWrite(MBB, 0);
  delay(100);
}


void right(){
  digitalWrite(MAA, 0);
  digitalWrite(MAB, 0);
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

void maykosnvkl(){
}

void maykosnvikl(){
}

void loop() {
  while(digitalRead(B1) == 0 or data == 0){
    delay(100);
  }
  
  
}
