
//  * Definition for a binary tree node.
 * class TreeNode {
    public:
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution {
public:
    //recursive method
    // void traverse(vector<vector<int>>&ans,TreeNode* root,int i){
    //     if(root){
    //         if (i >= ans.size()) {
    //             ans.push_back(vector<int>()); // Ensure ans has enough levels this method of increasing space is important
    //         }
    //         ans[i].push_back(root->val);
    //         traverse(ans,root->left,i+1);
    //         traverse(ans,root->right,i+1);
    //     }
        
    //     return ;
    // }
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>>ans;
    //     traverse(ans,root,0);
    //     return ans;
    // }

    //iterative approach
    vector<vector<int>>levelOrder(TreeNode* root){
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* n=q.front();
                q.pop();
                if(n->left){
                    q.push(n->left);
                }
                if(n->right){
                    q.push(n->right);
                }
                level.push_back(n->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
    


}