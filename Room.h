#ifndef ROOMH
#define ROOMH
#include <string>
#include <iostream>
using namespace std;

class Room
{
   public:
   bool operator<(Room &original);//used by tree.cpp
   bool operator>=(Room &original);//used by tree.cpp
   friend ostream &operator<<( ostream &output, const Room &D );//used by tree.cpp
   Room();//default constructor, sets privates to "Blank" and 0
   Room(string first,string last,int rando,int rando2);//paramaterized constructor: sets firstname, lastname, reward,a, and b to parameters based on what type of room is being constructed
   string getFirstname();//returns firstname
   string getLastname();//returns lastname
   int getReward();//returns reward
   int getA();//returns a
   int getB();//returns b
   string setFirstname(string);//sets firstname to string
   string setLastname(string);//sets lastname to string
   int setReward(int);//sets reward to int
   int setA(int);//sets a to int
   int setB(int);//sets b to int
   void printinfo(char type,int sum);//prints info on if you lose or gain money based on room type
   char getType();//returns a char based on room type
   private:
   string firstname;
   string lastname;
   int reward;
   int a;
   int b;
};
#endif
