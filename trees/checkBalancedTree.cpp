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
    node* n=new node(d);
    n->left=buildTree();
    n->right=buildTree();
    return n;
}


void printLevelOrder(node* root){
    queue<node *>q;
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
    
    return ;
}


int findHeight(node* root){
    if(root==NULL){
        return 0;
    }
    int h1=findHeight(root->left);
    int h2=findHeight(root->right);
    return max(h1,h2)+1;

}




pair<int,bool> checkBalance(node* root){
    pair<int,bool> p;
    if(root==NULL){
        p.first=0;
        p.second=true;
    }
    else{
        auto p1=checkBalance(root->left);
        auto p2=checkBalance(root->right);
        if(abs(p1.first-p2.first)<=1 and p1.second and p2.second){
            p.second=true;
        }
        else{
            p.second=false;
        }
        
        p.first=findHeight(root);
        
        
    }
    return p;
    
}




int main(){
    node* root=buildTree();
    printLevelOrder(root);
    auto p=checkBalance(root);
    if(p.second){
        cout<<"the tree is height balanced"<<endl;
    }
    else{
        cout<<"The tree is not height balanced"<<endl;
    }
}