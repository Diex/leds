//int A = 3;
//int B = 4;
//int C = 5;
//int D = 6;
//int E = 7;
//int F = 8;
//int G = 9;
//
//int segmentos[] = {A, B, C, D, E, F, G};

byte zero = B01111110;

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

//set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(display1, OUTPUT);
  pinMode(display2, OUTPUT);
  
}

void loop() {
  // muestro un caracter
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, LSBFIRST, zero);  
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);

    digitalWrite(display1, HIGH);
    digitalWrite(display2, LOW);
    delay(10);
  // muestro el otro 
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, B10101010);  
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);

    digitalWrite(display1, LOW);
    digitalWrite(display2, HIGH);
    delay(10);
}

/*
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
*/
