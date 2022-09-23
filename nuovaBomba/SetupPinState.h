#pragma once
#include "BombState.h"

class SetupPinState : public BombState
{
    SetupPinState(BombFSM* _bFSM);
    void OnEnter() override;
    void OnLoop() override;
    void OnExit() override;
};
