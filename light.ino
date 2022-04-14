void light() {
  static bool timerFlag;

  if (buttonLight.press()) {
    buttonLightFlag = true;
    timerFlag = true;
    timerLight.start();
  }
  if (timerLight.tick()) {
    timerFlag = false;
  }
  if (buttonLight.release()) {
    buttonLightFlag = false;
    timerLight.stop();
  }
  if (buttonLightFlag && timerFlag) {
    digitalWrite(LIGHT_PIN, 1);
  } else {
    digitalWrite(LIGHT_PIN, 0);
  }
}
