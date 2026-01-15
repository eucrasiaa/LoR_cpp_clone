#pragma once
#include <string>
#include <cstdlib>
#include "SkillSet.h"
using namespace std;
enum UnitType { PLAYER, ENEMY };
class Unit {
  public:
    // persistant stats
    std::string name;
    int maxHp;
    int maxStagger;
    int speedMin, speedMax;
    SkillSet * skillSet;
    UnitType unitType;
    // in combat stats

    int currentSpeed;
    int hp;
    int stagger;
    int turnStaggered = -1;
    int chosenSkillIndex = -1;
    int targetedUnitIndex = -1;
    SkillSet * activeSkills;

    
    Unit(std::string n, int h, int s, int sMin, int sMax, UnitType uType) 
      : name(n), maxHp(h), hp(h), maxStagger(s), stagger(s), speedMin(sMin), speedMax(sMax), unitType(uType) {};
    void rollSpeed();
    void takeDamage(int dmg);
    void takeStagger(int stag);
    void inheritSkillSet(SkillSet* newSkillSet);
    void displayUnitInfo();
    void displayUnitInfoColorful();
    
    void newCombatReset();
    void setTarget(int targetIndex);
    
    void combatTurnInit(int turnNumber );
   
    // 
    int selectSkill(); // returns index of chosen skill
    Unit* chooseTarget(Unit** enemies, int enemyCount); // given by CombatScene

    ~Unit(){
      delete skillSet;
    }      
};
