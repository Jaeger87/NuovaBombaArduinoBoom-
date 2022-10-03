#pragma once
#include "BombState.h"

class TriggeredState : public BombState
{
  public:
    TriggeredState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd);
    void OnEnter() override;
    void OnLoop(int deltaTime, char key) override;
    void OnExit() override;
  private:
    void PrintTime();
    long timeBomb = 0;
    long prev_timeBomb = 0;
    char pin[6];
};
