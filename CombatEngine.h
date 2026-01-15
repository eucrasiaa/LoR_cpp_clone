#pragma once
class CombatEngine{
  friend class Unit;
  public:
    int playerUnitCount;
    int enemyUnitCount;
  CombatEngine(int playerUnitCount, int enemyUnitCount);
};  
