/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:

    int recHelper(TreeNode* node,int &ans){
        if(!node) return 0;

        int lh=recHelper(node->left,ans);
        int rh=recHelper(node->right,ans);

        ans=max(ans,lh+rh);
        return 1+max(lh,rh); //edge from current node to child 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        recHelper(root,ans);
        return ans;
    }
};
