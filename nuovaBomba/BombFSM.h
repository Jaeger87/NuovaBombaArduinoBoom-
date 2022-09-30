#pragma once
#include "BombState.h"
#include "SetupPinState.h"
#include "SetTimeState.h"
#include "PressStartState.h"
#include "TriggeredState.h"
#include "BoomState.h"
#include "DefuseState.h"

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
    long GetTime();

  private:
    BombState* currentBombState;
    SetupPinState* setupPinState;
    SetTimeState* setTimeState;
    PressStartState* pressStartState;
    TriggeredState* triggeredState;
    BoomState* boomState;
    DefuseState* defuseState;
    unsigned long currentTime = 0;
    unsigned long oldTime = 0;
    long timeBomb = 0;
    LiquidCrystal_I2C* lcd;
    Keypad* keypad;
    char bombPin[6];
    
    

};
