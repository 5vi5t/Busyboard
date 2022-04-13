void light() {
  static bool buttonFlag;
  static bool timerFlag;

  if (buttonLight.press()) {
    buttonFlag = true;
    timerFlag = true;
    timerLight.start();
  }
  if (timerLight.tick()) {
    timerFlag = false;
  }
  if (buttonLight.release()) {
    buttonFlag = false;
    timerLight.stop();
  }
  if (buttonFlag && timerFlag) {
    digitalWrite(LIGHT_PIN, 1);
  } else {
    digitalWrite(LIGHT_PIN, 0);
  }
}
