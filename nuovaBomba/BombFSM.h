#pragma once
#include "BombState.h"
#include "SetupPinState.h"
#include "SetTimeState.h"
#include "PressStartState.h"
#include "TriggeredState.h"

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
    bool CheckPin(char* pin, int lengthPin);
    void SetPin(char* pin);
    void SetTime(unsigned long _TimeBomb);


  private:
    BombState* currentBombState;
    SetupPinState* setupPinState;
    SetTimeState* setTimeState;
    PressStartState* pressStartState;
    TriggeredState* triggeredState;
    unsigned long currentTime = 0;
    unsigned long oldTime = 0;
    unsigned long timeBomb = 0;
    LiquidCrystal_I2C* lcd;
    Keypad* keypad;
    char bombPin[6];
    
    

};
