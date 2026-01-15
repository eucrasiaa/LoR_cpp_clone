#include "Unit.h"
// Unit::Unit(std::string n, int h, int s, int sMin, int sMax) 
//   : name(n), maxHp(h), hp(h), maxStagger(s), stagger(s), speedMin(sMin), speedMax(sMax) {}

void Unit::rollSpeed() {
  currentSpeed = speedMin + (rand() % (speedMax - speedMin + 1));
}
void Unit::takeDamage(int dmg) {
  cout<<name<<" takes "<<dmg<<" damage!"<<endl;
  hp -= dmg;
  if (hp < 0) hp = 0;
  takeStagger(dmg);
}
void Unit::takeStagger(int stag) {
  cout<<name<<" takes "<<stag<<" stagger!"<<endl;
  stagger -= stag;
  if (stagger < 0) stagger = 0;
}
void Unit::inheritSkillSet(SkillSet* newSkillSet){
  skillSet = newSkillSet;
}
void Unit::displayUnitInfo(){
  cout<<"Unit Name: "<<name<<endl;
  cout<<"HP: "<<hp<<"/"<<maxHp<<endl;
  cout<<"Stagger: "<<stagger<<"/"<<maxStagger<<endl;
  cout<<"Speed Range: "<<speedMin<<" - "<<speedMax<<endl;
  cout<<"Skills: "<<endl;
  skillSet->displayAllSkills();
}
void Unit::displayUnitInfoColorful(){
  // use ascii codes different colors for variable and then value
  cout<<"\033[1;32mUnit Name:\033[0m "<<name<<endl;
  cout<<"\033[1;32mHP:\033[0m "<<hp<<"/"<<maxHp<<endl;
  cout<<"\033[1;32mStagger:\033[0m "<<stagger<<"/"<<maxStagger<<endl;
  cout<<"\033[1;32mSpeed Range:\033[0m "<<speedMin<<" - "<<speedMax<<endl;
  cout<<"\033[1;32mSkills:\033[0m "<<endl;
  skillSet->displayAllSkillsColorful();
}



void Unit::newCombatReset(){
  hp = maxHp;
  stagger = maxStagger;
  turnStaggered = -1;
  chosenSkillIndex = -1;
  targetedUnitIndex = -1;
  skillSet->resetSkills();
  skillSet->drawSkill(); // draw initial 1
  skillSet->drawSkill(); // draw initial 2
}
void Unit::combatTurnInit(int turnNumber){
  // rolls speed, sets active skills resolves start of turn effects
  //
  // TODO start of turn effects
  //
  if (turnStaggered != -1){
    //turn stagger set to turn it occured, staggered for a turn, therefore when turnStaggered == turnNumber -2 (2 have passed) they recover
    if(turnStaggered == turnNumber-2){
      cout<<name<<" is recovering from being staggered this turn!"<<endl;
      turnStaggered = -1;
    }
    else{
      cout<<name<<" is staggered and misses their turn!"<<endl;
      return;
    }

  }

  rollSpeed();


}
int Unit::selectSkill(){
  // if its an enemy, choose a random skill
  //
  // else:
  if (unitType == ENEMY){
    chosenSkillIndex = rand() % skillSet->getSkillCount();
    return chosenSkillIndex;
  }
  else {
    // player skill selection logic would go here
    // display active skills
    skillSet->displayAllSkillsColorful();
    // prompt for input
    int choice = -1;
    while (choice < 1 || choice > skillSet->getSkillCount()){
      cout<<"Select a skill to use (1 - "<<skillSet->getSkillCount()<<"): ";
      cin>>choice;
      if (choice < 1 || choice > skillSet->getSkillCount()){
        cout<<"Invalid choice, please try again."<<endl;
      }
    }
    chosenSkillIndex = choice - 1;

    cout<<"Player "<<name<<" selects skill "<<skillSet->skills[chosenSkillIndex]->getSkillName()<<"!"<<endl;
    // for now, just return the first skill
    // // and validate it is usable
    // cout<<"Player "<<name<<" selects first active skill!"<<endl;
    // chosenSkillIndex = 0;
    return chosenSkillIndex;
  }
} // returns index of chosen skill

void Unit::setTarget(int targetIndex){
  targetedUnitIndex = targetIndex;
}

Unit* Unit::chooseTarget(Unit** enemies, int enemyCount){
    //enemies have been handled, so can safely read their targeting and such
    // player target selection logic would go here
    // for now, just return the first enemy
    return enemies[0];
    // display enemies

  }
 // given by CombatScene


