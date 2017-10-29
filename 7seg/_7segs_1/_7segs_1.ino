int A = 3;
int B = 4;
int C = 5;
int D = 6;
int E = 7;
int F = 8;
int G = 9;

int segmentos[] = {A, B, C, D, E, F, G};
int qty = 7;
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < qty; i++) {
    pinMode(segmentos[i], OUTPUT);
    digitalWrite(segmentos[i], HIGH);
  }

}

void loop() {
  uno();
  delay(1000);
  siete();
  delay(1000);
  ocho();
  delay(1000);
}

void ocho() {
  reset();
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void siete() {
  reset();
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void uno() {
  reset();
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);

}

void reset() {
  for (int i = 0; i < qty; i++) {
    digitalWrite(segmentos[i], LOW);
  }
}

