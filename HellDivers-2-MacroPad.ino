
#include "Keyboard.h"

const uint8_t NUM_BUTTONS = 7;
const uint8_t BUTTON_PINS[NUM_BUTTONS] PROGMEM = {2, 3, 4, 5, 6, 7, 8};
#define K_UP 0x1A
#define K_DOWN 0x19
#define K_LEFT 0x18
#define K_RIGHT 0x17
#define K_LAST 0x80

constexpr uint16_t DEBOUNCE_DELAY = 50;
constexpr uint16_t KEY_PRESS_DELAY = 100;
constexpr uint16_t KEY_RELEASE_DELAY = 50;

const uint8_t KEY_SEQUENCES[] PROGMEM = {
  K_UP, K_DOWN, K_RIGHT, K_LEFT, K_UP | K_LAST,
  K_DOWN, K_DOWN, K_UP, K_RIGHT | K_LAST,
  K_DOWN, K_UP, K_LEFT, K_RIGHT, K_LEFT, K_RIGHT | K_LAST,
  K_UP, K_RIGHT, K_DOWN, K_RIGHT | K_LAST,
  K_RIGHT, K_UP, K_DOWN, K_DOWN, K_RIGHT | K_LAST,
  K_DOWN, K_LEFT, K_RIGHT, K_UP, K_DOWN | K_LAST,
  K_UP, K_UP, K_LEFT, K_UP, K_RIGHT | K_LAST
};

void setup() {
  for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
    pinMode(pgm_read_byte(&BUTTON_PINS[i]), INPUT_PULLUP);
  }
  Keyboard.begin();
  UCSR1B = 0; // Disable serial communication
}

__attribute__((optimize("Os")))
void loop() {
  static uint8_t lastStates = 0xFF; // Initialize to HIGH
  static uint32_t lastPress = 0;
  uint32_t now = millis();
  uint8_t currentStates = 0;
  for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(pgm_read_byte(&BUTTON_PINS[i])) == LOW) {
      currentStates |= (1 << i);
    }
  }
  uint8_t pressed = currentStates & ~lastStates;
  if (pressed && (now - lastPress > DEBOUNCE_DELAY)) {
    for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
      if (pressed & (1 << i)) {
        executeKeySequence(i);
        lastPress = now;
        break;
      }
    }
  }
  lastStates = currentStates;
}

__attribute__((optimize("Os")))
void executeKeySequence(uint8_t index) {
  const uint8_t* seq = KEY_SEQUENCES;
  if (index >= NUM_BUTTONS) {
    return;
  }
  // Skip to selected key seq
  while (index--) {
    while (!(pgm_read_byte(seq++) & K_LAST));
  }
  uint8_t key;
  while ((key = pgm_read_byte(seq++))) {
    if ((key & 0x7F) >= 0x00 && (key & 0x7F) <= 0x7F) {
      Keyboard.press(0xC0 + (key & 0x7F)); // key map
      delay(KEY_PRESS_DELAY);
      Keyboard.releaseAll();
      delay(KEY_RELEASE_DELAY);
    }
    if (key & K_LAST) break;
  }
}
