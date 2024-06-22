#include <iostream>
using namespace std;



class node{

public:
	int data;
	node*left;
	node*right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

void downTraverseK(node* root,int k,vector<int>& ans){
    if(root==NULL){
        return;
    }
    if(k==0){
        // cout<<root->data<<endl;
        ans.push_back(root->data);
    }
    downTraverseK(root->left, k-1,ans);
    downTraverseK(root->right, k-1,ans);

}




int findNodesAtK(node* root,node* target,int k,vector<int> &ans){
    if(root==NULL){
        return -1;
    }
    
    
    //react the target node
    if(root==target){
        downTraverseK(root,k,ans);
        return 0;

    }
    
    
    //other cases
    int DL=findNodesAtK(root->left,target,k,ans);
    if(DL!=-1){
        if(DL+1==k){
            // cout<<root->data<<endl;
            ans.push_back(root->data);
        }
        else{
            downTraverseK(root->right, k-DL-2,ans);
        }
        return DL+1;
    }
    
    int DR=findNodesAtK(root->right,target,k,ans);
    if(DR!=-1){
        if(DR+1==k){
            // cout<<root->data<<endl;
            ans.push_back(root->data);
        }
        else{
            downTraverseK(root->left, k-DR-2,ans);
        }
        return DR+1;
    }
    
    return -1;
}


vector<int> nodesAtDistanceK(node *root, node *target, int k){
    //return a SORTED vector of the nodes
    vector<int>ans;
    findNodesAtK(root,target,k,ans);
    return ans;
    
    
}




int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(7);
    root->right=new node(3);
    root->right->right=new node(6);
    int k;
    cout<<"enter the value of k: "<<endl;
    cin>>k;
    auto ans=nodesAtDistanceK(root, root->left->right, k);
    

    

    
}