#include "TriggeredState.h"
#include "BombFSM.h"

TriggeredState::TriggeredState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void TriggeredState::OnEnter()
{
  lcd->clear();
  lcd->setCursor(2, 0);
  lcd->print("Esplosione in");
  PrintTime();
  
}

void TriggeredState::OnLoop(int deltaTime, char key)
{
  
}

void TriggeredState::OnExit()
{

}

void TriggeredState::PrintTime()
{
}
