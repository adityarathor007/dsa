#include <cmath>
#include<iostream>
#include<map>
using namespace std;

//we need to create a map such that it contains the row number and boolean flag whether for that row element is inserted or not 


class node
{
  public:
   int key;
   node *left;
   node *right;

   node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

void traverse(node* root, map<int,bool>&m,int i,vector<int>&ans){
    if(!m[i]){
        ans.push_back(root->key);
        m[i]=true;
    }
    
    if(root->left){
        traverse(root->left, m,i+1,ans);
    }
    if(root->right){
        traverse(root->right, m,i+1,ans);
    }
    return;
}

int findHeight(node* root){
    if(root==NULL){
        return 0;
    }
    int h1=findHeight(root->left);
    int h2=findHeight(root->left);
    return max(h1,h2)+1;

    
}

vector<int> leftView(node * root){
    //Complete the function
    map<int,bool>m ;
    int h=findHeight(root);
    vector<int> ans;
    for(int i=1;i<=h;i++){
        m[i]=false;
    }
    traverse(root,m,1,ans);
    
    return ans;
    
}


int main(){
    node* root=new node(1);
    root->left= new node(2);
    root->left->left= new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(7);
    root->right=new node(3);
    root->right->left=new node(6);
    auto ans=leftView(root);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    
    return 0;
    
}