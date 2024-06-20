#include <iostream>
#include <queue>
#include <sys/wait.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* n=new node(d);
    n->left=buildTree();
    n->right=buildTree();
    
    return n;
    
}


void printLevelOrder(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
        }
        
    }
    return;
    
}


void printKthLevelNode(node* root,int k){
    if(root==NULL){  //who knows that left node is null
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
        return ;
    }
    
    printKthLevelNode(root->left,k-1);
    printKthLevelNode(root->right,k-1);
    
    
    return;
    
}




int main(){
    node* root=buildTree();
    printLevelOrder(root);
    int k=2;
    printKthLevelNode(root,k);
}