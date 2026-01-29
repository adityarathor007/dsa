/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, int& ans){
        if(!node) return 0;
        int ls=dfs(node->left,ans);
        int rs=dfs(node->right,ans);
        int maxChildSum=max(0,max(ls,rs));
        ans=max(ans,node->val+maxChildSum);
        ans=max(ans,node->val+ls+rs);
        return node->val+maxChildSum;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
};
