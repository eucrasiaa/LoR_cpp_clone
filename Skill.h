
#ifndef SKILL_H
#define SKILL_H
#include "Move.h"
#include <string>
#include <iostream>
// skill item is a card, containing 1-4 moves 
class Skill {
  public:
    std::string skillName;
    Move* moves[4];
    int moveCount;

    Skill(std::string name);
    void addMove(Move* move);
    std::string DisplaySkill();
    std::string getSkillName(){
      return skillName;
    }
    ~Skill(){
      for(int i=0; i<moveCount; i++){
        delete moves[i];
      }
    }
};

//  ==39429==ERROR: AddressSanitizer: new-delete-type-mismatch on 0x7b9b913e0010 in thread T0:
//   object passed to delete has wrong type:
//   size of the allocated type:   16 bytes;
//   size of the deallocated type: 12 bytes.
//     #0 0x7f7b92b54e8d in operator delete(void*, unsigned long) /usr/src/debug/gcc/gcc/libsanitizer/asan/asan_new_delete.cpp:155
//     #1 0x55f02277beee in Skill::~Skill() /home/willc/Documents/LoRClone/Skill.h:19
//     #2 0x55f02277c0b9 in SkillSet::~SkillSet() /home/willc/Documents/LoRClone/SkillSet.h:25
//     #3 0x55f02277c325 in Unit::~Unit() /home/willc/Documents/LoRClone/unit.cpp:34
//     #4 0x55f02277bc0d in main /home/willc/Documents/LoRClone/skillset_test.cpp:13
//     #5 0x7f7b92227b8a  (/usr/lib/libc.so.6+0x27b8a) (BuildId: 7ca1c72ce7733770eeca8102591e6d59d18b2e6a)
//     #6 0x7f7b92227c4a in __libc_start_main (/usr/lib/libc.so.6+0x27c4a) (BuildId: 7ca1c72ce7733770eeca8102591e6d59d18b2e6a)
//     #7 0x55f02277b264 in _start (/home/willc/Documents/LoRClone/skillset_test+0x4264) (BuildId: 3a523da9d2e5978d1a46c283f3c0f51a4fb90363)
//
// 0x7b9b913e0010 is located 0 bytes inside of 16-byte region [0x7b9b913e0010,0x7b9b913e0020)
// allocated by thread T0 here:
//     #0 0x7f7b92b53d2d in operator new(unsigned long) /usr/src/debug/gcc/gcc/libsanitizer/asan/asan_new_delete.cpp:86
//     #1 0x55f02277b4e2 in DemoSkill1() /home/willc/Documents/LoRClone/SkillSetGen.cpp:7
//     #2 0x55f02277bab3 in main /home/willc/Documents/LoRClone/skillset_test.cpp:11
//     #3 0x7f7b92227b8a  (/usr/lib/libc.so.6+0x27b8a) (BuildId: 7ca1c72ce7733770eeca8102591e6d59d18b2e6a)

// this mismatch is because Skill is deleting Move pointers, but some of those are actually Attack objects
// need to make Move's destructor virtual so that the correct destructor is called for derived classes
// fix by changing Move class destructor to virtual in Move.h

#endif // SKILL_H
