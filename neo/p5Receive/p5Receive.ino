#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUMPIXELS 60 // Number of LEDs in array
#define PIN 5 // Ardunio data pin

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10; // delay for half a second
int ColVal[] = {50,0,0};

int cnt;

void setup()
{
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  cnt = 0;
}

void loop()
{
  if (Serial.available())
  {
   char chan = Serial.read(); //channel
   int val = Serial.parseInt();//value
   setval(chan, val);
   String data = (String(ColVal[0]) + " "+ String(ColVal[1]) +" " + String(ColVal[2]));
   Serial.println(data); 
  }
}

void setval(char col, int dataV)
{ 
  if (col == 'r')
  {
   ColVal[0] = dataV;
   cnt ++;
  }
  if (col == 'g')
  {
    ColVal[1] = dataV;
    cnt ++;
  }
  if (col == 'b')
  {
   ColVal[2] = dataV;
   cnt ++;
  }
  ;
  if (cnt % 3 == 0)
  {
    go();
  }
}

void go()
{
  ;
  for(int i=0;i<NUMPIXELS;i++) //Climb LED with received colour value
  {
    strip.setPixelColor(i, strip.Color(ColVal[0],ColVal[1],ColVal[2]));
    strip.show(); // This sends the updated pixel color to the hardware
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
}
