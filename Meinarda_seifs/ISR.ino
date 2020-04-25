
//=======================[ISR]======================
/*
ISR(PCINT1_vect) {
  cli();
  delay(20);
  ssd1306_fillScreen(0x00);
  ssd1306_printFixedN (32, 16, "poga", STYLE_NORMAL, FONT_SIZE_2X);
  ssd1306_printFixedN (16, 32, "nospiesta!", STYLE_NORMAL, FONT_SIZE_2X);
  delay(2000);
  advance = true;
  sei();
}
*/
