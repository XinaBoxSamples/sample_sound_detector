void main_code(void) {

  unsigned int data[6];

  for (int i = 0; i < 6; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr_Accl);
    // Select data register
    Wire.write((2 + i));
    // Stop I2C Transmission
    Wire.endTransmission();

    // Request 1 byte of data
    Wire.requestFrom(Addr_Accl, 1);

    // Read 6 bytes of data
    // xAccl lsb, xAccl msb, yAccl lsb, yAccl msb, zAccl lsb, zAccl msb
    if (Wire.available() == 1)
    {
      data[i] = Wire.read();
    }
  }

  // Convert the data to 12-bits
  int xAccl = ((data[1] * 256) + (data[0] & 0xF0)) / 16;
  if (xAccl > 2047)
  {
    xAccl -= 4096;
  }
  int yAccl = ((data[3] * 256) + (data[2] & 0xF0)) / 16;
  if (yAccl > 2047)
  {
    yAccl -= 4096;
  }
  int zAccl = ((data[5] * 256) + (data[4] & 0xF0)) / 16;
  if (zAccl > 2047)
  {
    zAccl -= 4096;
  }

  for (int i = 0; i < 6; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr_Gyro);
    // Select data register
    Wire.write((2 + i));
    // Stop I2C Transmission
    Wire.endTransmission();

    // Request 1 byte of data
    Wire.requestFrom(Addr_Gyro, 1);

    // Read 6 bytes of data
    // xGyro lsb, xGyro msb, yGyro lsb, yGyro msb, zGyro lsb, zGyro msb
    if (Wire.available() == 1)
    {
      data[i] = Wire.read();
    }
  }

  // Convert the data
  int xGyro = (data[1] * 256) + data[0];
  if (xGyro > 32767)
  {
    xGyro -= 65536;
  }
  int yGyro = (data[3] * 256) + data[2];
  if (yGyro > 32767)
  {
    yGyro -= 65536;
  }
  int zGyro = (data[5] * 256) + data[4];
  if (zGyro > 32767)
  {
    zGyro -= 65536;
  }

  for (int i = 0; i < 6; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr_Mag);
    // Select data register
    Wire.write((66 + i));
    // Stop I2C Transmission
    Wire.endTransmission();

    // Request 1 byte of data
    Wire.requestFrom(Addr_Mag, 1);

    // Read 6 bytes of data
    // xMag lsb, xMag msb, yMag lsb, yMag msb, zMag lsb, zMag msb
    if (Wire.available() == 1)
    {
      data[i] = Wire.read();
    }
  }

  // Convert the data
  int xMag = ((data[1] * 256) + (data[0] & 0xF8)) / 8;
  if (xMag > 4095)
  {
    xMag -= 8192;
  }
  int yMag = ((data[3] * 256) + (data[2] & 0xF8)) / 8;
  if (yMag > 4095)
  {
    yMag -= 8192;
  }
  int zMag = ((data[5] * 256) + (data[4] & 0xFE)) / 2;
  if (zMag > 16383)
  {
    zMag -= 32768;
  }

  // Output data to serial monitor

  //  OD01.print(xAccl);
  //  OD01.print("  ");
  //  OD01.print(yAccl);
  //  OD01.print("  ");
  //  OD01.println(zAccl);
  //
  //  OD01.print(xGyro);
  //  OD01.print("  ");
  //  OD01.print(yGyro);
  //  OD01.print("  ");
  //  OD01.println(zGyro);

  double max_g = 6000;

  float magnitude = 0;





    magnitude = pow(xGyro, 2) + pow(yGyro, 2) + pow(zGyro, 2);
    Serial.println(magnitude);
    delay(500);
    if (magnitude > max_g) {
      Print = true;
    }
}



