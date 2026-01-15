#include <iostream>
#include "SkillSet.h"

SkillSet* genDemoSkillSet_1(){
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
  demoSkillSet1->addSkill(slashSkill, true);
  demoSkillSet1->addSkill(pierceSkill, false);
  demoSkillSet1->listSkills();

  return demoSkillSet1;
  
}
