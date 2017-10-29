int rojo = 6;
int amarillo = 5;
int verde = 4;


void setup() { // se ejecuta una sola vez.
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
}




void loop() {

  digitalWrite(rojo, HIGH);
  delay(2000);
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, HIGH);
  delay(500);
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, HIGH);
  delay(2000);
  digitalWrite(verde, LOW);
  digitalWrite(amarillo, HIGH);
  delay(500);
  digitalWrite(amarillo, LOW);
  
}


