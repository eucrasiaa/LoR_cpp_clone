#ifndef MOVE_H
#define MOVE_H
#include <string>
using namespace std;
enum class ActionType { ATTACK, GUARD, EVADE };
// helper for printing enums:

enum class DamageType { SLASH, PIERCE, BLUNT, NONE };
class Move {
  // has an action type, attacks 
  public:
    ActionType moveType;
    int minValue;
    int maxValue;

  Move(ActionType aType, int minVal, int maxVal);
  string actionTypeToString(ActionType aType);

  string displayMove();
  string displayMoveColorful();
  virtual ~Move(){}
};
class Attack : public Move {
  // has an attack TYPE (from enum)
  public:
    DamageType damageType;
  // use parent constructor and add damage TYPE
  Attack(ActionType aType, int minVal, int maxVal, DamageType dType);
  string displayMove();
  string damageTypeToString(DamageType dType){
      switch(dType) {
          case DamageType::SLASH:
              return "Slash";
          case DamageType::PIERCE:
              return "Pierce";
          case DamageType::BLUNT:
              return "Blunt";
          case DamageType::NONE:
              return "None";
          default:
              return "Unknown";
      }
  }

  ~Attack(){}
};
#endif // MOVE_H
