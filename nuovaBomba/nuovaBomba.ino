#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 5; //5 rows
const byte COLS = 4; //4 columns


char pin[] = { 0, 0, 0, 0, 0, 0};
char timeBombSting[] = { 'h', 'h', 'm', 'm'};
byte pinIndex = 0;

char specialKeysID[] = {
  'A',  'B', '#', '*',
  '1',  '2', '3', 'C',
  '4',  '5', '6', 'D',
  '7',  '8', '9', 'E',
  'F',  '0', 'G', 'H'
};

// H = ENTER

char keys[ROWS][COLS] = {
  {specialKeysID[0],  specialKeysID[1], specialKeysID[2], specialKeysID[3]},
  {specialKeysID[4],  specialKeysID[5], specialKeysID[6], specialKeysID[7]},
  {specialKeysID[8],  specialKeysID[9], specialKeysID[10], specialKeysID[11]},
  {specialKeysID[12],  specialKeysID[13], specialKeysID[14], specialKeysID[15]},
  {specialKeysID[16],  specialKeysID[17], specialKeysID[18], specialKeysID[19]}
};

byte rowPins[ROWS] = {2, 3, 4, 5, 6}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {10, 9, 8, 7}; //connect to the column pinouts of the kpd

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


enum  stati {
  PINSETUP, PIN, SETTIMESETUP, SETTIME, SETUPSTART, PRESSSTART, INFUNZIONE, BOOM, DEFUSE
};

stati statoBomba = PINSETUP;


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();

}

void loop() {

  char key = keypad.getKey();
  if (key) {
    Serial.print("Key: ");
    Serial.println(key);
  }
  switch (statoBomba)
  {

    case PINSETUP:
      {
        lcd.setCursor(2, 0);
        lcd.print("Inserire PIN");
        statoBomba = PIN;
        break;
      }

    case PIN:
      {
        if (key) {
          if (isDigit(key))
          {
            if (pinIndex < sizeof(pin) / sizeof(pin[0]))
            {
              pin[pinIndex] = key;
              update_pin_display();
              pinIndex++;

              if (pinIndex >= sizeof(pin) / sizeof(pin[0]))
                statoBomba = SETTIMESETUP;
            }
          }
          else if (key == 'H' && pinIndex >= 4)
            statoBomba = SETTIMESETUP;
        }
        delay(40);
        break;
      }
    case SETTIMESETUP:
      {
        lcd.setCursor(0, 0);
        lcd.print("Inserire Tempo");
        statoBomba = SETTIME;
        delay(40);
        break;
      }
    case SETTIME:
      {
        delay(40);
        break;
      }

    case SETUPSTART:
      {
        lcd.setCursor(2, 0);
        lcd.print("Premi Enter");
        lcd.setCursor(0, 1);
        lcd.print("Per avviare");
        statoBomba = PRESSSTART;
        delay(40);
        break;
      }
    case PRESSSTART:
      {
        if (key)
          if (key == 'H')
            statoBomba = INFUNZIONE;
        break;
      }

    case INFUNZIONE:
      {
        break;
      }
    case BOOM:
      {
        break;
      }
    case DEFUSE:
      {
        break;
      }
  }
}

void update_pin_display()
{


  String pinString = "";
  for (int i = 0; i < sizeof(pin) / sizeof(pin[0]); i++)
  {

    if (!pin[i])
      break;
    pinString += pin[i];
  }

  lcd.setCursor(2, 1);
  lcd.print(pinString);
}
