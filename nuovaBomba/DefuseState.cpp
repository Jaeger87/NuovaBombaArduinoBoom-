#include "DefuseState.h"
#include "BombFSM.h"

DefuseState::DefuseState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void DefuseState::OnEnter()
{

}

void DefuseState::OnLoop(int deltaTime, char key)
{

}

void DefuseState::OnExit()
{

}
