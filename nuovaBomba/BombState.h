#pragma once

class BombState
{
  public:
    virtual void OnEnter() = 0;
    virtual void OnLoop() = 0;
    virtual void OnExit() = 0;

  protected:
    void ChangeState();
};
