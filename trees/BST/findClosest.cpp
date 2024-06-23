#include <climits>
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


Node* insert(int x,Node* root){
    if(root==NULL){
        return new Node(x);
    }
    if(x<=root->key){
       root->left=insert(x,root->left);
    }
    else{
        root->right=insert(x,root->right);
    }
    
    return root;
}

int findNearest(Node* root,int k,int min_diff,int closest){
   
    
    if(root==NULL){
        // cout<<ans->key<<endl;
        return closest;
    }
    
    
    if(root->key==k){ //NULL check is important before this as NULL pointer wont contain any key this check done so that 
        //we dont traverse further as we found the node only whose key is same as the k
        min_diff=0;
        closest=root->key;
      
        return closest;
    }
    
    int diff=abs(k-root->key);
    
    if(diff<min_diff){
        min_diff=diff;
        closest=root->key;
    }
    
    if(k<root->key){
        closest=findNearest(root->left, k, min_diff,closest);
    }
    else{
        closest=findNearest(root->right, k, min_diff,closest);
    }
    
    return closest;
}



int main(){
    Node* root=NULL;
    int arr[]={8,4,10,1,6,14,4,7,13};
    for(auto x:arr){
        root=insert(x,root);
    }
    int ans=INT_MAX;
    int min_diff=INT_MAX;
    cout<<findNearest(root,2,min_diff,ans)<<endl;
    
}