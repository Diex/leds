#define row7 5
#define row6 4
#define row5 3
#define row4 2


#define colH 6
#define colG 7
#define colF 8
#define colE 9

int rows[] = {row7, row6, row5, row4};
int cols[] = {colH, colG, colF, colE};

byte pattern = B01010101;

void setup() {
  for (int row = 0; row < 4; row++) {
    pinMode(rows[row], OUTPUT);
    digitalWrite(rows[row], LOW);
  }

  for (int col = 0; col < 4; col++) {
    pinMode(cols[col], OUTPUT);
    digitalWrite(cols[col], LOW);
  }

  for(int i = 0 ; i < 15; i++){
    test();
  }

  blank();
}

void loop() {

  while(true){
    blank();
    set(random(4), random(4), HIGH);
    delay(500);
  }

}

void set(int x, int y, boolean state){
  digitalWrite(cols[x],  state);
  digitalWrite(rows[y],  state);
}


void test(){
    for (int on = 0; on < 4; on++) {
    for (int row = 0; row < 4 ; row++) {
      digitalWrite(rows[row], LOW);
      if (on == row) digitalWrite(rows[row], HIGH);
    }
    
    for (int col = 0; col < 4 ; col++) {      
      digitalWrite(cols[col], random(2));      
    
    }
    
    delay(30);

  }


}

void blank(){
    for (int row = 0; row < 4 ; row++) {
      digitalWrite(rows[row], LOW);
    }
  for (int col = 0; col < 4 ; col++) {
      digitalWrite(cols[col], LOW);
    }

}


