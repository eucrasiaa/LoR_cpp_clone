// stores all the skills equipped to a unit
// units only have access to a portion of the skills at any instance, so it marks which are (active) and only those can be used
#pragma once 
#include "Skill.h"
#include <iostream>
using namespace std;
class SkillSet{
  public:
    // will hold 10 pointers to Skill objects
    Skill *skills[10];
    bool active[10];   // marks if skill is active or not
    int skillCount;
    SkillSet();
    void displayAllSkills();
    void displayAllSkillsColorful();
    
    void addSkill(Skill* skill, bool isActive);
    



    int getSkillCount(){
      return skillCount;
    }

    int getActiveSkillCount(){
      int count = 0;
      for(int i=0; i<skillCount; i++){
        if(active[i]){
          count++;
        }
      }
      return count;
    }

    void drawSkill();
      // picks a random inactive skills and adds it to active pool

    int* activeSkillPool();

    void resetSkills(){
      for(int i=0; i<skillCount; i++){
        active[i] = false;
      }

    }

    ~SkillSet(){
      for(int i=0; i<skillCount; i++){
        delete skills[i];
      }
    }
};


