TreeNode* recHelper(int s,int e,vector<int>&nums){
        if(s>e) return NULL;
        if(s==e) return new TreeNode(nums[s]);

        int mid=(s+e)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=recHelper(s,mid-1,nums);
        node->right=recHelper(mid+1,e,nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return recHelper(0,n-1,nums);
    }
