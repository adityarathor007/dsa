//leaf nodes should be kept entact
#include <iostream>
#include <queue>
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
    else{
        node* n=new node(d);
        n->left=buildTree();
        n->right=buildTree();
        return n;
        
    }
}

void printLevelOrder(node* root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        
        }
        
       
    }
     return ;
    
    
}

int replaceWithSum(node* root){
    if(root==NULL){
        return 0;
    }
    
    if(root->left==NULL and root->right==NULL){
        // cout<<"reached leaf node"<<endl;
        // cout<<root->data<<endl;
        return root->data;
    }
    
    
    int temp=root->data;
    int left_sum =replaceWithSum(root->left);
    int right_sum=replaceWithSum(root->right);

    root->data=left_sum+right_sum;
    return temp+root->data;
    
    
}





int main(){
    node * root=buildTree();
    printLevelOrder(root);
    replaceWithSum(root);
    printLevelOrder(root);
}