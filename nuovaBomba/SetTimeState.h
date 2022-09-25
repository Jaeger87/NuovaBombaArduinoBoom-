#pragma once
#include "BombState.h"

class SetTimeState : public BombState
{
  public:
    SetTimeState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd);
    void OnEnter() override;
    void OnLoop(int deltaTime, char key) override;
    void OnExit() override;

  private:
    byte timeBombIndex = 0;
    char timeBombString[4];
    int timeBombDigitLimit[4];
    void UpdateSettimeDisplay();

};
