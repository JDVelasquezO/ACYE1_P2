#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);
const byte rows = 4;
const byte cols = 3;

char keys[rows][cols] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'#', '0', '*'},
};

byte rowPin[rows] = {10, 9, 8, 7};
byte colsPin[cols] = {13, 12, 11};

Keypad key = Keypad(makeKeymap(keys), rowPin, colsPin, rows, cols);

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hola");
}

void loop() {
  // put your main code here, to run repeatedly:
  /*Wire.beginTransmission(23); // Direccion del arduino
  Wire.write('a');
  Wire.endTransmission();
  delay(1000);*/

  char reads = key.getKey();
  if (reads) {
    Serial.println(reads);
  }
}
