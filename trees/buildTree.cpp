#include<iostream>
#include <queue>
#include <vector>
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

//pre-order Traversal(stack implementation)
node * buildTree(){
    
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


// the output will be in the form of level order print
void levelOrderPrint(node* root){
    queue<node*> q; //it is important that q contains node pointer
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        
        if(temp!=NULL){
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
           
        }
        else{
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
                
            }
            
            
            
        }
        
        
    }
    
    return ;
    
    
}


node * buildLevelOrder(){
    int d;
    cin>>d;
    
    node* root=new node(d);
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        node* current=q.front();
        q.pop();  //popping the node which is the root and whose child will be intialized
        
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            current->left=new node(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right=new node(c2);
            q.push(current->right);
        }
        
        
    }
    
    
    return root;
}




int main(){
    // node* root=buildTree();
    
    node * root= buildLevelOrder(); //using input in the form of level order
    
    
    levelOrderPrint(root);
    
    return 0;
    
    
}