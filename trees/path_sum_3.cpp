   // it  is possible that root or the lefs are not part of the path


    void dfs(TreeNode* node,long long csum,int& cnt,int targetSum){
        if(!node) return;
        csum+=node->val;
        if(csum==targetSum) cnt+=1;

        dfs(node->left,csum,cnt,targetSum);
        dfs(node->right,csum,cnt,targetSum);

    }


   int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        //three cases:
        // - if the root is included
        // - if the root is not included and we move to the left direction
        // - if the root is not included and we move to the right direction and it starts again
        int cnt=0;
        dfs(root,0,cnt,targetSum);
        cnt+=pathSum(root->left,targetSum);
        cnt+=pathSum(root->right,targetSum);
        return cnt;
    }
