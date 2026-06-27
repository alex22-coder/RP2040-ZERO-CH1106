#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>

#define SDA_PIN 4
#define SCL_PIN 5

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);
  // Wire.setPins(SDA_PIN, SCL_PIN);
  Wire.begin();
  Wire.setClock(400000);
  u8g2.begin();
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 15, "Hello RP2040-Zero!");
  u8g2.drawStr(0, 35, "   I2C pins 4/5");
  u8g2.drawStr(0, 55, "Device Address 0x3C");
  u8g2.sendBuffer();
  
  Serial.println("Display initialized");
}

void loop() {}