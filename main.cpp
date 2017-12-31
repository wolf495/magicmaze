#include <fstream>
#include <iostream>
#include <string>
#include "Room.h"
#include "tree.h"
#include "Girl.h"
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <sstream>
using namespace std;
/*
Name: Alfredo Soto
Date: 12/4/17
CopyRight ©
CPSC 340

DESC: A minigame where user traverses a binary tree (tree.cpp/tree.h/Treend.h) using a girl object (Girl.cpp/Girl.h),
        created with info from 'input.txt' to make rooms (Room.cpp/Room.h). The tree has rooms for nodes, and if the room
        has an elf, it adds money to the Girl object, if its monster it removes money form Girl. The game ends if girl has
        no money left, has reached a tree.DeadEnd(), or reached a wizard who multiplys the Girl's money.
        Statistics of rooms are shown at end of game.
        
Structure:
        [start program]
        do(while wants to play)
            do(while error opening file)
                if(no error with argument) <--(first iteration)
                    try to open
                    construct maze, and girl
                if(error opening with argument)
                    reprompt for filename
                    try to open
                    construct maze, and girl
            print GAME RULES
            call girl.NextMove
        [end program]
            
*/
int main(int argc, char *argv[]){
cout<<"-----------------------Starting Alfredo's Magic Maze-----------------------\n";
    string input;
    srand (time(NULL));
    int out;
    int out2;
    bool broke=false;
    TreeType <Room> maze;
            int starting=0;
            Girl girl;
            string tempFirst;
            string templast;
do{
    do{
        if(!broke){
            cout<<"{reading file...}\n";
            if(argc != 2){
                cout<<"PLEASE TYPE ARGUMENT: "<< argv[0]<<" <filename>\n";broke=true;
    }
            else{
                ifstream the_file(argv[1]);
                if(!the_file.is_open()){
                cout<<"Could not open file\n";broke=true;
                }
                else{
        cout<<"{creating tree...}\n";
                    string x;
                    while(the_file>>x){
                        if(x=="start"){
                            out=rand()%30+5;
                            out2=rand()%30+5;
                            Room tempRoom(x,"point",out,out2);
                            maze.Insert(tempRoom);
                            the_file>>x;
                            istringstream convert(x);
                            if ( !(convert >> starting) ){starting = 0;}
                            girl.RewardInit(starting);
                        }
                        else{
                            tempFirst=x;the_file>>x;
                            templast=x;
                            if(templast=="monster"||templast=="elf"){out=rand()%30+5;out2=rand()%30+5;}
                            else{out=rand()%10+1;out2=rand()%10+1;}
                            Room tempRoom(tempFirst,templast,out,out2);
                            maze.Insert(tempRoom);
                        }
                    }
                }
    }
        }
        else{
            cout<<"Could Not Start Normally. Please try typing the correct Filename\n";
            cin>>input;
            system("clear");
             ifstream the_file(input);
                if(!the_file.is_open()){
                cout<<"Could not open file\n";broke=true;
                }
                else{
        cout<<"{creating tree...}\n";
                    string x;
                    while(the_file>>x){
                        if(x=="start"){
                            out=rand()%30+5;
                            out2=rand()%30+5;
                            Room tempRoom(x,"point",out,out2);
                            maze.Insert(tempRoom);
                            the_file>>x;
                            istringstream convert(x);
                            if ( !(convert >> starting) ){starting = 0;}
                            girl.RewardInit(starting);
                        }
                        else{
                            tempFirst=x;the_file>>x;
                            templast=x;
                            if(templast=="monster"||templast=="elf"){out=rand()%30+5;out2=rand()%30+5;}
                            else{out=rand()%10+1;out2=rand()%10+1;}
                            Room tempRoom(tempFirst,templast,out,out2);
                            maze.Insert(tempRoom);
                        }
                    }
                broke=false;
                }
        }
    }while(broke);
    
     if(!broke){cout<<"{(DONE) reading file...}\n";
        cout<<"{(DONE) creating tree...}\n\n\n"; }else{cout<<"ERROR!\n";}   
    
    cout<<"[THE GAME]\nYou are a little girl, for some reason. Your parents apparently do not supervise you, and you wander into some random maze with magical creatures.";
    cout<<"\navoid monsters, and search for a wizard. Elfs will help you along the way.Oh and also for some reason you have gold. Figure the rest out.\n\n\n";
    
    do{cout<<"[continue?] (y)\n";
    cin>>input;
    }while(input!="y");
    maze.setCurrentToRoot();
    maze.PrintCurrent();
    system("clear");
    cin.ignore();
    girl.NextMove(maze);
    cout<<"\tType (y) to play again, or (any key) to quit\n";
    cin>>input;
    system("clear");
}while(input=="y");
cout<<"-----------------------Exiting Alfredo's Magic Maze-----------------------\n";

    return 0;
}