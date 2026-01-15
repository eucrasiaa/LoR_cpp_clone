#pragma once
#include "CombatScene.h"
class CombatEngine{
  friend class Unit;
  friend class CombatScene;
  public:
    int validatePreTurn(); // ensure all units have a valid selected skill and target
    CombatEngine();
};  
