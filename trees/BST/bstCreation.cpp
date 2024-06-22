#include <cmath>
#include<iostream>
using namespace std;


class Node{
    public:
        int key;
        Node* left;
        Node* right;
        
        Node(int k){
            key=k;
            left=NULL;
            right=NULL;
        }
};

Node* insert(Node* root,int k){
    if(root==NULL){
        return new Node(k);
    }
    if(k<=root->key){
        root->left=insert(root->left,k);
    }
    else{
        root->right=insert(root->right,k);
    }
    return root;
    
}

void printInOrder(Node* root){
    if(root==NULL){
        return ;
    }
    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);
    return;
}



bool isPresent(Node* root,int key){
    if(root==NULL){
        return false;
    }
    
    
    else{
        if(root->key==key){
            return true;
        }
    
    
    
        else if(root->key>=key){
            bool a=isPresent(root->left,key);
            if(a){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            bool a=isPresent(root->right,key);
            if(a){
                return true;
            }
            else{
                return false;
            }
        } 
    }
    
    
    
}


int main(){
    Node* root=NULL;
    int arr[]={8,3,10,1,6,14,4,7,13};
    
    for(int x:arr){
        root=insert(root,x);
    }
    // printInOrder(root);
    // cout<<endl;
    
    if(search(root,2)){
        cout<<"the key is present"<<endl;
    }
    else{
        cout<<"key not present"<<endl;
    }
 
    
}