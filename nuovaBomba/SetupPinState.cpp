#include "SetupPinState.h"
#include "BombFSM.h"

SetupPinState::SetupPinState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void SetupPinState::OnEnter()
{
  pin[0] = 0;
  pin[1] = 0;
  pin[2] = 0;
  pin[3] = 0;
  pin[4] = 0;
  pin[5] = 0;

  lcd->clear();
  lcd->setCursor(2, 0);
  lcd->print("Inserire PIN");
}

void SetupPinState::OnLoop(int deltaTime, char key)
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
          bFSM->ChangeState(SETTIME);
      }
    } else if (key == 'H' && pinIndex >= 4)
      bFSM->ChangeState(SETTIME);
  }
}

void SetupPinState::OnExit()
{

}


void SetupPinState::update_pin_display(bool underscore)
{
  String pinString = "";
  for (int i = 0; i < sizeof(pin) / sizeof(pin[0]); i++) {
    if (!pin[i])
      break;
    pinString += pin[i];
  }
  if (underscore && pinIndex < (sizeof(pin) / sizeof(pin[0])) - 1)
    pinString += '_';
  else
    pinString += ' ';
  lcd->setCursor(5, 1);
  lcd->print(pinString);
}
