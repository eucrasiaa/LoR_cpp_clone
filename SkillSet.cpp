// stores all the skills equipped to a unit
// units only have access to a portion of the skills at any instance, so it marks which are (active) and only those can be used
#include "SkillSet.h"
SkillSet::SkillSet() {
      skillCount = 0;
      for (int i = 0; i < 10; i++) {
        skills[i] = nullptr;
        active[i] = false;
      }
    }

    void SkillSet::listSkills() {
      cout<<"Skill Set:"<<endl;
      for (int i = 0; i < skillCount; i++) {
        if (skills[i] != nullptr) {
          cout<<i+1<<". "<<skills[i]->DisplaySkill();
          if (active[i]) {
            cout<<" (Active)";
          }
          cout<<endl;
        }
      }
    }

