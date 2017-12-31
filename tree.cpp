#include "tree.h"
#include <string>
#ifndef TREE_CPP
#define TREE_CPP

template<class ItemType>
void TreeType<ItemType>::operator=(TreeType<ItemType> &original)
{
        if(original == this)
                return; //ignore assigning self to self
        Destroy(root);
        CopyTree(root, original.root);
}


template<class ItemType>
void TreeType<ItemType>::CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* original)
{
     if(original!=NULL){
        copy=new TreeNode<ItemType>;
        copy->data=original->data;
        CopyTree(copy->left,original->left);
        CopyTree(copy->right,original->right);
    }
}



template<class ItemType>
TreeType<ItemType>::~TreeType()
{
   Destroy(root);
}


template <class ItemType>
void TreeType<ItemType>::Destroy(TreeNode<ItemType>*& root)
{
    if(root!=NULL){
    Destroy(root->left);
    Destroy(root->right);
    delete root;
    }
}

template <class ItemType>
TreeType<ItemType>::TreeType()
{
   root = NULL;
}
template<class ItemType>
bool TreeType<ItemType>::Insert(ItemType item)
{
   // cout<<"Insert:";
   return InsertItem(root, item);
}


template<class ItemType>
bool TreeType<ItemType>::InsertItem(TreeNode<ItemType>*& root, ItemType value)
{
    if(root==NULL){
    root=new TreeNode<ItemType>;
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    return true;
    }
    else if(value<root->data){
    return(InsertItem(root->right,value));
    }
    else if(value>= root->data){
    return(InsertItem(root->left,value));
    }
    return false;
}


template<class ItemType>
void TreeType<ItemType>::Print()
{
   PrintTree(root);

}


template <class ItemType>
void TreeType<ItemType>::PrintTree(TreeNode<ItemType>* root)
{
     if(root!=NULL){
        PrintTree(root->left);
        cout<<root->data<<" \n";
        PrintTree(root->right);
    }
    else if(root==NULL){}//nothing
}

template<class ItemType>
bool TreeType<ItemType>::DeleteItem(ItemType item)
{
   return Delete(root, item);
}


template<class ItemType>
void TreeType<ItemType>::FindMax(TreeNode <ItemType>* root, ItemType &data)
{
    while(root->right!=NULL){
                root=root->right;
            }
            data=root->data;
}

template<class ItemType>
bool TreeType<ItemType>::Delete(TreeNode<ItemType>*& root, ItemType item)
{
    if(root==NULL){
        return false;
    }
    else if(item<root->data){
        return Delete(root->left,item);
    }
    else if(item> root ->data){
        return Delete(root->right,item);
    }
    else{
         if(root->left==NULL&&root->right==NULL){
        item=root->data;
        delete root;
        root=NULL;
             return true;
         }
        if(root->left&&root->right==NULL){
            item=root->data;
            TreeNode<ItemType> *temp=root;   //(fill pointer in)
            root=root->left;
            delete temp;
            return true;
        }
        if(root->left==NULL&&root->right){
            item = root->data;
            TreeNode<ItemType> *temp=root; 
            temp=root;
            root=root->right;
            delete temp;
            return true;
        }
        if(root->right&&root->left){
            item=root->data;
            FindMax(root->left, root->data);
            Delete(root->left,root->data);
        }
    //need to find the greatest node in left subtree OR need to find least node in right subtree
    //reassign node to foundNode
    //call REMOVE for foundNode
        
        
//OR NOT FOUND
    }return false;
}

    template<class ItemType>
    void TreeType<ItemType>::moveCurrentLeft(){
        if(root->left!=NULL){
        root=root->left;
        setCurrentToRoot();}
    }
    
    template<class ItemType>
    void TreeType<ItemType>::moveCurrentRight(){
        if(root->right!=NULL){
        root=root->right;
        setCurrentToRoot();}
    }
    
    template<class ItemType>
    void TreeType<ItemType>::setCurrentToRoot(){
        //(root!=NULL){current->data=root->data;}
        current=root;
        
    }
    
    template<class ItemType>
    void TreeType<ItemType>::PrintCurrent(){
        cout<<current->data<<endl;
    }
    
    template<class ItemType>
    bool TreeType<ItemType>::DeadEnd(){
        return (root->left==NULL && root->right==NULL);
    }
    
    template<class ItemType>
    void TreeType<ItemType>::options(){
        string out="(";
        if(root->left!=NULL&&root->right==NULL){out+="left";}
        else if(root->left!=NULL&&root->right!=NULL){out+="left,right";}
        else if(root->left==NULL&&root->right!=NULL){out+="right";}
        out+=")";
        cout<<out;
    }
    
    template<class ItemType>
    bool TreeType<ItemType>::checkSide(string side){
        bool valid=true;
        if(side=="left"){
            if(root->left==NULL){valid=false;}
        }
        else if(side=="right"){
            if(root->right==NULL){valid=false;}
        }
        return valid;
    }
    
    


#endif

