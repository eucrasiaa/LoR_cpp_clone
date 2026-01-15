
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
string Move::displayMoveColorful(){
  switch(moveType) {
        case ActionType::ATTACK:
            return "\033[1;31mMove Type:\033[0m \033[1;31mAttack\033[0m, \033[1;32mMin:\033[0m \033[1;32m" + to_string(minValue) + "\033[0m, \033[1;32mMax:\033[0m \033[1;32m" + to_string(maxValue) + "\033[0m";
        case ActionType::GUARD:
            return "\033[1;31mMove Type:\033[0m \033[1;34mGuard\033[0m, \033[1;32mMin:\033[0m \033[1;32m" + to_string(minValue) + "\033[0m, \033[1;32mMax:\033[0m \033[1;32m" + to_string(maxValue) + "\033[0m";
        case ActionType::EVADE:
            return "\033[1;31mMove Type:\033[0m \033[1;35mEvade\033[0m, \033[1;32mMin:\033[0m \033[1;32m" + to_string(minValue) + "\033[0m, \033[1;32mMax:\033[0m \033[1;32m" + to_string(maxValue) + "\033[0m";
        default:
            return "\033[1;31mMove Type:\033[0m \033[1;33mUnknown\033[0m, \033[1;32mMin:\033[0m \033[1;32m" + to_string(minValue) + "\033[0m, \033[1;32mMax:\033[0m \033[1;32m" + to_string(maxValue) + "\033[0m";
    }
}


  // use parent constructor and add damage TYPE
Attack::Attack(ActionType aType, int minVal, int maxVal, DamageType dType)
    : Move(aType, minVal, maxVal) {
      damageType = dType;
    }
string Attack::displayMove(){
    return Move::displayMove() + ", Damage Type: " + damageTypeToString(damageType);
}
