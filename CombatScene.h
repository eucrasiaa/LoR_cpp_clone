#pragma once

#include "Unit.h"
class CombatScene {
  public:
    Unit** players;
    int playerCount;
    Unit** enemies;
    int enemyCount;
    int turnNumber = 0;
    // can i setup the constructor to take a variable num
    
    CombatScene(){
      turnNumber = 0;
      playerCount = 0;
      enemyCount = 0;
      players = nullptr;
      enemies = nullptr;
    }
    // can these take a list of units instead? like Unit, Unit, Unit... 
    // use variadic templates?
    void LoadPlayers(std::initializer_list<Unit*> playerList);
    void LoadEnemies(std::initializer_list<Unit*> enemyList);
    // CombatScene(Unit** players, int playerCount, Unit** enemies, int enemyCount)
    //   : players(players), playerCount(playerCount), enemies(enemies), enemyCount(enemyCount) {};
    int getTurnNumber(){ return turnNumber; }
    int getPlayerCount(){ return playerCount; }
    int getEnemyCount(){ return enemyCount; }

    void displayCombatants();
    void startCombat();
    ~CombatScene(){
      delete[] players;
      delete[] enemies;
    }
};
