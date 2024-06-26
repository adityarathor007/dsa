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



Node* findLCA(Node* root,int a,int b){
    if((a<root->key and b>root->key) or(a>root->key and b<root->key)){
        return root;
    }
    Node* l;
    if(a<root->key and b<root->key){
        l=findLCA(root->left, a, b);
    }
    else if(a>root->key and b>root->key){
        l=findLCA(root->right, a, b);
    }
    else if(a==root->key or b==root->key){
        l=root;
    }
    return l;
}