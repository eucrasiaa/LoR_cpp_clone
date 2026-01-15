// main, includes unit + skillset (which include all their own requiered elements)
//
//
#include <iostream>
#include "Unit.h"
#include "SkillSetGen.cpp"

int main(){
  cout<<"Starting SkillSet Test"<<endl;
  Unit *testUnit = new Unit("TestUnit", 100, 50, 10, 20);
  testUnit->inheritSkillSet(genDemoSkillSet_1());
g++ -g -Wall -Wextra -pedantic -fsanitize=address -o skillset_test skillset_test.cpp SkillSet.o Skill.o Move.o
/usr/bin/ld: /tmp/cc6J8cUd.o: in function `main':
/home/willc/Documents/LoRClone/skillset_test.cpp:10:(.text+0x7ba): undefined reference to `Unit::Unit(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, int, int, int, int)'
/usr/bin/ld: /home/willc/Documents/LoRClone/skillset_test.cpp:11:(.text+0x82e): undefined reference to `Unit::inheritSkillSet(SkillSet*)'
collect2: error: ld returned 1 exit status
                                          // this is due to the Unit constructor not being defined in a compiled file
                                          // to fix, 
  delete testUnit;
  cout<<"Ending SkillSet Test"<<endl;
  return 0;
}
