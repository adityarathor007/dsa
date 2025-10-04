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
    int maxPath(TreeNode* node,int& ans){
        if(!node) return 0;

        int ls=max(0,maxPath(node->left,ans)); //if sum is negative then it is better to not take left subtree
        int rs=max(0,maxPath(node->right,ans)); //similarily for right subtree
        ans=max(ans,ls+rs+node->val);
        return node->val+max(ls,rs);
    }

    int maxPathSum(TreeNode* root) {
     if(!root) return 0;
     int ans=INT_MIN;
     maxPath(root,ans);
     return ans;
    }
};c
