#include<iostream>
#include<queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode * buildTree(){
    
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    
    TreeNode* n=new TreeNode(d);
    n->left=buildTree();
    n->right=buildTree();
    
    
    return n;
    
    
}

int findHeight(TreeNode* root){
    // recursive approach
    // if(!root){
    //     return 0;
    // }
    // return 1+max(findHeight(root->left),findHeight(root->right));

    //level order traversal
    queue<TreeNode* > q;
    if(!root){
        return 0;
    }
    q.push(root);
    int ans=0;
    while(!q.empty()){
        
        int size=q.size();
        ans+=1;
        for(int i=0;i<size;i++){
            TreeNode* n=q.front();
            q.pop();
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
    }

    return ans;

}


TreeNode * buildLevelOrder(){
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




int main(){
    TreeNode* root=buildLevelOrder();

    cout<<findHeight(root)<<endl;
}