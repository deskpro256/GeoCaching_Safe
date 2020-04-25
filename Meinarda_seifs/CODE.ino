
//=======================[ENTER CODE]==========================
void enterCode() {
  unsigned int currentBit = 0;
  int currentDebounceMillis = 0;
  int previousDebounceMillis = 0;

  while (currentBit <= 3) {
    currentMillis = millis();
    int currentDebounceMillis = currentMillis;
    if (currentMillis - previousMillis >= 1) {
      previousMillis = currentMillis;
      val = analogRead(7);
      val = map(val, 0, 1023, 0, 9);
      valChar[0] = val + '0';

      ssd1306_printFixed (50, 8, "KODS:", STYLE_NORMAL);
      ssd1306_printFixedN (56, 20, valChar, STYLE_NORMAL, FONT_SIZE_2X);
      ssd1306_printFixedN (40, 48, enteredCodeChar, STYLE_NORMAL, FONT_SIZE_2X);

      if (advance) {
        advance = false;
        enteredCode[currentBit] = val;
        enteredCodeChar[currentBit] = valChar[0];
        currentBit++;
      }
    }

    if (currentDebounceMillis - previousDebounceMillis >= 200 && digitalRead(PA1) == LOW) {
      advance = true;
      previousDebounceMillis = currentDebounceMillis;
    }

    if (digitalRead(PA2) == LOW) {
      changeCode();
    }

  }
  ssd1306_printFixed (50, 8, "KODS:", STYLE_NORMAL);
  ssd1306_printFixedN (40, 48, enteredCodeChar, STYLE_NORMAL, FONT_SIZE_2X);
  delay(1000);
  checkCode();

}

//=======================[CHECK CODE]==========================

void checkCode() {
  
  enteredCodeChar[0] = '-';
  enteredCodeChar[1] = '-';
  enteredCodeChar[2] = '-';
  enteredCodeChar[3] = '-';

  if (enteredCode[0] == code[0] && enteredCode[1] == code[1] && enteredCode[2] == code[2] && enteredCode[3] == code[3]) {
    codeCorrect = true;
  }
  else {
    codeCorrect = false;
  }
  if (codeCorrect) {
    codeCorrect = false;
    PORTA |= (1 << PA0); // OPENS DOOR
    openingDoor();
  }
  else {
    PORTA &= ~(1 << PA0); // CLOSES DOOR
    wrongCode();
    timerStart();
  }

}


//=======================[CHANGE CODE]==========================

void changeCode() {

  ssd1306_fillScreen(0x00);
  newCodeChar[0] = '-';
  newCodeChar[1] = '-';
  newCodeChar[2] = '-';
  newCodeChar[3] = '-';

  unsigned int currentBit = 0;
  int currentDebounceMillis = 0;
  int previousDebounceMillis = 0;

  while (currentBit <= 3) {
    currentMillis = millis();
    int currentDebounceMillis = currentMillis;
    if (currentMillis - previousMillis >= 1) {
      previousMillis = currentMillis;
      val = analogRead(7);
      val = map(val, 0, 1023, 0, 9);
      valChar[0] = val + '0';

      ssd1306_printFixed (26, 8, "JAUNAIS KODS:", STYLE_NORMAL);
      ssd1306_printFixedN (56, 16, valChar, STYLE_NORMAL, FONT_SIZE_2X);
      ssd1306_printFixedN (40, 48, newCodeChar, STYLE_NORMAL, FONT_SIZE_2X);


      if (advance) {
        advance = false;
        newCode[currentBit] = val;
        newCodeChar[currentBit] = valChar[0];
        currentBit++;
      }
    }

    if (currentDebounceMillis - previousDebounceMillis >= 200 && digitalRead(PA1) == LOW) {
      advance = true;
      previousDebounceMillis = currentDebounceMillis;
    }
  }
  ssd1306_printFixed (26, 8, "JAUNAIS KODS:", STYLE_NORMAL);
  ssd1306_printFixedN (40, 48, newCodeChar, STYLE_NORMAL, FONT_SIZE_2X);
  delay(1000);
  saveToEEPROM(newCode[0], newCode[1], newCode[2], newCode[3]);
}
