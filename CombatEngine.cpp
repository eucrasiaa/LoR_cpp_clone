// combat engine for now will handle the passing of a turn state and then resolving actions
// 
// turn state comprised of:
// // - list of units (player)
// //     - player units targeting
// //     - player units actions
// // - list of units (enemy)
//

// // - enemy units targeting
// // - enemy units actions
#include "CombatEngine.h"
// CombatEngine::CombatEngine(int playerUnitCount, int enemyUnitCount): playerUnitCount(playerUnitCount), enemyUnitCount(enemyUnitCount){};

CombatEngine::CombatEngine(CombatScene* scene){
  // link to combat scene
  this->scene = scene;
}


int CombatEngine::validatePreTurn(){
  // ensure all units have a valid selected skill and target
  // return 0 if all valid, else return error code
  return 0;
}

void CombatEngine::ResolveCombatOrder(){
  // process the combat order for the turn
  // go through each unit, and if its target has a lower speed, they clash and its target is set to the unit attacking it 
  int playerCount = scene->getPlayerCount();
  int enemyCount = scene->getEnemyCount();
  Unit* speedOrder[playerCount + enemyCount];
  int index = 0;
  // gather all units into speedOrder array
  for(int i=0; i<playerCount; i++){
    speedOrder[index++] = scene->players[i];
  }
  for(int i=0; i<enemyCount; i++){
    speedOrder[index++] = scene->enemies[i];
  }
  // sort speedOrder by currentSpeed descending
  // simple bubble sort for now
  for(int i=0; i<playerCount + enemyCount - 1; i++){
    for(int j=0; j<playerCount + enemyCount - i - 1; j++){
      if(speedOrder[j]->currentSpeed < speedOrder[j+1]->currentSpeed){
        Unit* temp = speedOrder[j];
        speedOrder[j] = speedOrder[j+1];
        speedOrder[j+1] = temp;
      }
    }
  }
  // TODO draw clash aggro stuff 
  //
}
