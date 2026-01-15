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
CombatEngine::CombatEngine(int playerUnitCount, int enemyUnitCount): playerUnitCount(playerUnitCount), enemyUnitCount(enemyUnitCount){};
