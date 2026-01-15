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
void SkillSet::addSkill(Skill* skill, bool isActive=false){

  if(skillCount <10){
    skills[skillCount] = skill;
    active[skillCount] = isActive; // default to inactive
    skillCount++;
  }
}


void SkillSet::displayAllSkills() {
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

void SkillSet::displayAllSkillsColorful() {
  cout<<"\033[1;34mSkill Set:\033[0m"<<endl;
  for (int i = 0; i < skillCount; i++) {
    if (skills[i] != nullptr) {
      cout<<"\033[1;33m"<<i+1<<". \033[0m"<<skills[i]->DisplaySkill();
      if (active[i]) {
        cout<<"\033[1;32m (Active)\033[0m";
      }
      cout<<endl;
    }
  }
}
int* SkillSet::activeSkillPool(){
  int activeCount = getActiveSkillCount();
  int* activeIndices = new int[activeCount];
  int index = 0;
  for(int i=0; i<skillCount; i++){
    if(active[i]){
      activeIndices[index] = i;
      index++;
    }
  }
  return activeIndices;
}
void SkillSet::drawSkill(){
  // picks a random inactive skills and adds it to active pool
  int inactiveIndices[10];
  int inactiveCount = 0;
  for(int i=0; i<skillCount; i++){
    if(!active[i]){
      inactiveIndices[inactiveCount] = i;
      inactiveCount++;
    }
  }
  if(inactiveCount > 0){
    int randIndex = rand() % inactiveCount;
    int skillToActivate = inactiveIndices[randIndex];
    active[skillToActivate] = true;
    cout<<"New Skill Activated: "<<skills[skillToActivate]->getSkillName()<<endl;
  }
  else{
    cout<<"No Inactive Skills to Activate!"<<endl;
  }
} 


