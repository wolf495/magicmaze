#ifndef GIRLH
#define GIRLH
#include "Room.h"
#include "tree.h"
#include <string>
#include <iostream>
using namespace std;

class Girl
{
   public:
   Girl();//constructs Girl; sets all privates to 0 and false
   void RewardInit(int start);//sets TotalGold=start 
   void Reward(Room);//Calculates new TotalGold based on what type of ROOM is passed (type: e/m/w)
   bool GameOver(TreeType <Room> &maze);//checks if wizardCount==1,gold<=0, or Current Node is a DeadEnd()
   void NextMove(TreeType <Room> &maze);//Main method for prompting user Input until GameOver()
   void PrintGirlStatus();//Prints TotalGold

   private:
   int roomCount;
   int elfRoomCount;
   int wizardRoomCount;
   int monsterRoomCount;
   int totalGold;
   bool gameOver;
};
#endif
