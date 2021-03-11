#include <Servo.h>

Servo SD;

int B1       = A0;

int PIN_ECHO1 = 11;
int PIN_TRIG1 = 12;
int PIN_ECHO2 = 13;
int PIN_TRIG2 = 14;
bool state = 0;


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
}


void left(){
}


void right(){
}

void back(){
}

void maykosnvkl(){
}

void maykosnvikl(){
}

void maykrezervvkl(){
}

void maykrezervvikl(){
}

void loop() {
  
  
  
}
