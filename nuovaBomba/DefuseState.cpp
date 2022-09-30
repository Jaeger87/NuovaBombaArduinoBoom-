#include "DefuseState.h"
#include "BombFSM.h"

DefuseState::DefuseState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void DefuseState::OnEnter()
{
  lcd->clear();
  lcd->setCursor(5, 0);
  lcd->print("Bomba");
  lcd->setCursor(0, 1);
  lcd->print("Disinnescata");
}

void DefuseState::OnLoop(int deltaTime, char key)
{

}

void DefuseState::OnExit()
{

}
