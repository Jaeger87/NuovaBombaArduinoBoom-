#include "PressStartState.h"
#include "BombFSM.h"

PressStartState::PressStartState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void PressStartState::OnEnter()
{

  lcd->clear();
  lcd->setCursor(3, 0);
  lcd->print("Premi Enter");
  lcd->setCursor(3, 1);
  lcd->print("Per avviare");
}

void PressStartState::OnLoop(int deltaTime, char key)
{

}

void PressStartState::OnExit()
{

}
