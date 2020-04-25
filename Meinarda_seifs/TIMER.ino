
//=======================[START TIMER]==========================
void timerStart() {

  EEPROM[0] = 0x01; //timer needs to be on if somebody tries to just restart the machine to bypass the timeout period

  //countdown = timeout ;
  countdown = 3;

  while (countdown > 0) {
    currentMillis = millis();
    if (currentMillis - previousMillis >= intervalSecond) {
      previousMillis = currentMillis;

      if (countdown < 100) {
        countdownChar[0] = (countdown / 10) + '0'; //desmiti
        countdownChar[1] = (countdown % 10) + '0'; //vieni
      }
      else if (countdown < 10) {
        countdownChar[0] = 0x20; //desmiti
        countdownChar[1] = (countdown % 10) + '0'; //vieni
      }

      ssd1306_fillScreen(0x00);
      ssd1306_printFixedN (50, 16, countdownChar, STYLE_NORMAL, FONT_SIZE_2X);

      countdown--;

    }
  }
  EEPROM[0] = 0x00;
  enterCodeScreen();
}
