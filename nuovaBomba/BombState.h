#pragma once
#include "BombFSM.h"
class BombState
{
  public:
    BombState(BombFSM* _bFSM);
    virtual void OnEnter() = 0;
    virtual void OnLoop() = 0;
    virtual void OnExit() = 0;


  protected:
    void ChangeState();
    BombFSM* bFSM;
};
