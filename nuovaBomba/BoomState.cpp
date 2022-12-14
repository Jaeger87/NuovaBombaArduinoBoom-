#include "BoomState.h"
#include "BombFSM.h"

BoomState::BoomState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void BoomState::OnEnter()
{
  lcd->clear();
  lcd->setCursor(6, 0);
  lcd->print("Boom");
  bFSM->PlaySiren();
}

void BoomState::OnLoop(int deltaTime, char key)
{

}

void BoomState::OnExit()
{

}
