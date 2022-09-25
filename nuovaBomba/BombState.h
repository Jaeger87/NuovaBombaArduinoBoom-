#pragma once
#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

class BombFSM;

class BombState
{

  public:
    
    BombState(BombFSM* _bFSM, LiquidCrystal_I2C* _lcd);
    virtual void OnEnter() = 0;
    virtual void OnLoop(int deltaTime, char key) = 0;
    virtual void OnExit() = 0;


  protected:
    BombFSM* bFSM;
    LiquidCrystal_I2C* lcd;
};
