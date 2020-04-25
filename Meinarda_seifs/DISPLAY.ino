
//===========================[DISPLAY_SETUP]============================

void displaySetup() {
  ssd1306_128x64_i2c_init();
  ssd1306_fillScreen(0x00);
  ssd1306_setFixedFont(ssd1306xled_font6x8);

}

//===============================[DONE]===============================
void openingDoor() {
  ssd1306_fillScreen(0x00);
  ssd1306_printFixedN (30, 30, "DURVIS", STYLE_NORMAL, FONT_SIZE_2X);
  ssd1306_printFixedN (20, 46, "ATVERAS!", STYLE_NORMAL, FONT_SIZE_2X);
  delay(1000);
  PORTA &= ~(1 << PA0); // CLOSES DOOR
  
  ssd1306_fillScreen(0x00);
  ssd1306_printFixedN (30, 30, "PALDIES!", STYLE_NORMAL, FONT_SIZE_2X);


  while (digitalRead(1) != LOW) {
  }

  ssd1306_fillScreen(0x00);
  splashScreen();

}
//===============================[DONE]===============================
void wrongCode() {
  ssd1306_fillScreen(0x00);
  ssd1306_printFixedN (10, 30, "NEPAREIZS", STYLE_NORMAL, FONT_SIZE_2X);
  ssd1306_printFixedN (40, 46,   "KODS!", STYLE_NORMAL, FONT_SIZE_2X);
  delay(2000);
  ssd1306_fillScreen(0x00);

}


//=======================[ENDTER CODE SCREEN]==========================
void enterCodeScreen() {

  ssd1306_fillScreen(0x00);
  ssd1306_printFixedN (26, 16, "IEVADI", STYLE_NORMAL, FONT_SIZE_2X);
  ssd1306_printFixedN (32, 32, "KODU!", STYLE_NORMAL, FONT_SIZE_2X);
  delay(2000);
  ssd1306_fillScreen(0x00);
  enterCode();
}

//=======================[SPLASH_SCREEN]==========================
void splashScreen() {
  ssd1306_fillScreen(0x00);
  ssd1306_printFixedN (32, 16, "TEST", STYLE_NORMAL, FONT_SIZE_2X);
  ssd1306_printFixedN (26, 32, "SEIFS", STYLE_NORMAL, FONT_SIZE_2X);
  delay(1000);
  ssd1306_fillScreen(0x00);
  enterCodeScreen();
}
