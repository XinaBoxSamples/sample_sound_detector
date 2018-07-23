void setup_program(void) {
  // Set the I2C Pins for CW01
#if defined(ESP8266)
  WiFi.forceSleepBegin();
  Wire.begin(2, 14);
  Wire.setClockStretchLimit(15000);

#elif defined(ARDUINO_SAMD_ZERO)
  Wire.begin();

#elif defined(ARDUINO_AVR_PRO)
  Wire.begin();

#elif defined(ESP32)
  Wire.begin();

#endif

  // start sensor

  // start oled
  OLED.begin();
  Serial.begin(115200);

  // clear oled
  OD01.clear();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Accl);
  // Select PMU_Range register
  Wire.write(0x0F);
  // Range = +/- 2g
  Wire.write(0x03);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Accl);
  // Select PMU_BW register
  Wire.write(0x10);
  // Bandwidth = 7.81 Hz
  Wire.write(0x08);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Accl);
  // Select PMU_LPW register
  Wire.write(0x11);
  // Normal mode, Sleep duration = 0.5ms
  Wire.write(0x00);
  // Stop I2C Transmission on the device
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Gyro);
  // Select Range register
  Wire.write(0x0F);
  // Full scale = +/- 125 degree/s
  Wire.write(0x04);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Gyro);
  // Select Bandwidth register
  Wire.write(0x10);
  // ODR = 100 Hz
  Wire.write(0x07);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Gyro);
  // Select LPM1 register
  Wire.write(0x11);
  // Normal mode, Sleep duration = 2ms
  Wire.write(0x00);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Mag);
  // Select Mag register
  Wire.write(0x4B);
  // Soft reset
  Wire.write(0x83);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Mag);
  // Select Mag register
  Wire.write(0x4C);
  // Normal Mode, ODR = 10 Hz
  Wire.write(0x00);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Mag);
  // Select Mag register
  Wire.write(0x4E);
  // X, Y, Z-Axis enabled
  Wire.write(0x84);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Mag);
  // Select Mag register
  Wire.write(0x51);
  // No. of Repetitions for X-Y Axis = 9
  Wire.write(0x04);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr_Mag);
  // Select Mag register
  Wire.write(0x52);
  // No. of Repetitions for Z-Axis = 15
  Wire.write(0x0F);
  // Stop I2C Transmission
  Wire.endTransmission();
  delay(300);


// set output leds
pinMode(CW01_RED, OUTPUT);
pinMode(CW01_GREEN, OUTPUT);
pinMode(CW01_BLUE, OUTPUT);

// turn rgb on
digitalWrite(CW01_RED, HIGH);
digitalWrite(CW01_GREEN, HIGH);
digitalWrite(CW01_BLUE, HIGH);

delay(2000);

// turn rgb off
digitalWrite(CW01_RED, LOW);
digitalWrite(CW01_GREEN, LOW);
digitalWrite(CW01_BLUE, LOW);

delay(1000);
t.tick_main = millis();
t.tick_poll = millis();
}

