#pragma once

#include "Unit.h"
#include "CombatEngine.h"

class CombatScene {
  public:
    Unit** players;
    int playerCount;
    Unit** enemies;
    int enemyCount;
    int turnNumber = 0;
    // can i setup the constructor to take a variable num
    CombatEngine *engine;

    CombatScene();
    // can these take a list of units instead? like Unit, Unit, Unit... 
    // use variadic templates?
    void LoadPlayers(std::initializer_list<Unit*> playerList);
    void LoadEnemies(std::initializer_list<Unit*> enemyList);
    // CombatScene(Unit** players, int playerCount, Unit** enemies, int enemyCount)
    //   : players(players), playerCount(playerCount), enemies(enemies), enemyCount(enemyCount) {};
    int getTurnNumber(){ return turnNumber; }
    int getPlayerCount(){ return playerCount; }
    int getEnemyCount(){ return enemyCount; }
   
    void displayEnemyPreTurn();
    void combatStep();

    void displayCombatants();
    void startCombat();
    void skillAndTarget();

    int preDamageValidate();
    ~CombatScene(){
      delete[] players;
      delete[] enemies;
      delete engine;
    }
    
};
