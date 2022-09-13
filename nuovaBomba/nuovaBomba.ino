#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 5; //5 rows
const byte COLS = 4; //4 columns

                    
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

byte rowPins[ROWS] = {2,3,4,5,6}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {10,9,8,7}; //connect to the column pinouts of the kpd

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


enum  stati {
  PIN, SETTIME, PRESSSTART, INFUNZIONE, BOOM, DEFUSE};


LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(2,0);
  lcd.print("Inserire PIN");

  lcd.setCursor(2,1);
  lcd.print("Yeah");

}

void loop() {

  char key = keypad.getKey();
    // just print the pressed key
    
   if (key){
    Serial.print("Key: ");
    Serial.println(key);
  } 


}
