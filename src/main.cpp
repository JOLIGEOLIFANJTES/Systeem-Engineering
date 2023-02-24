#include <Arduino.h>
#define Knop1 4
#define Knop2 3 
#define Knop3 6 
#define Knop4 5 
#define Knop5 7  
#define Knop6 8
#define Knop7 9
#define Knop8 10

int counter = 0;
int counter0_05S =0;
int counter2 = 0;

void spel1();
void spel2();
void spel3();
void spel4();
void setupTimer1();

ISR(TIMER1_COMPA_vect) {
  counter0_05S = counter0_05S +1;
  counter2 = counter2 +1;
  if (counter0_05S == 20){
    counter = counter + 1;
    counter0_05S =0;
  }
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
if(digitalRead(Knop1) == LOW){
  spel1();
}
else if(digitalRead(Knop2) == LOW){
  spel2();
}
else if(digitalRead(Knop3) == LOW){
  spel3();
}
else if(digitalRead(Knop4) == LOW){
  spel4();
}
}

void spel1(){
  Serial.print("spel1");
  delay(500);
  int player1 = 0, player2 =0, player3 =0, player4 =0;
  int winning = 1;
  const int TIMEPERIOD = 30;
  int winningscore = 0;
  int oldstatusknop1, oldstatusknop2, oldstatusknop3, oldstatusknop4;
  Serial.print("drukkkken");
  counter =0;
  while (counter < TIMEPERIOD) {
  int statusknop1 = digitalRead(Knop5);
  if (statusknop1 != oldstatusknop1){if(statusknop1 == LOW){player1 = player1 +1;}}
  int statusknop2 = digitalRead(Knop6); 
  if (statusknop2 != oldstatusknop2){if(statusknop2 == LOW){player2 = player2 +1;}}
  int statusknop3 = digitalRead(Knop7); 
  if (statusknop3 != oldstatusknop3){if(statusknop3 == LOW){player3 = player3 +1;}}
  int statusknop4 = digitalRead(Knop8); 
  if (statusknop4 != oldstatusknop4){if(statusknop4 == LOW){player4 = player4 +1;}}
  delay(50);
  oldstatusknop1 = statusknop1;
  oldstatusknop2 = statusknop2;
  oldstatusknop3 = statusknop3;
  oldstatusknop4 = statusknop4;
  Serial.println(counter);
  }
  winningscore = player1;
  if(winningscore < player2){ winning = 2; winningscore = player2;}
  if(winningscore < player3){ winning = 3; winningscore = player3;}
  if(winningscore < player4){ winning = 4; winningscore = player4;}
  Serial.print("player");Serial.print(winning);Serial.print(" has won with:");Serial.print(winningscore);Serial.print(" points");
}

void spel2(){
  Serial.println("spel2");
  delay(500);
  int player1 = 0;
  int player2 = 0;
  int player3 = 0;
  int player4 = 0;
  int player1T = 0;
  int player2T = 0;
  int player3T = 0;
  int player4T = 0;
  int winning = 0;
  counter = 0;
  counter2 =0;
  long TIMEPERIOD = random(60) * 20;
  Serial.println(TIMEPERIOD);
  float winningscore = 0;
  while (player1 == 0 || player2 == 0 || player3 == 0 || player4 == 0) {
    if(digitalRead(Knop5) == LOW){ if(player1 ==0){player1T = counter2 - TIMEPERIOD;} player1 = player1 +1;}
    if(digitalRead(Knop6) == LOW){ if(player2 ==0){player2T = counter2 - TIMEPERIOD;} player2 = player2 +1;}
    if(digitalRead(Knop7) == LOW){ if(player3 ==0){player3T = counter2 - TIMEPERIOD;} player3 = player3 +1;}
    if(digitalRead(Knop8) == LOW){ if(player4 ==0){player4T = counter2 - TIMEPERIOD;} player4 = player4 +1;}
    if(counter2 == TIMEPERIOD){ Serial.println("piep");}
  }
  if (player1T >= 0 && player1T < player2T && player1T < player3T && player1T < player4T){winning = 1; winningscore = player1T /20;}
  if (player2T >= 0 && player2T < player1T && player2T < player3T && player2T < player4T){winning = 2; winningscore = player2T /20;}
  if (player3T >= 0 && player3T < player1T && player3T < player2T && player3T < player4T){winning = 3; winningscore = player3T /20;}
  if (player4T >= 0 && player4T < player1T && player4T < player2T && player4T < player3T){winning = 4; winningscore = player4T /20;}
  Serial.print("player");Serial.print(winning);Serial.print(" has won with:");Serial.print(winningscore);Serial.print(" seconds from the beep");
}
void spel3(){
  Serial.println("spel3");
  long TIMEPERIOD = random(60) * 20;
  Serial.print("druk na "); Serial.print(TIMEPERIOD/20);Serial.println("seconden");
  int player1 = 0;
  int player2 = 0;
  int player3 = 0;
  int player4 = 0;
  int player1T = 0;
  int player2T = 0;
  int player3T = 0;
  int player4T = 0;
  int winning = 0;
  counter = 0;
  counter2 =0;
  float winningscore = 0;
    while (player1 == 0 || player2 == 0 || player3 == 0 || player4 == 0) {
    if(digitalRead(Knop5) == LOW){ if(player1 ==0){player1T = counter2 - TIMEPERIOD;} player1 = player1 +1;}
    if(digitalRead(Knop6) == LOW){ if(player2 ==0){player2T = counter2 - TIMEPERIOD;} player2 = player2 +1;}
    if(digitalRead(Knop7) == LOW){ if(player3 ==0){player3T = counter2 - TIMEPERIOD;} player3 = player3 +1;}
    if(digitalRead(Knop8) == LOW){ if(player4 ==0){player4T = counter2 - TIMEPERIOD;} player4 = player4 +1;}
    Serial.println(counter);
  }
  Serial.println(player1T);
  Serial.println(player2T);
  Serial.println(player3T);
  Serial.println(player4T);
  if (player1T < 0){player1T = player1T/-1;}
  if (player2T < 0){player2T = player2T/-1;}
  if (player3T < 0){player3T = player3T/-1;}
  if (player4T < 0){player4T = player4T/-1;}
  Serial.println(player1T);
  Serial.println(player2T);
  Serial.println(player3T);
  Serial.println(player4T);
  if (player1T >= 0 && player1T < player2T && player1T < player3T && player1T < player4T){winning = 1; winningscore = player1T /20;}
  if (player2T >= 0 && player2T < player1T && player2T < player3T && player2T < player4T){winning = 2; winningscore = player2T /20;}
  if (player3T >= 0 && player3T < player1T && player3T < player2T && player3T < player4T){winning = 3; winningscore = player3T /20;}
  if (player4T >= 0 && player4T < player1T && player4T < player2T && player4T < player3T){winning = 4; winningscore = player4T /20;}
  Serial.print("player");Serial.print(winning);Serial.print(" has won with:");Serial.print(winningscore);Serial.print(" seconds from point");
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
  OCR1A = 780;
  // CTC
  TCCR1B |= (1 << WGM12);
  // Prescaler 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // Output Compare Match A Interrupt Enable
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}