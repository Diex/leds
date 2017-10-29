void setup(){  // se ejecuta una sola vez.
 pinMode(6, OUTPUT); 
}

void loop(){
  digitalWrite(6, HIGH);
  delay(2000);
  digitalWrite(6, LOW);
  delay(2000);
}

