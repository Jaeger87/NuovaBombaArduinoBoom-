#pragma once
#include "BombState.h"
#include "SetupPinState.h"
#include "SetTimeState.h"

enum bombStates {
  SETUPPIN,
  SETTIME,
  PRESSSTART,
  TRIGGERED,
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
    SetTimeState* setTimeState;
    unsigned long currentTime = 0;
    unsigned long oldTime = 0;
    unsigned long timeBomb = 0;
    LiquidCrystal_I2C* lcd;
    Keypad* keypad;
    char pin[6];
    
    

};
