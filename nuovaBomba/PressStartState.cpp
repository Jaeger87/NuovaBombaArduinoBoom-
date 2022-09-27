#include "PressStartState.h"
#include "BombFSM.h"

PressStartState::PressStartState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void PressStartState::OnEnter()
{

  lcd->clear();
  lcd->setCursor(2, 0);
  lcd->print("Inserire PIN");
}

void PressStartState::OnLoop(int deltaTime, char key)
{

}

void PressStartState::OnExit()
{

}

