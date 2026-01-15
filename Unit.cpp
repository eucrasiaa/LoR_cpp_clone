#include "Unit.h"
Unit::Unit(std::string n, int h, int s, int sMin, int sMax) 
  : name(n), maxHp(h), hp(h), maxStagger(s), stagger(s), speedMin(sMin), speedMax(sMax) {}

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
      skillSet->listSkills();
    }
