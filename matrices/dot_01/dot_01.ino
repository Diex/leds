int row1 = 5;
int row2 = 4;
int row3 = 3;
int row4 = 2;



//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;


void setup() {
    // put your setup code here, to run once:
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

byte data   = B00000001;
byte data2  = B00000010;
void loop() {
  // muestro un caracter
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, data);  
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    delay(1000);

    
    digitalWrite(row1, HIGH);
    digitalWrite(row2, HIGH);
    digitalWrite(row3, HIGH);
    digitalWrite(row4, HIGH);

      // muestro un caracter
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, data2);  
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    delay(1000);


// muestro un caracter

}
