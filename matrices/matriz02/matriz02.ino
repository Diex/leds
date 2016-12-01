#define col7 5
#define col6 4
#define col5 3
#define col4 2


#define rowH 6
#define rowG 7
#define rowF 8
#define rowE 9

int rows[] = {col7, col6, col5, col4};
int cols[] = {rowH, rowG, rowF, rowE};


void setup() {
  start();
  for (int i = 0 ; i < 3; i++) {
    test();
  }
  blank();
}

char pattern = B10101010;

void loop() {  
  
  
  
  for (int col = 0; col< 4 ; col++) {
      drawInColumn(pattern);      
      mux(col);  
  }
}


void drawInColumn(char data){
  for(int row = 0; row < 4; row++){
    digitalWrite(rows[row], bitRead(pattern, row));
  }
  
}

void mux(int col) {
  for (int i = 0; i < 4 ; i++) {
    digitalWrite(cols[i], LOW);
  }
  digitalWrite(cols[col], HIGH);
}

void set(int x, int y, boolean state) {
  digitalWrite(cols[x],  state);
  digitalWrite(rows[y],  state);
}


void test() {
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

void start() {
  for (int row = 0; row < 4; row++) {
    pinMode(rows[row], OUTPUT);
    digitalWrite(rows[row], LOW);
  }

  for (int col = 0; col < 4; col++) {
    pinMode(cols[col], OUTPUT);
    digitalWrite(cols[col], LOW);
  }

}
void blank() {
  for (int row = 0; row < 4 ; row++) {
    digitalWrite(rows[row], LOW);
  }
  for (int col = 0; col < 4 ; col++) {
    digitalWrite(cols[col], LOW);
  }

}


