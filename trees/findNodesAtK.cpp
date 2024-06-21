#include <iostream>
using namespace std;

class node{
  public:
     int data;
     node *left;
     node *right;
     
     node(int d){
         data=d;
         left=NULL;
         right-NULL;
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
}

void downTraverseK(node* root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
    }
    downTraverseK(root->left, k-1);
    downTraverseK(root->right, k-1);

}




int findNodesAtK(node* root,node* target,int k){
    if(root==NULL){
        return -1;
    }
    
    
    //react the target node
    if(root==target){
        downTraverseK(root,k);
        return 0;

    }
    
    
    //other cases
    int DL=findNodesAtK(root->left,target,k);
    if(DL!=-1){
        if(DL+1==k){
            cout<<root->data<<endl;
        }
        else{
            downTraverseK(root->right, k-DL-2);
        }
        return DL+1;
    }
    
    int DR=findNodesAtK(root->right,target,k);
    if(DR!=-1){
        if(DR+1==k){
            cout<<root->data<<endl;
        }
        else{
            downTraverseK(root->right, k-DR-2);
        }
        return DR+1;
    }
    
    return -1;
}




int main(){
    node* root=buildTree();
    
}