#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d){
            val=d;
            left=NULL;
            right=NULL;
        }
};


TreeNode* buildLevelOrder(){
    int d;
    cin>>d;
    
    TreeNode* root=new TreeNode(d);
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode* current=q.front();
        q.pop();  //popping the node which is the root and whose child will be intialized
        
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            current->left=new TreeNode(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right=new TreeNode(c2);
            q.push(current->right);
        }
        
        
    }
    
    
    return root;
}



void leftMostTraversal(TreeNode* root,vector<int>&ans){
    if(!root->left and !root->right){
        return ; //i.e reached the leaf node
    }
    ans.push_back(root->val);
    if(root->left){
        leftMostTraversal(root->left,ans);
    }
    else if(root->right){
        leftMostTraversal(root->right,ans);
    }

}

void leafNodes(TreeNode* root,vector<int>& ans){
    int s=ans.size();
    if(!root){
        return ;
    }
    if(!root->left and !root->right){
        ans.push_back(root->val);
    }
    
    leafNodes(root->left,ans);
    leafNodes(root->right,ans);
}

void rightTraversal(TreeNode* root,vector<int>&ans){
    if(!root->left and !root->right){
        return ; //reached the leaf node

    }
    if(root->right){
        rightTraversal(root->right,ans);
    }
    else if(root->left){
        rightTraversal(root->left,ans);
    }
    ans.push_back(root->val);

}




vector <int> boundary(Node *root)
    {
    vector<int>ans;
    if(!root){
        return ans;
    }
    if(root->left or root->right){  //push only when it is not a leaf
          ans.push_back(root->data);
    }
  
    if(root->left){
        leftMostTraversal(root->left,ans); // excluding the only leaf node
    }
    
    
    leafNodes(root,ans); //all leaf nodes
    if(root->right){
        rightTraversal(root->right,ans);  // excluding the root and only leaf node
    } //also to be added in reverse order
    

    return ans;
    }

int main(){
    TreeNode* root=buildLevelOrder();

    auto a=printBoundary(root);
    for(auto x:a){
        cout<<x<<",";
    }
    cout<<endl;

    return 0;
}