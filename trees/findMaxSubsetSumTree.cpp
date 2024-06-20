//the important condition we have to ensure here is that whatever node we consider for the subset then the parent and its child are not included

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

pair <int,int> findMaxSubsetTree(node* root){
    pair<int,int> p;
    if(root==NULL){
        p.first=0;
        p.second=0;
    }
    else{
        pair<int,int>  p1=findMaxSubsetTree(root->left);
        pair<int,int>  p2=findMaxSubsetTree(root->right);
        //considering the inc root sum
        p.first=root->data+p1.second+p2.second;
        //considering the exc root sum
        p.second=max(p1.first,p1.second)+max(p2.first,p2.second);
        
    }
    
    return p;
}



int main(){
    node* root=buildTree();
    printLevelOrder(root);
    auto p=findMaxSubsetTree(root);
    cout<<max(p.first,p.second)<<endl;  //to find the max if root include and root not include
}