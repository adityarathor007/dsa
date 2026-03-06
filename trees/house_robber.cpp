 int rob(TreeNode* root) {
        auto [withRoot,withoutRoot]=dfs(root);
        return max(withRoot,withoutRoot);
    }

    pair<int,int>dfs(TreeNode* node){
        if(!node) return {0,0};
        auto [lwr,lwor]=dfs(node->left);
        auto [rwr,rwor]=dfs(node->right);

        int wor=max(lwr,lwor)+max(rwr,rwor);
        int wr=node->val+lwor+rwor;
        return {wr,wor};
    }
