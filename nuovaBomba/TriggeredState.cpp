#include "TriggeredState.h"
#include "BombFSM.h"

TriggeredState::TriggeredState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void TriggeredState::OnEnter()
{
  lcd->clear();
  lcd->setCursor(1, 0);
  lcd->print("Esplosione in:");
  timeBomb = bFSM->GetTime();
  PrintTime();

}

void TriggeredState::OnLoop(int deltaTime, char key)
{
  timeBomb -= deltaTime;
  Serial.println(timeBomb);
  PrintTime();
  if (timeBomb <= 0)
    bFSM->ChangeState(BOOM);

  prev_timeBomb = timeBomb;
}

void TriggeredState::OnExit()
{

}

void TriggeredState::PrintTime()
{
  long timeForPrint = timeBomb;
  timeForPrint -= timeForPrint % 100;

  long decimalsPart = timeForPrint % 1000;
  long decimals = decimalsPart / 100;
  timeForPrint -= decimalsPart;

  long secondsPart = timeForPrint % 60000;
  long seconds = secondsPart / 1000;
  timeForPrint -= secondsPart;

  long minutesPart = timeForPrint % 3600000;
  long minutes = minutesPart / 60000;
  timeForPrint -= minutesPart;

  lcd->setCursor(12, 1);
  lcd->print((char)('0' + decimals));
  lcd->setCursor(11, 1);
  lcd->print(".");
  lcd->setCursor(9, 1);
  lcd->print(seconds);
  lcd->setCursor(8, 1);
  lcd->print(":");
  lcd->setCursor(6, 1);
  lcd->print(minutes);
  lcd->setCursor(5, 1);
  lcd->print(":");
}
