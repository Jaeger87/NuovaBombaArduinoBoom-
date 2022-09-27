#pragma once
#include "BombState.h"

class DefuseState : public BombState
{
  public:
    DefuseState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd);
    void OnEnter() override;
    void OnLoop(int deltaTime, char key) override;
    void OnExit() override;

};
