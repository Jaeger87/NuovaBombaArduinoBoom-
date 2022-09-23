#include "BombState.h"

class SetupPinState : public BombState
{
    void OnEnter() override;
    void OnLoop() override;
    void OnExit() override;
};
