const int c = 2;
const int b = 3;
const int a = 4;
int digits[] = {a, b, c};

const int cl = 49;
const int latch = 51;
const int data = 53;

#define NUM_DIGITS 3


char leds = B10101010;


 
const char zero = B01110111;
const char one  = B01000001;
const char two  = B00111011;
const char three = B01101011;
const char four  = B01001101;
const char five  = B01101110;
const char six = B01111110;
const char seven  = B01000011;
const char eigth  = B01111111;
const char nine  = B01001111;

const char achar  = B01011111;
const char bchar  = B01111100;
const char cchar  = B00110110;
const char dchar  = B01111001;
const char echar  = B00111110;
const char fchar  = B00011110;


char numbers[] = {zero, one, two, three, four, five, six, seven, eigth, nine, achar, bchar, cchar, dchar, echar, fchar};


void setup()
{
  pinMode(cl, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);


	digitalWrite(a, 1);		
	digitalWrite(b, 1);		
	digitalWrite(c, 1);		
  updateShiftRegister(leds);
}

int step = 0;
int maxSteps = 16;
long lastUpdate = 0;
int delayTime = 500;

void loop()
{
  if(millis() - lastUpdate > delayTime){
    lastUpdate = millis();
    step = (step + 1) % maxSteps;
  }

  showDigit(a, numbers[step]);
  showDigit(b, numbers[(step + 1) % maxSteps]);
  showDigit(c, numbers[(step + 2) % maxSteps]);
}

void showDigit(int dig, char val)
{
  for(int i = 0; i < NUM_DIGITS; i ++)
    digitalWrite(digits[i], LOW);
  updateShiftRegister(val);
  digitalWrite(dig, HIGH);
  delay(10);
}


void updateShiftRegister(char value)
{
   digitalWrite(latch, LOW);
   digitalWrite(cl, LOW);
   shiftOut(data, cl, LSBFIRST, value);
   digitalWrite(latch, HIGH);
}
