   // it  is possible that root or the lefs are not part of the path 


     int countTargetSum(TreeNode* node,long long targetSum){
        if(!node) return 0;
        int ans=0;
        if(targetSum==node->val) ans+=1;
        ans+=countTargetSum(node->left,targetSum-node->val);
        ans+=countTargetSum(node->right,targetSum-node->val);
        return ans;

    }
   
   int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        //three cases:
        // - if the root is included
        // - if the root is not included and we move to the left direction
        // - if the root is not included and we move to the right direction and it starts again
        return countTargetSum(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }