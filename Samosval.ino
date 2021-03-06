#include <Servo.h>

Servo SD;

int B1       = A0;

int PIN_ECHO = 11;
int PIN_TRIG = 12;

bool state = 0;

void dist() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  duration = pulseIn(PIN_ECHO, HIGH);
  cm = (duration / 2) / 29.1;
  if cm <= 30{
    state = 1;
  }
  delay(100);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Слава Кайзеру");
  SD.attach(20);
  SD.write(0);
}

void loop() {
}
