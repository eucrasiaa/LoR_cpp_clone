#include "CombatScene.h"

void CombatScene::startCombat(){
  cout<<"Combat Initialization Setup!"<<endl;
  // run newCombatReset on all Units
  for(int i=0; i<playerCount; i++){
    players[i]->newCombatReset();
  }
  for(int i=0; i<enemyCount; i++){
    enemies[i]->newCombatReset();
  }


  displayCombatants();
}


void CombatScene::LoadPlayers(std::initializer_list<Unit*> playerList){
  playerCount = playerList.size();
  players = new Unit*[playerCount];
  int index = 0;
  for (Unit* unit : playerList) {
    players[index++] = unit;
  }
}
void CombatScene::LoadEnemies(std::initializer_list<Unit*> enemyList){
  enemyCount = enemyList.size();
  enemies = new Unit*[enemyCount];
  int index = 0;
  for (Unit* unit : enemyList) {
    enemies[index++] = unit;  
  }
}

void CombatScene::displayCombatants(){
  cout<<"Player Units:"<<endl;
  for(int i=0; i<playerCount; i++){
    players[i]->displayUnitInfo();
  }
  cout<<"Enemy Units:"<<endl;
  for(int i=0; i<enemyCount; i++){
    enemies[i]->displayUnitInfo();
  }
}
void CombatScene::displayEnemyPreTurn(){
  // show each enemy in a little box, name, hp, stagger, target, and chosen skill
  cout<<"Enemy Status:"<<endl;
  for(int i=0; i<enemyCount; i++){
    Unit* enemy = enemies[i];
    cout<<"------------------------"<<endl;
    cout<<"| Name: "<<enemy->name<<endl;
    cout<<"| HP: "<<enemy->hp<<"/"<<enemy->maxHp<<endl;
    cout<<"| Stagger: "<<enemy->stagger<<"/"<<enemy->maxStagger<<endl;
    cout<<"| Targeting: ";
    if(enemy->targetedUnitIndex >=0 && enemy->targetedUnitIndex < playerCount){
      cout<<players[enemy->targetedUnitIndex]->name<<endl;
    }
    else{
      cout<<"None"<<endl;
    }
    cout<<"| Chosen Skill: ";
    if(enemy->chosenSkillIndex >=0 && enemy->chosenSkillIndex < enemy->skillSet->getSkillCount()){
      cout<<enemy->skillSet->skills[enemy->chosenSkillIndex]->skillName<<endl;
    }
    else{
      cout<<"None"<<endl;
    }
    cout<<"------------------------"<<endl;
  }
}
void CombatScene::skillAndTarget(){
  // for each unit, have them select skill and target
  for(int i=0; i<enemyCount; i++){
    Unit* unit = enemies[i];
    int skillIndex = unit->selectSkill();
    int targetIndex = rand() % playerCount;
    unit->setTarget(targetIndex);
    Unit* target = players[targetIndex];
    cout<<unit->name<<" selects skill "<<unit->skillSet->skills[skillIndex]->skillName<<" targeting "<<target->name<<"!"<<endl;
  }
  for(int i=0; i<playerCount; i++){
    Unit* unit = players[i];
    int skillIndex = unit->selectSkill();
    Unit* target = unit->chooseTarget(enemies, enemyCount);
    cout<<unit->name<<" selects skill "<<unit->skillSet->skills[skillIndex]->skillName<<" targeting "<<target->name<<"!"<<endl;
  }

}
