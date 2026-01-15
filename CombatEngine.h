#pragma once
class CombatScene;
class CombatEngine{
  friend class Unit;
  friend class CombatScene;
  private:
    CombatScene* scene;
    int** combatOrder; // 2D array holding order of actions for the turn, -=enemy, +=player, pairs of who targets who and clashes
  public:
    int validatePreTurn(); // ensure all units have a valid selected skill and target
    CombatEngine(CombatScene* scene);
    ResolveCombatOrder();
}; 
