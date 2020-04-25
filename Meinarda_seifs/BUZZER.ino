
//===========================[BEEP]============================

void beep(unsigned int onTime, unsigned int offTime, unsigned int noteCount) {
  for (unsigned int i = 0; i <= noteCount; i++) {
    PORTA |= (1 << PA3);
    NOPdelay(onTime * 160000);
    PORTA &= !(1 << PA3);
    NOPdelay(offTime * 160000);
  }
}

//===========================[DONE_MUSIC]============================
void doneMusic() {
  beep(2, 1, 8);
}
//===========================[START_MUSIC]===========================
void startMusic() {
  beep(3, 2, 3);
}
//===========================[STOP_MUSIC]============================
void stopMusic() {
  beep(2, 2, 3);
}
//===========================[SPLASH_MUSIC]==========================
void splashMusic() {
  beep(2, 1, 5);
}
