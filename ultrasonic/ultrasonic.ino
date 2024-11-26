#include <NewPing.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define TRIG_PIN 33
#define ECHO_PIN 32
#define MAX_DISTANCE 200 //Maximum distance to measure(cms)
// Create a NewPing object
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
// Change 0x27 to your LCD I2C address if different
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Ultrasonic Sensor");
  lcd.print("By Bharath Pi");
}
void loop() {
  delay(100);
  unsigned int distance = sonar.ping_cm();
// Display the distance on the LCD
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm ");
}