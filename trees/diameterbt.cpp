#include <iostream>
#include <queue>
#include <algorithm>
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
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* current=q.front();
        if(current==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<current->data<<" ";
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
       
    }
    return;
    
}

//finding the height of the tree which is the number of nodes in a given direction
int height(node * root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return max(h1,h2)+1;
    
};


// int diameter(node* root){
//     //base case
//     if(root==NULL){
//         return 0;
//     }
    
//     //rec case
//     int D1=height(root->left)+height(root->right);
//     int D2=diameter(root->left);
//     int D3=diameter(root->right);
    
//     int ans=max(D1,max(D2,D3));
//     return ans ;
    
    
// }


//-----Diameter Optimised
class HDPair{
    public:
        int height;
        int diameter;
};


HDPair optDiameter(node* root){
    HDPair p;
        
    if(root==NULL){
            p.height=p.diameter=0;
            return p;
    }
        
        
        //otherwise
        
        HDPair Left= optDiameter(root->left);
        HDPair Right=optDiameter(root->right);
        p.height=max(Left.height,Right.height)+1;
        int D1=Left.height+Right.height;
        int D2=Left.diameter;
        int D3=Right.diameter;
        
        p.diameter=max(D1,max(D2,D3));
        return p;
        
        
    }



int main(){
    node* root=buildTree();
    printLevelOrder(root);
    // cout<<"the diameter is: "<<diameter(root)<<endl;
    cout<<"The optimized diameter is: "<<optDiameter(root).diameter<<endl;
    
    return 0;
}