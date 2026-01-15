// main, includes unit + skillset (which include all their own requiered elements)
//

#include <iostream>
#include "Unit.h"
#include "devFunctions.h"
#include "CombatScene.h"

int main(){
  cout<<"Starting SkillSet Test"<<endl;
  Unit *testUnit = new Unit("PlayerUnit", 100, 50, 10, 20, PLAYER);
  testUnit->inheritSkillSet(genDemoSkillSet_1());
 
  testUnit->displayUnitInfo();
  DrawLine(1, 34); // blue line
  Unit *enemyUnit = new Unit("EnemyUnit", 80, 40, 5, 15, ENEMY);
  enemyUnit->inheritSkillSet(genDemoSkillSet_2());
  enemyUnit->displayUnitInfo();
  DrawLine(1, 34); // blue line
  
  // set up combat scene with both units
  CombatScene* devScene = new CombatScene();
  devScene->LoadPlayers({testUnit});
  devScene->LoadEnemies({enemyUnit});
  devScene->startCombat();

  delete devScene;
  
  delete testUnit;
  delete enemyUnit;

  cout<<"Ending SkillSet Test"<<endl;
  return 0;
}

