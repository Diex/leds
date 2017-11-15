//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to the CLK
 pin 10 is connected to LOAD
 We have only a single MAX72XX.
 */

#define row1  B11111111
#define row2  B11000011
#define row3  B11000011
#define row4  B11111111
#define row5  B11000000
#define row6  B11000000
#define row7  B11000000
#define row8  B11000000

byte A[] = {row1, row2, row3, row4, row5, row6, row7, row8};

LedControl lc=LedControl(12,11,10,1);
//LedControl lc=LedControl(5,7,6,1);
/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,4);
  /* and clear the display */
  lc.clearDisplay(0);

  
}

void loop() {
  lc.clearDisplay(0);
  
  for(int i = 0; i < sizeof(A)/sizeof(byte); i++){
    lc.setRow(0,i,A[i]);
  }

  delay(1000);
}
