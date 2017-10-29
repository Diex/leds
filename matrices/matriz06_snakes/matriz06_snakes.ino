#define col7 3
#define col6 13
#define col5 A5
#define col4 A4
#define col3 A3
#define col2 A2
#define col1 A1
#define col0 A0

#define rowH 11
#define rowG 10
#define rowF 9
#define rowE 8
#define rowD 7
#define rowC 6
#define rowB 5
#define rowA 4

int rows[] = {rowA, rowB,rowC, rowD, rowE, rowF, rowG, rowH}; // X
int cols[] = {col0, col1, col2, col3, col4, col5, col6, col7}; //Y

int rowQty = 8;
int colQty = 8;


void setup() {
  start();
  for (int i = 0 ; i < 3; i++) {
    test();
  }
  blank();
}

char pattern = B10101010;

unsigned char r1 = B10101010;
unsigned char r2 = B01010101;


long t = 0;
int frame = 0;
int x = 0;
int y = 0;
int x2 = 0;
int y2 = 0;

void loop() {
  
  
  mux(1);
  drawInColumn(B11110000);
  delay(20);
  mux(4);
  drawInColumn(B11110000);
  delay(20);
  mux(6);
  drawInColumn(B11110000);
  delay(20);
  mux(7);
  drawInColumn(B11110000);
  delay(20);
  mux(2);
  drawInColumn(B11110000);
  delay(20);
  mux(0);
  drawInColumn(B11110000);
  delay(20);
  mux(3);
  drawInColumn(B11110000);
  delay(20);
  mux(5);
  drawInColumn(B11110000);
  delay(20);
  
  
  
  
  
}

  
//  snake();
//  if(random(0,3) < 1) snake2();
//  blank();
//  set(x, y, true);
//  blank();
//  set(x2, y2, true);



void snake2(){
  
  if(random(0, 1000) > 500){
    int dx = random(0, 1000) < 500 ? -1 : 1;
    x2 = (x2 + dx) > 7 || (x2 + dx) < 0 ? x2 : (x2 + dx);
    return;
  }
  
  if(random(0, 1000) > 500){
    int dy = random(0, 1000) < 500 ? -1 : 1;
    y2 = (y2 + dy) > 7 || (y2 + dy) < 0 ? y2 : (y2 + dy);
  }  
}

void snake(){
  
  if(random(0, 1000) > 500){
    int dx = random(0, 1000) < 500 ? -1 : 1;
    x = (x + dx) > 7 || (x + dx) < 0 ? x : (x + dx);
    return;
  }
  
  if(random(0, 1000) > 500){
    int dy = random(0, 1000) < 500 ? -1 : 1;
    y = (y + dy) > 7 || (y + dy) < 0 ? y : (y + dy);
  }  
}

void alterna(boolean estatico){
    if(millis() - t > 300){
      if(!estatico) frame++; 
         t = millis();   
   }
   
    
  for (int col = 0; col < colQty ; col++) {
    blank();
    mux(col);
    if (frame % 2 == 0) {
      if (col % 2 == 0) { // si la col es par
        drawInColumn(r2);
      } else {
        drawInColumn(r1);
      }
    } else {
      if (col % 2 == 0) { // si la col es par
        drawInColumn(r1);
      } else {
        drawInColumn(r2);
      }
    }
    delay(1);
  }
}

void drawInColumn(unsigned char data) {
  for (int row = 0; row < rowQty; row++) {
    digitalWrite(rows[row], bitRead(data, row) );
  }
}

void mux(int col) {
  for (int i = 0; i < colQty ; i++) {
    digitalWrite(cols[i], LOW);
  }

  digitalWrite(cols[col], HIGH);
}

void set(int x, int y, boolean state) {
  digitalWrite(cols[x],  state);
  digitalWrite(rows[y],  state);
}


void test() {
  for (int on = 0; on < colQty; on++) {
    for (int row = 0; row < rowQty ; row++) {
      digitalWrite(rows[row], LOW);
      if (on == row) digitalWrite(rows[row], HIGH);
    }

    for (int col = 0; col < colQty ; col++) {
      digitalWrite(cols[col], random(2));

    }

    delay(30);

  }


}
void start() {
  for (int row = 0; row < rowQty; row++) {
    pinMode(rows[row], OUTPUT);
    digitalWrite(rows[row], LOW);
  }

  for (int col = 0; col < colQty; col++) {
    pinMode(cols[col], OUTPUT);
    digitalWrite(cols[col], LOW);
  }

}
void blank() {
  for (int row = 0; row < rowQty ; row++) {
    digitalWrite(rows[row], LOW);
  }
  for (int col = 0; col < colQty ; col++) {
    digitalWrite(cols[col], LOW);
  }

}


