#include "TriggeredState.h"
#include "BombFSM.h"

TriggeredState::TriggeredState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd): BombState(_bFSM, _lcd)
{

}

void TriggeredState::OnEnter()
{

}

void TriggeredState::OnLoop(int deltaTime, char key)
{

}

void TriggeredState::OnExit()
{

}
