#pragma once
#include "BombState.h"

class SetupPinState : public BombState
{
  public:
    SetupPinState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd);
    void OnEnter() override;
    void OnLoop(int deltaTime, char key) override;
    void OnExit() override;

  private:
    byte pinIndex = 0;
    int pinTime = 0;
    bool pinUnderscore = false;
    void update_pin_display(bool underscore);
    char pin[6];
};
