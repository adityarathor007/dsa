void inOrderTraversal(TreeNode* node, int&cnt, int&ans, int&k){
        if(!node) return ;
        inOrderTraversal(node->left,cnt,ans,k);
        cnt+=1;
        if(cnt==k){
            ans=node->val;
            return ;
        }
        inOrderTraversal(node->right,cnt,ans,k);
        return ;

    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans;
        inOrderTraversal(root,cnt,ans,k);
        return ans;
    }
