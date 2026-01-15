#include "CombatScene.h"


CombatScene::CombatScene()
    : turnNumber(0), playerCount(0), enemyCount(0), players(nullptr), enemies(nullptr), engine(new CombatEngine(this)) {
}
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
    displayEnemyPreTurn(); 
    int skillIndex = unit->selectSkill();
    int targetIndex = -1;
    while(targetIndex < 0 || targetIndex >= enemyCount){
      cout<<"Select a target for "<<unit->name<<" (1 - "<<enemyCount<<"): ";
      cin>>targetIndex;
      targetIndex -= 1; // adjust for 0-based index
      if(targetIndex < 0 || targetIndex >= enemyCount){
        cout<<"Invalid target, please try again."<<endl;
      }
      else{
        unit->setTarget(targetIndex);
        Unit* target = enemies[targetIndex];
        cout<<unit->name<<" selects skill "<<unit->skillSet->skills[skillIndex]->skillName<<" targeting "<<target->name<<"!"<<endl;
      }
    }


  }
}

int CombatScene::preDamageValidate(){
  // validate all units have a skill and target selected
  for(int i=0; i<enemyCount; i++){
    Unit* unit = enemies[i];
    if(unit->chosenSkillIndex < 0 || unit->chosenSkillIndex >= unit->skillSet->getSkillCount()){
      cout<<"Enemy unit "<<unit->name<<" has invalid skill selection!"<<endl;
      return -1;
    }
    if(unit->targetedUnitIndex < 0 || unit->targetedUnitIndex >= playerCount){
      cout<<"Enemy unit "<<unit->name<<" has invalid target selection!"<<endl;
      return -2;
    }
  }
  for(int i=0; i<playerCount; i++){
    Unit* unit = players[i];
    if(unit->chosenSkillIndex < 0 || unit->chosenSkillIndex >= unit->skillSet->getSkillCount()){
      cout<<"Player unit "<<unit->name<<" has invalid skill selection!"<<endl;
      return -3;
    }
    if(unit->targetedUnitIndex < 0 || unit->targetedUnitIndex >= enemyCount){
      cout<<"Player unit "<<unit->name<<" has invalid target selection!"<<endl;
      return -4;
    }
  }
  return 0; // all good
}
void CombatScene::combatStep(){
  //wrapper for a full combat turn 
  turnNumber++;
  cout<<"--- Combat Turn "<<turnNumber<<" ---"<<endl;
  skillAndTarget();

  //validate all units have a skill and target selected
  int res = preDamageValidate();
  if(res != 0){
    cout<<"Pre-damage validation failed with code "<<res<<", aborting combat step."<<endl;
    return;
  }
  // handles clashes and damages, hand off to engine

  // for now, just display combatants at start of turnNumbe/
}
