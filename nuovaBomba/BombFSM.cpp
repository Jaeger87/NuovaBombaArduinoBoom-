#include "BombFSM.h"

BombFSM::BombFSM(LiquidCrystal_I2C* _lcd):lcd(_lcd)
{

}

void BombFSM::ChangeState(bombStates newState)
{
  
}


void BombFSM::Initialize()
{
  setupPinState = new SetupPinState(this, lcd);
}
