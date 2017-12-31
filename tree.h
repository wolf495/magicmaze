#ifndef TREE
#define TREE
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
#include "Treend.h"


/*
   Name: Alfredo Soto
   date: 11/11/2017
   desc: trees trees trees. Makes a tree, and destroys it. Isn't that analogous to mankind? To create trees, crops, and other resources
         for our own needs, and to destroy them in the process. Food for thought. THE MORE YOU KNOW!
                                                                                                                        .
                                              .         ;  
                 .              .              ;%     ;;   
                   ,           ,                :;%  %;   
                    :         ;                   :;%;'     .,   
           ,.        %;     %;            ;        %;'    ,;
             ;       ;%;  %%;        ,     %;    ;%;    ,%'
              %;       %;%;      ,  ;       %;  ;%;   ,%;' 
               ;%;      %;        ;%;        % ;%;  ,%;'
                `%;.     ;%;     %;'         `;%%;.%;'
                 `:;%.    ;%%. %@;        %; ;@%;%'
                    `:%;.  :;bd%;          %;@%;'
                      `@%:.  :;%.         ;@@%;'   
                        `@%.  `;@%.      ;@@%;         
                          `@%%. `@%%    ;@@%;        
                            ;@%. :@%%  %@@%;       
                              %@bd%%%bd%%:;     
                                #@%%%%%:;;
                                %@@%%%::;
                                %@@@%(o);  . '         
                                %@@@o%;:(.,'         
                            `.. %@@@o%::;         
                               `)@@@o%::;         
                                %@@(o)::;        
                               .%@@@@%::;         
                               ;%@@@@%::;.          
                              ;%@@@@%%:;;;. 
                          ...;%@@@@@%%:;;;;,..    Gilo97
*/
template<class ItemType>
class TreeType
{

   public:
      TreeType();//sets initial NODE to NULL
      TreeType (const TreeType &original){CopyTree(root, original.root);}//constructor that copies from another tree
      void operator=(TreeType &orginalTree);//lets you compare Trees for equality
      bool Search(ItemType &value);//Search a tree for a sepcific value
      bool Insert(ItemType value);//Insert a value into a tree
      void Print() ;//prints whole tree in order
     ~TreeType();//deconstructor 
      bool isEmpty() {return root==0;}//checks if root is empty
      bool DeleteItem(ItemType value);//deletes a value from the tree
      ItemType getCurrentData(){return current->data;}
      void moveCurrentLeft();
      void moveCurrentRight();
      void setCurrentToRoot();
      void PrintCurrent();
      bool DeadEnd();
      void options();
      bool checkSide(string);


   private:
      TreeNode<ItemType>* root;//points to current node in tree
      void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* original);//copies a tree into another tree
      //void Insert(ItemType item);
      bool BinarySearch(TreeNode<ItemType>* root, ItemType &value);//Searches thru tree binarily <-- is that even a word?
      bool InsertItem(TreeNode<ItemType>*&  root, ItemType value);//inserts a value into root, calls other INSERT function once find specific node
      void PrintTree(TreeNode<ItemType>* root);//traverses the root to print each node, called by other PRINT function
      void Destroy(TreeNode<ItemType>*& root);//Destroys each node of the tree, calls DELETE on each side of the tree
      bool Delete(TreeNode<ItemType>*& root, ItemType);//deletes a sepcific node in the tree, once it finds the specific node, will call DELETE ITEM
      void FindMax(TreeNode<ItemType>* root, ItemType &data);//Finds the largest number
      TreeNode<ItemType>* current;


};

#include "tree.cpp"
#endif
