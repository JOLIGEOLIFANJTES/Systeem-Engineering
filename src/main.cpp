#include <Arduino.h> //include library's
#include <Talkie.h>
#include <Vocab_US_Large.h>
#include <Vocab_Special.h>
#include <Vocab_US_TI99.h>

#define Knop1 4 //define knoppins
#define Knop2 2 
#define Knop3 6 
#define Knop4 5 
#define Knop5 7  
#define Knop6 8
#define Knop7 9
#define Knop8 10

int counter = 0; //define timer counters
int counter0_05S =0;
int counter2 = 0;

Talkie voice; //talkie library define

void spel1(); //define voids
void spel2();
void spel3();
void spel4();
void setupTimer1();
void sayNumber(long n);

ISR(TIMER1_COMPA_vect) {    //timer void (word elke 50ms)
  counter0_05S = counter0_05S +1; //timer 50ms (gebruikt voor 1 sec timer)
  counter2 = counter2 +1; //timer 50ms voor 50ms timer
  if (counter0_05S == 20){  //if voor timer elke seconden
    counter = counter + 1;
    counter0_05S =0;
  }
}

void setup() { //void setup
  Serial.begin(9600); //open serial voor debug
  pinMode(Knop1, INPUT_PULLUP); //pin setup
  pinMode(Knop2, INPUT_PULLUP);
  pinMode(Knop3, INPUT_PULLUP);
  pinMode(Knop4, INPUT_PULLUP);
  pinMode(Knop5, INPUT_PULLUP);
  pinMode(Knop6, INPUT_PULLUP);
  pinMode(Knop7, INPUT_PULLUP);
  pinMode(Knop8, INPUT_PULLUP);
  setupTimer1(); //setup timer 50ms
  voice.say(spt_THERE); delay(100); voice.say(spt_ARE); delay(100); voice.say(sp3_THREE); delay(100); voice.say(spt_GAMES); delay(100); voice.say(spt_START); //zin uitspreken
}

void loop() {
if(digitalRead(Knop1) == LOW){ //check of knop 1 ingedrukt is
  voice.say(sp2_ONE);
  spel1();
}
else if(digitalRead(Knop2) == LOW){ //check of knop 2 ingedrukt is
  voice.say(sp2_TWO);
  spel2();
}
else if(digitalRead(Knop3) == LOW){ //check of knop 3 ingedrukt is
  voice.say(sp2_THREE);
  spel3();
}
else if(digitalRead(Knop4) == LOW){ //check of knop 4 ingedrukt is
  voice.say(sp2_FOUR);
  spel4();
}
}

void spel1(){
  int player1 = 0, player2 =0, player3 =0, player4 =0; //define alle variabelen die nodig zijn
  int winning = 1;
  const int TIMEPERIOD = 30;
  int winningscore = 0;
  int oldstatusknop1, oldstatusknop2, oldstatusknop3, oldstatusknop4;
  delay(500); //even wachten zodat het niet te snel gaat
  voice.say(sp4_START); //say start
  setupTimer1(); //setup timer 50ms (dit omdat de timer ook bij uitspreken word gebruikt)
  counter =0; //set counter naar 0
  while (counter < TIMEPERIOD) { //blijf herhalen tot counter < Timerperiode of ook wel 30 seconden lang
  int statusknop1 = digitalRead(Knop5); //define variabelen
  int statusknop2 = digitalRead(Knop6); 
  int statusknop3 = digitalRead(Knop7); 
  int statusknop4 = digitalRead(Knop8); 
  if (statusknop1 != oldstatusknop1){ //check of de status van de knop niet gelijk is aan de oude status
    if(statusknop1 == LOW){ //check of de status van de knop niet ingedrukt is
        player1 = player1 +1;}} //doe +1 bij de score van de player
  if (statusknop2 != oldstatusknop2){
    if(statusknop2 == LOW){
        player2 = player2 +1;}}
  if (statusknop3 != oldstatusknop3){
    if(statusknop3 == LOW){
        player3 = player3 +1;}}
  if (statusknop4 != oldstatusknop4){
    if(statusknop4 == LOW){
        player4 = player4 +1;}}
  delay(50); 
  oldstatusknop1 = statusknop1; //oudestutus word gelijk aan nieuwe status gezet
  oldstatusknop2 = statusknop2;
  oldstatusknop3 = statusknop3;
  oldstatusknop4 = statusknop4;
  Serial.println(counter); //serial print timer
  }
  winningscore = player1; //winning word gelijk gezet aan de score van player 1
  if(winningscore < player2){ // als winningscore kleiner is als die van player 2 zet deze naar de score van player 2 en sla op dat player 2 gewonnen heeft
    winning = 2; winningscore = player2;} 
  if(winningscore < player3){ 
    winning = 3; winningscore = player3;}
  if(winningscore < player4){ 
    winning = 4; winningscore = player4;}
  voice.say(sp2_NUMBER); sayNumber(winning); voice.say(spt_WON); voice.say(spt_WITH); sayNumber(winningscore); voice.say(sp2_PRESS); //spreek zin uit
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
  voice.say(sp4_START);
  setupTimer1();
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
    if(counter2 == TIMEPERIOD){ Serial.println("piep"); voice.say(spt_NOW); setupTimer1();}
  }
  if (player1T >= 0 && player1T < player2T && player1T < player3T && player1T < player4T){winning = 1; winningscore = player1T /20;}
  if (player2T >= 0 && player2T < player1T && player2T < player3T && player2T < player4T){winning = 2; winningscore = player2T /20;}
  if (player3T >= 0 && player3T < player1T && player3T < player2T && player3T < player4T){winning = 3; winningscore = player3T /20;}
  if (player4T >= 0 && player4T < player1T && player4T < player2T && player4T < player3T){winning = 4; winningscore = player4T /20;}
  Serial.print("player");Serial.print(winning);Serial.print(" has won with:");Serial.print(winningscore);Serial.print(" seconds from the beep");
  voice.say(sp2_NUMBER); sayNumber(winning); voice.say(spt_WON); voice.say(spt_WITH); sayNumber(winningscore); voice.say(sp2_SECONDS); 
}
void spel3(){
  Serial.println("spel3");
  long TIMEPERIOD = random(60) * 20;
  Serial.print("druk na "); Serial.print(TIMEPERIOD/20);Serial.println("seconden");
  voice.say(sp2_PRESS); voice.say(spt_AFTER); sayNumber(TIMEPERIOD/20); voice.say(sp2_SECONDS);
  delay(2000);
  int player1 = 0;
  int player2 = 0;
  int player3 = 0;
  int player4 = 0;
  int player1T = 0;
  int player2T = 0;
  int player3T = 0;
  int player4T = 0;
  int winning = 0;
  voice.say(sp4_START);
  setupTimer1();
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
  if (player1T < 0){player1T = player1T/-1;}
  if (player2T < 0){player2T = player2T/-1;}
  if (player3T < 0){player3T = player3T/-1;}
  if (player4T < 0){player4T = player4T/-1;}
  if (player1T >= 0 && player1T < player2T && player1T < player3T && player1T < player4T){winning = 1; winningscore = player1T /20;}
  if (player2T >= 0 && player2T < player1T && player2T < player3T && player2T < player4T){winning = 2; winningscore = player2T /20;}
  if (player3T >= 0 && player3T < player1T && player3T < player2T && player3T < player4T){winning = 3; winningscore = player3T /20;}
  if (player4T >= 0 && player4T < player1T && player4T < player2T && player4T < player3T){winning = 4; winningscore = player4T /20;}
  Serial.print("player");Serial.print(winning);Serial.print(" has won with:");Serial.print(winningscore);Serial.print(" seconds from point");
  voice.say(sp2_NUMBER); sayNumber(winning); voice.say(spt_WON); voice.say(spt_WITH); sayNumber(winningscore); voice.say(sp2_SECONDS); 
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

void sayNumber(long n) {
    if (n < 0) {
        voice.say(sp2_MINUS);
        sayNumber(-n);
    } else if (n == 0) {
        voice.say(sp2_ZERO);
    } else {
        if (n >= 1000) {
            int thousands = n / 1000;
            sayNumber(thousands);
            voice.say(sp2_THOUSAND);
            n %= 1000;
            if ((n > 0) && (n < 100))
                voice.say(sp2_AND);
        }
        if (n >= 100) {
            int hundreds = n / 100;
            sayNumber(hundreds);
            voice.say(sp2_HUNDRED);
            n %= 100;
            if (n > 0)
                voice.say(sp2_AND);
        }
        if (n > 19) {
            int tens = n / 10;
            switch (tens) {
            case 2:
                voice.say(sp2_TWENTY);
                break;
            case 3:
                voice.say(sp2_THIR_);
                voice.say(sp2_T);
                break;
            case 4:
                voice.say(sp2_FOUR);
                voice.say(sp2_T);
                break;
            case 5:
                voice.say(sp2_FIF_);
                voice.say(sp2_T);
                break;
            case 6:
                voice.say(sp2_SIX);
                voice.say(sp2_T);
                break;
            case 7:
                voice.say(sp2_SEVEN);
                voice.say(sp2_T);
                break;
            case 8:
                voice.say(sp2_EIGHT);
                voice.say(sp2_T);
                break;
            case 9:
                voice.say(sp2_NINE);
                voice.say(sp2_T);
                break;
            }
            n %= 10;
        }
        switch (n) {
        case 1:
            voice.say(sp2_ONE);
            break;
        case 2:
            voice.say(sp2_TWO);
            break;
        case 3:
            voice.say(sp2_THREE);
            break;
        case 4:
            voice.say(sp2_FOUR);
            break;
        case 5:
            voice.say(sp2_FIVE);
            break;
        case 6:
            voice.say(sp2_SIX);
            break;
        case 7:
            voice.say(sp2_SEVEN);
            break;
        case 8:
            voice.say(sp2_EIGHT);
            break;
        case 9:
            voice.say(sp2_NINE);
            break;
        case 10:
            voice.say(sp2_TEN);
            break;
        case 11:
            voice.say(sp2_ELEVEN);
            break;
        case 12:
            voice.say(sp2_TWELVE);
            break;
        case 13:
            voice.say(sp2_THIR_);
            voice.say(sp2__TEEN);
            break;
        case 14:
            voice.say(sp2_FOUR);
            voice.say(sp2__TEEN);
            break;
        case 15:
            voice.say(sp2_FIF_);
            voice.say(sp2__TEEN);
            break;
        case 16:
            voice.say(sp2_SIX);
            voice.say(sp2__TEEN);
            break;
        case 17:
            voice.say(sp2_SEVEN);
            voice.say(sp2__TEEN);
            break;
        case 18:
            voice.say(sp2_EIGHT);
            voice.say(sp2__TEEN);
            break;
        case 19:
            voice.say(sp2_NINE);
            voice.say(sp2__TEEN);
            break;
        }
    }
}