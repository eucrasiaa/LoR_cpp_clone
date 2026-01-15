// #include "Skill.h"
// skill item is a card, containing 1-4 moves 

#include "Skill.h"
Skill::Skill(std::string name) {
  skillName = name;
  moveCount = 0;
  for (int i = 0; i < 4; i++) {
    moves[i] = nullptr;
  }
  std::cout << "Created Skill: " << skillName << std::endl;
}
void Skill::addMove(Move* move) {
  if (moveCount < 4) {
    moves[moveCount] = move;
    moveCount++;
    std::cout << "Added Move to Skill " << skillName << ": " << move->displayMove() << std::endl;
  }
}

std::string Skill::DisplaySkill() {
  std::string result = skillName + ":\n";
  for (int i = 0; i < moveCount; i++) {
    if (moves[i] != nullptr) {
      result += "  - " + moves[i]->displayMoveColorful() + "\n";
    }
  }
  return result;
}
