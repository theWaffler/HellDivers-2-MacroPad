/*bool
Welcome, Hell Diver! I see you're looking for every advantage in spreading managed Democracy! 
Below, you'll find code to help assign macro buttons to help call for reinforcements and other stratagems. 
Remember, if this is illegal, Super Earth may not look kindly upon you.  
The watchdog doesn't seem to mind, but that can all change. Take caution using this!
I am in no way responsible if you get caught and imprisoned.

All Stratagems button inputs can be found here.
https://gamerant.com/helldivers-2-all-stratagams-button-inputs/
*/

#include "Keyboard.h"

// Pin definitions
#define BUTTON_PIN1 2
#define BUTTON_PIN2 3
#define BUTTON_PIN3 4
#define BUTTON_PIN4 5
#define BUTTON_PIN5 6
#define BUTTON_PIN6 7
#define BUTTON_PIN7 8
#define BUTTON_PIN8 9

// Define the button class to handle button states and debouncing
class button {
public:
  const uint8_t pin; // pin number associated with the button (0-255 bc memory)
  bool lastState = HIGH; // last read state of the button
  bool currentState = HIGH; // current debounced state of the button
  unsigned long lastDebounceTime = 0; // last time the button state was changed
  const uint8_t debounceTime = 50; // prevents flickering (ms)
  bool executeFlag = false; // indicates if a key sequence should be executed

  // constructor initializes the button with its associated pin
  button(uint8_t p) {
      pin = p;
      lastState = HIGH;
      currentState = HIGH;
      lastDebounceTime = 0;
      executeFlag = false;
  }

  // update button state and set the execute flag if pressed
  void update() {
    bool reading = !digitalRead(pin); // Read the current state of the button
    // Check if the button state has changed
    if (reading != lastState) {
      lastDebounceTime = millis(); // Reset the debouncing timer
    }
    if ((millis() - lastDebounceTime) > debounceTime) {
      // If the state is stable for longer than the debounce time, update the current state
      if (reading != currentState) {
        currentState = reading;
        // If the button is pressed (state is LOW), set the execute flag
        if (currentState == LOW) {
          executeFlag = true;
        }
      }
    }
    lastState = reading; // Update the lastState for the next loop
  }
  // Method to reset the execute flag after a key sequence is executed
  void resetExecuteFlag() {
    executeFlag = false;
  }
};
// Macro pad 4 x 2 (column x rows)
// Key sequence starts at 0
// 1, 2, 3, 4
// 5, 6, 7, 8
// Reinforce
// up, down, right, left, up
void executeKeySequence0() {
  // pull up strat menu
  Keyboard.press(KEY_PAGE_DOWN);
  delay(100);
  Keyboard.release(KEY_PAGE_DOWN);
  delay(50);

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.release(KEY_UP_ARROW);
  delay(50);

  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);

  Keyboard.press(KEY_LEFT_ARROW);
  delay(50);
  Keyboard.release(KEY_LEFT_ARROW);
  delay(50);

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.release(KEY_UP_ARROW);
  delay(50);
}

// Resupply
// down, down, up, right
void executeKeySequence1() {
  Keyboard.press(KEY_PAGE_DOWN);
  delay(100);
  Keyboard.release(KEY_PAGE_DOWN);
  delay(50);
  
  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50);

  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50);

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.release(KEY_UP_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);
}

// Shield Generator
// down, up, left, right, left, right
void executeKeySequence2(){
  // pull up strat menu
  Keyboard.press(KEY_PAGE_DOWN);
  delay(100);
  Keyboard.release(KEY_PAGE_DOWN);
  delay(50);

  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50);

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.release(KEY_UP_ARROW);
  delay(50);

  Keyboard.press(KEY_LEFT_ARROW);
  delay(100);
  Keyboard.release(KEY_LEFT_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);

  Keyboard.press(KEY_LEFT_ARROW);
  delay(100);
  Keyboard.release(KEY_LEFT_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);
}

// Rail gun
// down, right, down, up, left, right
void executeKeySequence3(){
  // pull up strat menu
  Keyboard.press(KEY_PAGE_DOWN);
  delay(100);
  Keyboard.release(KEY_PAGE_DOWN);
  delay(50);

  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(25);

  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50);

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.release(KEY_UP_ARROW);
  delay(50);

  Keyboard.press(KEY_LEFT_ARROW);
  delay(100);
  Keyboard.release(KEY_LEFT_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);
}

// Eagle Airstrike
// up, right, down, RIGHT
void executeKeySequence4() {
  // pull up strat menu
  Keyboard.press(KEY_PAGE_DOWN);
  delay(100);
  Keyboard.release(KEY_PAGE_DOWN);
  delay(50);

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.release(KEY_UP_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);

  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);
}

// Oribtal Railgun
// right, up, down, down, right
void executeKeySequence5(){
  // pull up strat menu
  Keyboard.press(KEY_PAGE_DOWN);
  delay(50);
  Keyboard.release(KEY_PAGE_DOWN);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(50);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);

  Keyboard.press(KEY_UP_ARROW);
  delay(50);
  Keyboard.release(KEY_UP_ARROW);
  delay(50);

  Keyboard.press(KEY_DOWN_ARROW);
  delay(50);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50);

  Keyboard.press(KEY_DOWN_ARROW);
  delay(50);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(50);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);
}

// Anti materiel rifle
// down, left, right, up, down
void executeKeySequence6(){
  // pull up strat menu
  Keyboard.press(KEY_PAGE_DOWN);
  delay(100);
  Keyboard.release(KEY_PAGE_DOWN);
  delay(50);

  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50);

  Keyboard.press(KEY_LEFT_ARROW);
  delay(100);
  Keyboard.release(KEY_LEFT_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.release(KEY_UP_ARROW);
  delay(50);

  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(50); 
}

// Eagle Rearm
// up, up, left, up, right
void executeKeySequence7(){
  // pull up strat menu
  Keyboard.press(KEY_PAGE_DOWN);
  delay(100);
  Keyboard.release(KEY_PAGE_DOWN);
  delay(50);

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.release(KEY_UP_ARROW);
  delay(50);

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.release(KEY_UP_ARROW);
  delay(50); 

  Keyboard.press(KEY_LEFT_ARROW);
  delay(100);
  Keyboard.release(KEY_LEFT_ARROW);
  delay(50); 

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.release(KEY_UP_ARROW);
  delay(50);

  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
  delay(50);
}

button buttons[] = {
  button(BUTTON_PIN1),
  button(BUTTON_PIN2),
  button(BUTTON_PIN3),
  button(BUTTON_PIN4),
  button(BUTTON_PIN5),
  button(BUTTON_PIN6),
  button(BUTTON_PIN7),
  button(BUTTON_PIN8),
};

void setup() {
  Keyboard.begin(); // Initialize keyboard control
  // Set each button pin as input with pull-up resistor
  for (int i = 0; i < sizeof(buttons) / sizeof(button); ++i) {
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < sizeof(buttons) / sizeof(button); i++) {
    buttons[i].update();
    if (buttons[i].executeFlag) {
      switch(buttons[i].pin){
        case BUTTON_PIN1: executeKeySequence0(); break;
        case BUTTON_PIN2: executeKeySequence1(); break;
        case BUTTON_PIN3: executeKeySequence2(); break;
        case BUTTON_PIN4: executeKeySequence3(); break;
        case BUTTON_PIN5: executeKeySequence4(); break;
        case BUTTON_PIN6: executeKeySequence5(); break;
        case BUTTON_PIN7: executeKeySequence6(); break;
        case BUTTON_PIN8: executeKeySequence7(); break; 
      }
      buttons[i].resetExecuteFlag();
    }
  }
}
