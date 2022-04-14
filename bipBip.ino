void bipBip() {
  static bool periodFlag;
  static bool timerFlag;
  static bool speedFlag;
  static byte dir = 5;
  static byte duty = 0;
  byte crt;

  if (buttonDingle.press()) {
    buttonDingleFlag = true;
    periodFlag = true;
    timerFlag = true;
    speedFlag = true;
    periodDingle.start();
    timerDingle.start();
    speedFade.start();
  }
  if (periodDingle.tick()) {
    periodFlag = !periodFlag;
  }
  if (speedFade.tick()) {
    speedFlag = true;
  } else {
    speedFlag = false;
  }
  if (timerDingle.tick()) {
    timerFlag = false;
    periodDingle.stop();
    speedFade.stop();
  }
  if (buttonDingle.release()) {
    buttonDingleFlag = false;
    periodDingle.stop();
    timerDingle.stop();
    speedFade.stop();
  }
  if (buttonDingleFlag && timerFlag) {
    if (periodFlag) {
      analogWrite(DINGLE_PIN, 10);
      if (speedFlag && duty <= 255) {
        crt = ((long)duty * duty * duty + 130305) >> 16;
        analogWrite(LED1_PIN, crt);
        analogWrite(LED2_PIN, crt);
        duty += dir;
      }
    } else {
      analogWrite(DINGLE_PIN, 0);
      if (speedFlag && duty >= 0) {
        crt = ((long)duty * duty * duty + 130305) >> 16;
        analogWrite(LED1_PIN, crt);
        analogWrite(LED2_PIN, crt);
        duty -= dir;
      }
    }
  } else {
    analogWrite(DINGLE_PIN, 0);
    analogWrite(LED1_PIN, 0);
    analogWrite(LED2_PIN, 0);
    duty = 0;
  }
}
