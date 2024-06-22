//given sorted array and if you insert using the normal insert function then it will give a skewed tree


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


Node * insert(int arr[],Node* root,int s,int e){
    if(s<=e){
        int mid=(s+e)/2;
        
        root=new Node(arr[mid]);
        
        root->left=insert(arr,root->left,s,mid-1);
        root->right=insert(arr,root->right,mid+1,e);
    }
    return root;
    
}

void printInOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    printInOrderTraversal(root->left);
    cout<<root->key<<" ";
    printInOrderTraversal(root->right);
    
    return ;
}


int main(){
    Node* root=NULL;
    int n=7;
    int arr[]={1,2,3,4,5,6,7};
    root=insert(arr,root,0,n-1);
    printInOrderTraversal(root);
    cout<<endl;
}