void TaskScheduler(void) {

  if (ledID == 0) {
    red_fade(30, CW01_RED, 255, 5);
  } else if (ledID == 1) {
    green_fade(30, CW01_GREEN, 255, 5);
  } else if (ledID == 2) {
    blue_fade(30, CW01_BLUE, 255, 5);
  }

  if ((millis() - t.tick_main) > 1) {
    main_code();
    t.tick_main = millis();
  }

  if ((millis() - t.tick_poll) > 1000) {
    // poll sensor

    OD01.clear();
    if (!Print) {
      OD01.set2X();
      OD01.println("ATTENTION!");
      OD01.set1X();
      OD01.println("Please ");
      OD01.println("Make some noise");
      //    digitalWrite(CW01_BLUE, HIGH);
      //    digitalWrite(CW01_RED, LOW);
      //    digitalWrite(CW01_GREEN, LOW);
    }

    else {
      digitalWrite(CW01_GREEN, HIGH);
      digitalWrite(CW01_BLUE, LOW);
      digitalWrite(CW01_RED, LOW);
      OD01.clear();
      OD01.set2X();
      OD01.println("  ");
      OD01.println("  Y");
      OD01.println("    E");
      OD01.print("      S?");
      Print = false;
    }
    t.tick_poll = millis();
  }

}
