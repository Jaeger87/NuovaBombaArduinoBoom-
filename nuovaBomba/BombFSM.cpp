#include "BombFSM.h"

BombFSM::BombFSM(LiquidCrystal_I2C* _lcd, Keypad* _keypad): lcd(_lcd), keypad(_keypad)
{
  
}

void BombFSM::OnLoop()
{
  currentTime = millis();
  int deltaTime = currentTime - oldTime;
  char key = keypad->getKey();
  Serial.println("fsmkkoko");
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

        break;
      }
  }
  currentBombState->OnEnter();
}


void BombFSM::Initialize()
{
  setupPinState = new SetupPinState(this, lcd);

  ChangeState(SETUPPIN);
}
