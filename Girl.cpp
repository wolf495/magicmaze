#ifndef GIRLCPP
#define GIRLCPP
#include "Girl.h"
#include "Room.h"
#include "tree.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

    Girl::Girl(){
        totalGold=0;
        roomCount=0;
        elfRoomCount=0;
        wizardRoomCount=0;
        monsterRoomCount=0;
        gameOver=false;
    }
    void Girl::RewardInit(int start){totalGold=start;}
    void Girl::Reward(Room room){
        char type=room.getType();
        if(type=='e'){
            totalGold=totalGold+room.getReward();
        }
        else if(type=='m'){
            totalGold=totalGold-room.getReward();
        }
        else if(type=='w'){
            totalGold=(totalGold*room.getA())+room.getB();
        }
        else{totalGold=-2;}
    }
    bool Girl::GameOver(TreeType <Room> &maze){
        if(totalGold<=0){gameOver=true;}
        else if(wizardRoomCount==1){gameOver=true;}
        else if(maze.DeadEnd()){gameOver=true;}
        return gameOver;
    }
    void Girl::NextMove(TreeType <Room> &maze){
//-----------------------------------------------------------------------------------------------------------------
    string input="";
    cout<<"\n--Status--\n\tRoom Count: "<<roomCount<<"\n\tCurrent Room: ";maze.PrintCurrent();cout<<"\t";PrintGirlStatus();cout<<"\n----------\n";
        while(!gameOver){
        //while(input!="left"||input!="right"){
        cout<<"What path shall you take? ";maze.options();
        getline(cin,input);
        system("clear");
        if(input=="left"&&maze.checkSide(input)){
            maze.moveCurrentLeft();
            Room temp=maze.getCurrentData();
            if(temp.getType()=='m'){
                roomCount++;
                monsterRoomCount++;
                temp.printinfo(temp.getType(),totalGold);
                Reward(temp);
            }
            else if(temp.getType()=='e'){
                roomCount++;
                elfRoomCount++;
                temp.printinfo(temp.getType(),totalGold);
                Reward(temp);
            }
            else if(temp.getType()=='w'){
                roomCount++;
                wizardRoomCount++;
                temp.printinfo(temp.getType(),totalGold);
                Reward(temp);
            }
            gameOver=GameOver(maze);
            //break;
        }
        else if(input=="right"&&maze.checkSide(input)){
            maze.moveCurrentRight();
            Room temp=maze.getCurrentData();
            if(temp.getType()=='m'){
                roomCount++;
                monsterRoomCount++;
                temp.printinfo(temp.getType(),totalGold);
                Reward(temp);
            }
            else if(temp.getType()=='e'){
                roomCount++;
                elfRoomCount++;
                temp.printinfo(temp.getType(),totalGold);
                Reward(temp);
            }
            else if(temp.getType()=='w'){
                roomCount++;
                wizardRoomCount++;
                temp.printinfo(temp.getType(),totalGold);
                Reward(temp);
            }
            gameOver=GameOver(maze);
            //break;
        }
        else{
            cout<<"Incorrect Option\n";
        }
        //}
    
    cout<<"\n--Status--\n\tRoom Count: "<<roomCount<<"\n\tCurrent Room: ";maze.PrintCurrent();cout<<"\t";PrintGirlStatus();cout<<"\n----------\n";
    //maze.PrintCurrent();
    input="z";
    }
//-----------------------------------------------------------------------------------------------------------------
    if(gameOver){cout<<"--Room Stats--\n\tElf Count: "<<elfRoomCount<<"\n\tMonster Count: "<<monsterRoomCount<<"\n----------\n";}
    if(wizardRoomCount!=1){cout<<"You failed to find a wizard. You lose.\n";}
    else{cout<<"Yippy! You found a wizard.\n";}
        
    }
    void Girl::PrintGirlStatus(){
        cout<<"Gold Left: "<<totalGold;
    }

#endif

