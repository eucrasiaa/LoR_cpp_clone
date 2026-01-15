

#include "devFunctions.h"
SkillSet* genDemoSkillSet_1(){
  cout<< "\033[31m";
  SkillSet *demoSkillSet1 = new SkillSet();

  Skill* slashSkill = new Skill("Slash Attack");
  Move* slashMove = new Attack(ActionType::ATTACK, 10, 20, DamageType::SLASH);
  Move* guardMove = new Move(ActionType::GUARD, 5, 20);
  slashSkill->addMove(slashMove);
  slashSkill->addMove(guardMove);

  Skill* pierceSkill = new Skill("Pierce Attack");
  Move* pierceMove = new Attack(ActionType::ATTACK, 15, 25, DamageType::PIERCE);
  pierceSkill->addMove(pierceMove);


  std::cout << "Demo Skill Set Created" << std::endl;
  demoSkillSet1->addSkill(slashSkill, false);
  demoSkillSet1->addSkill(pierceSkill, false);
  demoSkillSet1->displayAllSkills();


//
  cout<< "\033[0m"; // reset text color

  return demoSkillSet1;
  
}

SkillSet* genDemoSkillSet_2(){
  cout<< "\033[31m";
  SkillSet *demoSkillSet2 = new SkillSet();

  Skill* bashSkill = new Skill("Bash Attack");
  Move* bashMove = new Attack(ActionType::ATTACK, 20, 30, DamageType::BLUNT);
  bashSkill->addMove(bashMove);

  Skill* sliceSkill = new Skill("Vertical Slash");

  Move* sliceMove = new Attack(ActionType::ATTACK, 20, 30, DamageType::SLASH);
  sliceSkill->addMove(sliceMove);


  std::cout << "Demo Skill Set Created" << std::endl;
  demoSkillSet2->addSkill(bashSkill, false);
  demoSkillSet2->addSkill(sliceSkill, false);
  demoSkillSet2->displayAllSkills();
//
  cout<< "\033[0m"; // reset text color 
  return demoSkillSet2;
}

void DrawLine(int rows=1, int color=37){
  // color codes: 30-black, 31-red, 32-green, 33-yellow, 34-blue, 35-magenta, 36-cyan, 37-white
  for (int i=0; i<rows; i++)
    std::cout << "\033[" << color << "m" << "----------------------------------------" << "\033[0m" << std::endl;
}
