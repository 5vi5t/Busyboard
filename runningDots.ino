void runningDots() {
  static byte ledCounter = 0;
  static byte colorCounter = 0;
  static bool periodFlag;
  static bool timerFlag;

  if (buttonStrip.press()) {
    buttonStripFlag = true;
    periodFlag = true;
    timerFlag = true;
    speedStrip.start();
    timerStrip.start();
  }
  if (timerStrip.tick()) {
    buttonStripFlag = false;
    periodFlag = false;
    timerFlag = false;
    speedStrip.stop();
  }
  if (speedStrip.tick()) {
    periodFlag = true;
  } else {
    periodFlag = false;
  }
  if (buttonStrip.release()) {
    buttonStripFlag = false;
    periodFlag = false;
    timerFlag = false;
    speedStrip.stop();
    timerStrip.stop();
  }
  if (buttonStripFlag && timerFlag) {
    if (periodFlag) {
      for (int i = 0; i < NUMLEDS - 1; i++) {
        strip.leds[i] = strip.leds[i + 1];
      }
      if (ledCounter % 3 == 0) {
        strip.leds[NUMLEDS - 1] = mWheel8(colorCounter);
      } else {
        strip.leds[NUMLEDS - 1] = mBlack;
      }
      ledCounter++;
      colorCounter += 3;
      strip.show();
    }
  } else {
    strip.clear();
    strip.show();
  }
}
