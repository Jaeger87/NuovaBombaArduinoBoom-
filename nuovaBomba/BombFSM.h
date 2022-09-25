#pragma once
#include "BombState.h"
#include "SetupPinState.h"

class BombFSM
{

  public:
    BombFSM();
    enum bombStates {
      PIN,
      SETTIME,
      SETUPSTART,
      PRESSSTART,
      INFUNZIONE,
      BOOM,
      DEFUSE
    };


  private:
    BombState* currentBombState;
    SetupPinState* setupPinState;
    void Initialize();

};
