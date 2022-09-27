#include "BombFSM.h"

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 5;  //5 rows
const byte COLS = 4;  //4 columns
const byte tempoDelay = 40;


char pin[] = { 0, 0, 0, 0, 0, 0 };

char specialKeysID[] = {
  'A', 'B', '#', '*',
  '1', '2', '3', 'C',
  '4', '5', '6', 'D',
  '7', '8', '9', 'E',
  'F', '0', 'G', 'H'
};

// H = ENTER

char keys[ROWS][COLS] = {
  { specialKeysID[0], specialKeysID[1], specialKeysID[2], specialKeysID[3] },
  { specialKeysID[4], specialKeysID[5], specialKeysID[6], specialKeysID[7] },
  { specialKeysID[8], specialKeysID[9], specialKeysID[10], specialKeysID[11] },
  { specialKeysID[12], specialKeysID[13], specialKeysID[14], specialKeysID[15] },
  { specialKeysID[16], specialKeysID[17], specialKeysID[18], specialKeysID[19] }
};

byte rowPins[ROWS] = { 2, 3, 4, 5, 6 };  //connect to the row pinouts of the kpd
byte colPins[COLS] = { 10, 9, 8, 7 };    //connect to the column pinouts of the kpd

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);

BombFSM bombFSM(&lcd, &keypad);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.println("Setup Done");
  bombFSM.Initialize();
}

void loop() {
  bombFSM.OnLoop();
  delay(tempoDelay);
/*
    switch (statoBomba) {

      case SETTIME:
        {
          update_settime_display();
          if (key) {
            if (isDigit(key)) {
              int keyInt = key - '0';
              if (keyInt <= timeBombDigitLimit[timeBombIndex]) {
                if (timeBombIndex == 0 && keyInt == 2) {
                  timeBombDigitLimit[1] = 3;
                }
                timeBombString[timeBombIndex] = key;
                timeBombIndex++;
                if (timeBombIndex >= 4) {

                  changeState(SETUPSTART);
                }
              }
            }
          }
          delay(tempoDelay);

          break;
        }
      case SETUPSTART:
        {

          changeState(PRESSSTART);
          delay(tempoDelay);
          break;
        }
      case PRESSSTART:
        {

          if (key)
            if (key == 'H')
              changeState(INFUNZIONE);
          delay(tempoDelay);

          break;
        }
    }
    */
}
