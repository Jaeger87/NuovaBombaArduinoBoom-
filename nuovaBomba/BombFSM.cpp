#include "BombFSM.h"

BombFSM::BombFSM(LiquidCrystal_I2C* _lcd, Keypad* _keypad): lcd(_lcd), keypad(_keypad)
{

}

void BombFSM::OnLoop()
{
  currentTime = millis();
  int deltaTime = currentTime - oldTime;
  char key = keypad->getKey();
  currentBombState->OnLoop(deltaTime, key);
  oldTime = currentTime;
}

void BombFSM::ChangeState(bombStates newState)
{
  if (currentBombState)
    currentBombState->OnExit();

  switch (newState) {
    case SETUPPIN:
      {
        currentBombState = setupPinState;
        break;
      }
    case SETTIME:
      {
        currentBombState = setTimeState;
        break;
      }
    case PRESSSTART:
      {
        currentBombState = pressStartState;
        break;
      }

    case TRIGGERED:
      {
        currentBombState = triggeredState;
        break;
      }

    case BOOM:
      {
        currentBombState = boomState;
        break;
      }
    case DEFUSE:
      {
        currentBombState = defuseState;
        break;
      }

  }
  currentBombState->OnEnter();
}

void BombFSM::Initialize()
{
  bombPin[0] = 0;
  bombPin[1] = 0;
  bombPin[2] = 0;
  bombPin[3] = 0;
  bombPin[4] = 0;
  bombPin[5] = 0;
  setupPinState = new SetupPinState(this, lcd);
  setTimeState = new SetTimeState(this, lcd);
  pressStartState = new PressStartState(this, lcd);
  triggeredState = new TriggeredState(this, lcd);
  boomState = new BoomState(this, lcd);
  defuseState = new DefuseState(this, lcd);
  ChangeState(SETUPPIN);
}

bool BombFSM::CheckPin(char* pin)
{
  if (bombPin[0] != pin[0])
    return false;
  if (bombPin[1] != pin[1])
    return false;
  if (bombPin[2] != pin[2])
    return false;
  if (bombPin[3] != pin[3])
    return false;
  if (bombPin[4] != pin[4])
    return false;
  if (bombPin[5] != pin[5])
    return false;
  return true;
}

void BombFSM::SetPin(char* pin)
{
  bombPin[0] = pin[0];
  bombPin[1] = pin[1];
  bombPin[2] = pin[2];
  bombPin[3] = pin[3];
  bombPin[4] = pin[4];
  bombPin[5] = pin[5];
}

void BombFSM::SetTime(unsigned long _TimeBomb)
{
  timeBomb = _TimeBomb;
}

long BombFSM::GetTime()
{
  return timeBomb;
}
