vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* cn=q.front();
                if(i==size-1)  ans.push_back(cn->val);
                q.pop();
                if(cn->left) q.push(cn->left);
                if(cn->right) q.push(cn->right);
            }

        }
        return ans;
    }
