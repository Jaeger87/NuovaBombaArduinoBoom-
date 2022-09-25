#pragma once
#include "BombState.h"
#include "SetupPinState.h"

class BombFSM
{

  public:
    BombFSM(LiquidCrystal_I2C* _lcd);
    enum bombStates {
      PIN,
      SETTIME,
      SETUPSTART,
      PRESSSTART,
      INFUNZIONE,
      BOOM,
      DEFUSE
    };
    void ChangeState(bombStates newState);


  private:
    BombState* currentBombState;
    SetupPinState* setupPinState;
    LiquidCrystal_I2C* lcd;
    void Initialize();

};
