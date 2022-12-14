#include "SetTimeState.h"
#include "BombFSM.h"

SetTimeState::SetTimeState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void SetTimeState::OnEnter()
{
  timeBombIndex = 0;
  timeBombString[0] = 'h';
  timeBombString[1] = 'h';
  timeBombString[2] = 'm';
  timeBombString[3] = 'm';

  timeBombDigitLimit[0] = 2;
  timeBombDigitLimit[1] = 9;
  timeBombDigitLimit[2] = 6;
  timeBombDigitLimit[3] = 9;


  lcd->clear();
  lcd->setCursor(1, 0);
  lcd->print("Inserire Tempo");
  UpdateSetTimeDisplay();
}

void SetTimeState::OnLoop(int deltaTime, char key)
{
  
  if (key) {
    if (isDigit(key)) {
      int keyInt = key - '0';
      if (keyInt <= timeBombDigitLimit[timeBombIndex]) {
        if (timeBombIndex == 0 && keyInt == 2) {
          timeBombDigitLimit[1] = 3;
        }
        timeBombString[timeBombIndex] = key;
        timeBombIndex++;
        UpdateSetTimeDisplay();
        if (timeBombIndex >= 4) {

          bFSM->ChangeState(PRESSSTART);
        }
      }
    }
  }
}

void SetTimeState::OnExit()
{
  long timeBomb = 0;
  timeBomb += (long)1000 * 60 * (timeBombString[3] - '0');
  timeBomb += (long)1000 * 60 * 10 * (timeBombString[2] - '0');
  timeBomb += (long)1000 * 60 * 60 * (timeBombString[1] - '0');
  timeBomb += (long)1000 * 60 * 60 * 10 * (timeBombString[0] - '0');

  Serial.println(timeBomb);
  bFSM->SetTime(timeBomb);
}


void SetTimeState::UpdateSetTimeDisplay() {

  String timeString = "";
  timeString += timeBombString[0];
  timeString += timeBombString[1];
  timeString += ':';
  timeString += timeBombString[2];
  timeString += timeBombString[3];
  lcd->setCursor(6, 1);
  lcd->print(timeString);
}
