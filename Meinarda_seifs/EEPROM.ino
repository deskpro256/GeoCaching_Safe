//EEPROM MAP:
/*
   0 - timerON byte
   1 - code byte 1
   2 - code byte 2
   3 - code byte 3
   4 - code byte 4
*/


//=======================[READ FROM EEPROM]==========================
void readEEPROM() {
  //search for set byte, if present, load config, else set defaults
  if (EEPROM.read(5) != 0x69) {
    //dafault values if the code hasn't been configured. Code : 1234, timer 0x00(off)
    EEPROM.write(0, 0x00);
    EEPROM.write(1, 1);
    EEPROM.write(2, 2);
    EEPROM.write(3, 3);
    EEPROM.write(4, 4);

    EEPROM.write(5, 0x69);

  }
  else {
    timerON = EEPROM[0]; // reads the byte from eeprom to see if the timer needs to be on

    code[0] = EEPROM[1];
    code[1] = EEPROM[2];
    code[2] = EEPROM[3];
    code[3] = EEPROM[4];
  }
}


//=======================[SAVE TO EEPROM]==========================

void saveToEEPROM(unsigned int code1, unsigned int code2, unsigned int code3, unsigned int code4) {

  EEPROM.write(0, 0x00);
  EEPROM[1] = code1;
  EEPROM[2] = code2;
  EEPROM[3] = code3;
  EEPROM[4] = code4;
  EEPROM.write(5, 0x69);


  ssd1306_fillScreen(0x00);
  ssd1306_printFixedN (40, 16,   "KODS", STYLE_NORMAL, FONT_SIZE_2X);
  ssd1306_printFixedN (8, 32, "NOMAINITS!", STYLE_NORMAL, FONT_SIZE_2X);
  delay(2000);
  ssd1306_fillScreen(0x00);
  readEEPROM();

}
