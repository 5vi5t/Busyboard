void starWars() {
  static bool startFlag;

  if (buttonLightFlag && buttonStripFlag && buttonDingle.hasClicks(9)) {
    startFlag = true;
  }

  if (startFlag) {
    buttonLightFlag = false;
    static int notes[39] = {
      392, 392, 392, 311, 466, 392, 311, 466, 392,
      587, 587, 587, 622, 466, 369, 311, 466, 392,
      784, 392, 392, 784, 739, 698, 659, 622, 659,
      415, 554, 523, 493, 466, 440, 466,
      311, 369, 311, 466, 392
    };

    static int times[39] = {
      350, 350, 350, 250, 100, 350, 250, 100, 700,
      350, 350, 350, 250, 100, 350, 250, 100, 700,
      350, 250, 100, 350, 250, 100, 100, 100, 450,
      150, 350, 250, 100, 100, 100, 450,
      150, 350, 250, 100, 750
    };

    static int index = 0;

    tone(DINGLE_PIN, notes[index], times[index] * 2);
    digitalWrite(LED1_PIN, 1);
    digitalWrite(LED2_PIN, 1);
    delay(times[index]);
    noTone(DINGLE_PIN);
    digitalWrite(LED1_PIN, 0);
    digitalWrite(LED2_PIN, 0);
    delay(times[index]);
    index++;
    if (index >= 39) {
      index = 0;
      noTone(DINGLE_PIN);
      digitalWrite(LED1_PIN, 0);
      digitalWrite(LED2_PIN, 0);
      delay(2000);
      startFlag = false;
    }
  }
}
