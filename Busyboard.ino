#define BUTTON_DINGLE_PIN 3
#define DINGLE_PIN 11
#define BUTTON_STRIP_PIN 4
#define STRIP_PIN 7
#define NUMLEDS 20
#define BUTTON_LIGHT_PIN 5
#define LIGHT_PIN 8
#define LED1_PIN 9
#define LED2_PIN 10


#include <TimerMs.h>
// (период, мс), (0 не запущен / 1 запущен), (режим: 0 период / 1 таймер)
TimerMs periodDingle(500, 0, 0);
TimerMs timerDingle(5000, 0, 1);
TimerMs speedStrip(200, 0, 0);
TimerMs timerStrip(60000, 0, 1);
TimerMs timerLight(10000, 0, 1);
TimerMs speedFade(11, 0, 0);

#include <EncButton.h>
EncButton<EB_TICK, BUTTON_DINGLE_PIN> buttonDingle;
EncButton<EB_TICK, BUTTON_STRIP_PIN> buttonStrip;
EncButton<EB_TICK, BUTTON_LIGHT_PIN> buttonLight;

#include <microLED.h>
microLED<NUMLEDS, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_LOW> strip;

bool buttonDingleFlag;
bool buttonStripFlag;
bool buttonLightFlag;

void setup() {
  pinMode(BUTTON_DINGLE_PIN, INPUT_PULLUP);
  pinMode(DINGLE_PIN, OUTPUT);
  pinMode(BUTTON_STRIP_PIN, INPUT_PULLUP);
  pinMode(BUTTON_LIGHT_PIN, INPUT_PULLUP);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  strip.setMaxCurrent(100);
  strip.setBrightness(50);
}

void loop() {
  buttonDingle.tick();
  buttonStrip.tick();
  buttonLight.tick();

  bipBip();
  runningRainbowDots();
  light();
  starWars();
}
