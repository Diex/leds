// audio input con el electret a rele

int sensor = 3;
int rele = 4;
boolean estado = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(rele, OUTPUT);
}

void loop() {  
  // put your main code here, to run repeatedly:
  if(digitalRead(sensor) == LOW){
    estado = !estado;
    digitalWrite(rele, estado);
    delay(3);
  }
}
