#include <iostream>
#include <map>
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

void FindVertical(map<int,vector<int> >& ans,node* root,int k){
    
    if(root==NULL){
        return;
    }
    ans[k].push_back(root->data);
    FindVertical(ans, root->left, k-1);
    FindVertical(ans, root->right, k+1);
    
    return ;
    
    
    
    
}



int main(){
  node* root=new node(1);
  root->left= new node(2);
  root->left->left= new node(4);
  root->left->right=new node(5);
  root->left->right->left=new node(7);
  root->right=new node(3);
  root->right->left=new node(6);
  map<int,vector<int> > ans;
  FindVertical(ans,root,0);
  
  for(auto elem:ans){
      for(auto x:elem.second){
          cout<<x<<",";
      }
      cout<<endl;
  }
}