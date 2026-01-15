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

int CombatEngine::validatePreTurn(){
  // ensure all units have a valid selected skill and target
  // return 0 if all valid, else return error code
  return 0;
}
