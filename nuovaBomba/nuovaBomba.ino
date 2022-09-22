#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 5;  //5 rows
const byte COLS = 4;  //4 columns
const byte tempoDelay = 40;


char pin[] = { 0, 0, 0, 0, 0, 0 };
byte pinIndex = 0;
int pinTime = 0;
bool pinUnderscore = false;
char timeBombString[] = { 'h', 'h', 'm', 'm' };
int timeBombDigitLimit[] = { 2, 9, 6, 9 };
byte timeBombIndex = 0;


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
unsigned long currentTime = 0;
unsigned long oldTime = 0;


enum stati {
  PIN,
  SETTIME,
  SETUPSTART,
  PRESSSTART,
  INFUNZIONE,
  BOOM,
  DEFUSE
};

stati statoBomba = PIN;


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  currentTime = millis();
  int deltaTime = currentTime - oldTime;
  char key = keypad.getKey();
  switch (statoBomba) {

    case PIN:
      {
        pinTime += deltaTime;
        if (pinTime > 1000) {
          pinTime = 0;
          pinUnderscore = !pinUnderscore;
          update_pin_display(pinUnderscore);
        }
        if (key) {
          if (isDigit(key)) {
            if (pinIndex < sizeof(pin) / sizeof(pin[0])) {
              pin[pinIndex] = key;
              pinIndex++;
              update_pin_display(pinUnderscore);

              if (pinIndex >= sizeof(pin) / sizeof(pin[0]))
                changeState(SETTIME);
            }
          } else if (key == 'H' && pinIndex >= 4)
            changeState(SETTIME);
        }
        delay(tempoDelay);
        break;
      }
    case SETTIME:
      {
        update_settime_display();
        if (key) {
          if (isDigit(key)) {
            int keyInt = key - '0';
            if (keyInt <= timeBombDigitLimit[timeBombIndex]) {
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
        lcd.setCursor(2, 0);
        lcd.print("Premi Enter");
        lcd.setCursor(0, 1);
        lcd.print("Per avviare");
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

    case INFUNZIONE:
      {
        delay(tempoDelay);
        break;
      }
    case BOOM:
      {
        delay(tempoDelay);
        break;
      }
    case DEFUSE:
      {
        delay(tempoDelay);
        break;
      }
  }
  oldTime = currentTime;
}

void update_pin_display(bool underscore) {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Inserire PIN");
  String pinString = "";
  for (int i = 0; i < sizeof(pin) / sizeof(pin[0]); i++) {
    if (!pin[i])
      break;
    pinString += pin[i];
  }
  if (underscore && pinIndex < (sizeof(pin) / sizeof(pin[0])) - 1)
    pinString += '_';
  lcd.setCursor(5, 1);
  lcd.print(pinString);
}

void update_settime_display() {
  lcd.setCursor(1, 0);
  lcd.print("Inserire Tempo");
  String timeString = "";
  timeString += timeBombString[0];
  timeString += timeBombString[1];
  timeString += ':';
  timeString += timeBombString[2];
  timeString += timeBombString[3];
  lcd.setCursor(6, 1);
  Serial.println(timeString);
  lcd.print(timeString);
}

void changeState(stati nuovoStato) {
  lcd.clear();
  statoBomba = nuovoStato;
}