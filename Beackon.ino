int L   = 2;

int val = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  while(!Serial.avaible){
    delay(100);
  }
  
  val = Serial.read();
  
  if(val == '0'){
    tone(L, 0);
  }
  if(val == '1'){
    tone(L, 40000);
    delay(250);
    notone(L);
    delay(250);
  }
}
