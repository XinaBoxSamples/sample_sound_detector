#include <xCore.h> //find @ https://github.com/xinabox/xCore
#include <xOD01.h> //find @ https://github.com/xinabox/xOD01
#include <ESP8266WiFi.h>
#include "TIMER_CTRL.h"
#include <Wire.h>


// BMX055 Accl I2C address is 0x18(24)
#define Addr_Accl 0x18
// BMX055 Gyro I2C address is 0x68(104)
#define Addr_Gyro 0x68
// BMX055 Mag I2C address is 0x10(16)
#define Addr_Mag 0x10

unsigned long currentMilli = 0;
int ledID = 0;

bool instruct_flag = false;
bool intro_flag = true;

boolean Print = false;


bool fade_flag1 = true;
unsigned long previousMilli1 = 0;    // timing variable for LEDS
int LED_state1 = 0;
bool fade_flag2 = true;
unsigned long previousMilli2 = 0;    // timing variable for LEDS
int LED_state2 = 0;
bool fade_flag3 = true;
unsigned long previousMilli3 = 0;    // timing variable for LEDS
int LED_state3 = 0;


void setup() {
  // put your setup code here, to run once:
  setup_program();
}

void loop() {
  // put your main code here, to run repeatedly:
  main_program();
}
