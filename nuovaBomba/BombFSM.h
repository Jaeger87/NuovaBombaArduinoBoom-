#pragma once
#include "BombState.h"
#include "SetupPinState.h"

enum bombStates {
  SETUPPIN,
  SETTIME,
  SETUPSTART,
  PRESSSTART,
  INFUNZIONE,
  BOOM,
  DEFUSE
};

class BombFSM
{

  public:
    BombFSM(LiquidCrystal_I2C* _lcd, Keypad* _keypad);
    void OnLoop();
    void ChangeState(bombStates newState);
    void Initialize();


  private:
    BombState* currentBombState;
    SetupPinState* setupPinState;
    unsigned long currentTime = 0;
    unsigned long oldTime = 0;
    LiquidCrystal_I2C* lcd;
    Keypad* keypad;
    

};
