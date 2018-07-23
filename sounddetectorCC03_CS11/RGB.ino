void red_fade(const long interval, int LED, int limit, int increment) {
  currentMilli = millis();
  if (currentMilli - previousMilli1 >= interval) {
    previousMilli1 = currentMilli;
    if (fade_flag1 == true) {
      LED_state1 += increment;
      if (LED_state1 == limit) {
        fade_flag1 = false;
      }
    }
    if (fade_flag1 == false) {
      LED_state1 -= increment;
      if (LED_state1 == 0) {
        fade_flag1 = true;
        ledID++;
      }
    }
  }
  analogWrite(LED, LED_state1);
}
void blue_fade(const long interval, int LED, int limit, int increment) {
  currentMilli = millis();
  if (currentMilli - previousMilli2 >= interval) {
    previousMilli2 = currentMilli;
    if (fade_flag2 == true) {
      LED_state2 += increment;
      if (LED_state2 == limit) {
        fade_flag2 = false;
      }
    }
    if (fade_flag2 == false) {
      LED_state2 -= increment;
      if (LED_state2 == 0) {
        fade_flag2 = true;
        ledID = 0;
      }
    }
  }
  analogWrite(LED, LED_state2);
}
void green_fade(const long interval, int LED, int limit, int increment) {
  currentMilli = millis();
  if (currentMilli - previousMilli3 >= interval) {
    previousMilli3 = currentMilli;
    if (fade_flag3 == true) {
      LED_state3 += increment;
      if (LED_state3 == limit) {
        fade_flag3 = false;
      }
    }
    if (fade_flag3 == false) {
      LED_state3 -= increment;
      if (LED_state3 == 0) {
        fade_flag3 = true;
        ledID++;
      }
    }
  }
  analogWrite(LED, LED_state3);
}
