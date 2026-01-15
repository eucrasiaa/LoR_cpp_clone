
#include "Move.h"
// defiens ActionType, DamageType
Move::Move(ActionType aType, int minVal, int maxVal) {
    moveType = aType;
    minValue = minVal;
    maxValue = maxVal;
  }
string Move::actionTypeToString(ActionType aType){
    switch(aType) {
        case ActionType::ATTACK:
            return "Attack";
        case ActionType::GUARD:
            return "Guard";
        case ActionType::EVADE:
            return "Evade";
        default:
            return "Unknown";
    }
}

string Move::displayMove(){
    return "Move Type: " + actionTypeToString(moveType) + ", Min: " + to_string(minValue) + ", Max: " + to_string(maxValue);

}
  // use parent constructor and add damage TYPE
Attack::Attack(ActionType aType, int minVal, int maxVal, DamageType dType)
    : Move(aType, minVal, maxVal) {
      damageType = dType;
    }
string Attack::displayMove(){
    return Move::displayMove() + ", Damage Type: " + damageTypeToString(damageType);
}
