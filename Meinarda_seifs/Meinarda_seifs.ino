#include <HID.h>


/*
  pinMode(0, OUTPUT);         // SOLENOID  PA0
  pinMode(1, INPUT_PULLUP);   // START  PA1
  pinMode(2, INPUT_PULLUP);   // STOP   PA2
  pinMode(3, OUTPUT);         // BUZZER PA3
  pinMode(7, INPUT);          // POT    PA7
  //pinMode(8, INPUT);          // SENSOR PB2
*/

//=======================[INCLUDES]==========================
#include <avr/io.h>
#include "ssd1306.h"
#include <EEPROM.h>

#define NOP __asm__ __volatile__ ("nop\n\t")

//=======================[VARIABLES]==========================

unsigned int val = 0; //analog value from pin
char valChar[2] = {'-'};

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
unsigned int intervalSecond = 1000;
unsigned int timeout = 60;
unsigned int countdown = 0;
char countdownChar[3] = {'-', '-'};

unsigned int code[4] = {1, 2, 3, 4}; // default code = [1234]
char codeChar[5] = {'-', '-', '-', '-'};
unsigned int enteredCode[4] = {1, 2, 3, 4}; //
char enteredCodeChar[5] = {'-', '-', '-', '-'};
unsigned int newCode[4] = {0, 0, 0, 0}; //
char newCodeChar[5] = {'-', '-', '-', '-'};
bool codeCorrect = false;

volatile bool advance = false;

unsigned int timerON = 0x00; // 0x00 if off, 0x01 if on boolean codeCorrect = false;
//=======================[SETUP]==========================
void setup() {
  //------[PIN COFING]-----
  //1 = OUTPUT // 0 = INPUT
  DDRA |= 0b00001001;
  PORTA |= (1 << PA1);
  PORTA |= (1 << PA2);

  //------[ISR SETUP]------
  /*
    PCMSK0 |= 0B000000010;
    GIMSK |= (1 << PCIE0);
  */
  //------[ISR SETUP]------

  splashMusic();
  displaySetup();
  readEEPROM();
  start();
}

void NOPdelay(unsigned int duration) {
  for (unsigned int q = 0; q <= duration; q++) {
    NOP;
  }
}


//===========================[SOFT_START]==========================
void softStart() {
  ssd1306_fillScreen(0x00);
  ssd1306_printFixed (40, 24, "PARBAUDU!", STYLE_BOLD);
  unsigned int on = 0;
  unsigned int off = 100;
  while (on < 100) {
    PORTA |= (1 << PA0);
    delay(on);
    PORTA &= !(1 << PA0);
    delay(off);
    on = on + 10;
    off = off - 10;
  }
}

void start() {
  if (timerON == 0x00) {
    splashScreen();
  }
  else if (timerON == 0x01) {
    timerStart();
  }
}

//=======================[LOOP]==========================
void loop() {
}
