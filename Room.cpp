#ifndef ROOMCPP
#define ROOMCPP
#include "Room.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <climits>
using namespace std;

bool Room::operator<(Room &original){
        if(original.getFirstname() < getFirstname())
                return true;
        else    return false;
}
bool Room::operator>=(Room &original){
        if(original.getFirstname() >= getFirstname())
                return true;
        else    return false;
}
ostream &operator<<( ostream &output, const Room &D ) { 
         output <<"["<< D.firstname <<" "<< D.lastname<<"]";
         return output;            
      }

    Room::Room(){
        firstname="blank";
        lastname="blank";
        reward=0;
        a=0;
        b=0;
    }
    Room::Room(string first,string last,int rando,int rando2){
        firstname=first;
        lastname=last;
        if(lastname=="monster"){
            int monster=rando;//randomNum('m');
            reward=monster;
            a=-1;
            b=-1;}
        else if(lastname=="elf"){
            int elf=rando;//randomNum('e');
            reward=elf;
            a=-1;
            b=-1;}
        else if(lastname=="wizard"){
            reward=-1;
            a=rando;
            b=rando2;}
    }
    string Room::getFirstname(){return firstname;}
    string Room::getLastname(){return lastname;}
    int Room::getReward(){return reward;}
    int Room::getA(){return a;}
    int Room::getB(){return b;}
    string Room::setFirstname(string newfirst){firstname=newfirst;}
    string Room::setLastname(string newlast){lastname=newlast;}
    int Room::setReward(int newreward){reward=newreward;}
    int Room::setA(int newa){a=newa;}
    int Room::setB(int newb){b=newb;}
    void Room::printinfo(char type, int girlSum){
        if(type=='e'){
            cout<<"You find a "<<firstname<<" "<<lastname<<" and it bestows "<<reward<<" gold to you.\n";
        }
        else if(type=='m'){
            cout<<"You find a "<<firstname<<" "<<lastname<<" and it steals "<<reward<<" gold from you.\n";
        }
        else if(type=='w'){
            cout<<"You find a "<<firstname<<" "<<lastname<<" and it uses the magic multiplier "<<a<<" x "<<girlSum<<" + "<<b<<" on your gold!\n";
        }
        else{
            cout<<"invalid room type\n";
        }
    }
    char Room::getType(){char c=lastname.at(0);return c;}

#endif

