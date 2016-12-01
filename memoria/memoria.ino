int variable = 20;
int variable2 = 587; 

const int datos[] PROGMEM = {0, 15, 24, 54, 23};   // use this form

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  variable += 2;
  for(int i = 0 ; i < 4 ; i ++){
    pgm_read_word_near(datos + i);
  }
  
}
