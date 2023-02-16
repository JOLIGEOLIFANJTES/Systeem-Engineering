#include <Arduino.h>
#define Knop1 2
#define Knop2 3
#define Knop3 4
#define Knop4 5
#define Knop5 6
#define Knop6 7
#define Knop7 8
#define Knop8 9

int counter = 0;
const int TIMEPERIOD = 30;

void spel1();
void spel2();
void spel3();
void spel4();
void setupTimer1();

ISR(TIMER1_COMPA_vect) {
  counter = counter + 1;
}

void setup() {
  Serial.begin(9600);
  pinMode(Knop1, INPUT_PULLUP);
  pinMode(Knop2, INPUT_PULLUP);
  pinMode(Knop3, INPUT_PULLUP);
  pinMode(Knop4, INPUT_PULLUP);
  pinMode(Knop5, INPUT_PULLUP);
  pinMode(Knop6, INPUT_PULLUP);
  pinMode(Knop7, INPUT_PULLUP);
  pinMode(Knop8, INPUT_PULLUP);
  setupTimer1();
}

void loop() {

}

void spel1(){
  int player1 = 0;
  int player2 = 0;
  int player3 = 0;
  int player4 = 0;
  int winning = 1;
  int winningscore = 0;
  while (counter < TIMEPERIOD) {
    if(digitalRead(Knop1) == RISING){ player1 +1; }
    if(digitalRead(Knop2) == RISING){ player2 +1; }
    if(digitalRead(Knop3) == RISING){ player3 +1; }
    if(digitalRead(Knop4) == RISING){ player4 +1; }
  }
  counter =0;
  winningscore = player1;
  if(winningscore < player2){ winning = 2; winningscore = player2;}
  if(winningscore < player3){ winning = 3; winningscore = player3;}
  if(winningscore < player4){ winning = 4; winningscore = player4;}
  Serial.print("player");Serial.print(winning);Serial.print(" has won with:");Serial.print(winningscore);Serial.print(" points");
}

void spel2(){
  
}

void spel3(){
  
}

void spel4(){
  
}

void setupTimer1() {
  noInterrupts();
  // Clear registers
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  // 1 Hz (16000000/((15624+1)*1024))
  OCR1A = 15624;
  // CTC
  TCCR1B |= (1 << WGM12);
  // Prescaler 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // Output Compare Match A Interrupt Enable
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}