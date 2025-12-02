 int Traverse(TreeNode* root, int&ans){
        if(!root) return 0;

        //if bringing negative from child then we replace it with zero
        int leftMaxSum=max(0,Traverse(root->left,ans));
        int rightMaxSum=max(0,Traverse(root->right,ans));
        int maxChildSum=max(leftMaxSum,rightMaxSum);

        ans=max(ans,root->val+leftMaxSum+rightMaxSum); //at each position we do this so that we can ignore the tree above it
        return root->val+maxChildSum;

    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        Traverse(root,ans);
        return ans;
    }
