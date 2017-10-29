int rojo = 9; //pin 9

void setup() { // se ejecuta una sola vez.
  pinMode(rojo, OUTPUT);
  Serial.begin(115200);
}



void loop() {

  for (   int i = 0; i < 255; i = i + 5) { // si i es menor que 255.. blbl
    analogWrite(rojo, i);
    Serial.println(i);
    delay(25);
  }

  for (int i = 0; i < 255; i += 5) {
    analogWrite(rojo, 255 - i);
    Serial.println(255 - i);
    delay(25);
  }
}


