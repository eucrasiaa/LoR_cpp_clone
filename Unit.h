#pragma once
#include <string>
#include <cstdlib>
#include "SkillSet.h"
using namespace std;

class Unit {
  public:
    std::string name;
    int hp, maxHp;
    int stagger, maxStagger;
    int speedMin, speedMax;
    int currentSpeed;
    SkillSet * skillSet;

    Unit(std::string n, int h, int s, int sMin, int sMax);
    void rollSpeed();
    void takeDamage(int dmg);
    void takeStagger(int stag);
    void inheritSkillSet(SkillSet* newSkillSet);
    ~Unit(){
      delete skillSet;
    }      
};
