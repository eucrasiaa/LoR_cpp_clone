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
