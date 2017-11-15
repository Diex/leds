int A = 3;
int B = 4;
int C = 5;
int D = 6;
int E = 7;
int F = 8;
int G = 9;

int segmentos[] = {A, B, C, D, E, F, G};

int qty = 7;

int display1 = 6;
int display2 = 7;

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < qty; i++) {
    pinMode(segmentos[i], OUTPUT);
    digitalWrite(segmentos[i], HIGH);
  }

  pinMode(display1, OUTPUT);
  pinMode(display2, OUTPUT);
  
}

void loop() {

}

void seis(){
  reset();
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(E, HIGH);
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

