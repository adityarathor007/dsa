#include <cstddef>
#include <iostream>
using namespace std;

class Node{
    public:
        int key;
        Node* left;
        Node* right;
        Node* parent;
        
        Node(int k){
            key=k;
            left=NULL;
            right=NULL;
        }
};



Node* findInOrderSuccessor( Node *inputNode ){
    //Complete this Method, return the pointer to the inorder successor
    // HINT : Since the parent pointer is given, you can traverse upwards in the tree
    Node* succ;
    if(inputNode->right){
        succ=inputNode->right;
        while(succ->left!=NULL){
            succ=succ->left;
        }
       
    }
    else if(inputNode->parent){
        succ=inputNode->parent;
        while(succ!=NULL && succ->right==inputNode){
            succ=succ->parent;
        }
    }
    return succ;
    
    
    
}