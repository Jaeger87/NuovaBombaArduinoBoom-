#include "TriggeredState.h"
#include "BombFSM.h"

TriggeredState::TriggeredState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void TriggeredState::OnEnter()
{
  lcd->clear();
  lcd->setCursor(6, 0);
  lcd->print("Pin");
  timeBomb = bFSM->GetTime();
  PrintTime();
  pin[0] = 0;
  pin[1] = 0;
  pin[2] = 0;
  pin[3] = 0;
  pin[4] = 0;
  pin[5] = 0;
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

  long hours = timeForPrint / 3600000;
  String zero = "0";
  String hourString = (hours > 9 ? String(hours) : String(zero + hours)) + ":";
  String minuteString = (minutes > 9 ? String(minutes) : String(zero + minutes)) + ":";
  String secondsString = (seconds > 9 ? String(seconds) : String(zero + seconds)) + "." + decimals;
  lcd->setCursor(3, 1);
  lcd->print(String(hourString + minuteString + secondsString));

}
