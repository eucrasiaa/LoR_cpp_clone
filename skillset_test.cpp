// main, includes unit + skillset (which include all their own requiered elements)
//

#include <iostream>
#include "Unit.h"
#include "SkillSetGen.cpp"

int main(){
  cout<<"Starting SkillSet Test"<<endl;
  Unit *testUnit = new Unit("TestUnit", 100, 50, 10, 20);
  testUnit->inheritSkillSet(genDemoSkillSet_1());

  testUnit->displayUnitInfo();
  delete testUnit;
  cout<<"Ending SkillSet Test"<<endl;
  return 0;
}
