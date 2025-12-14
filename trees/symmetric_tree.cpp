bool dfs(TreeNode* l,TreeNode* r){
        if(!l and !r) return true;
        if(!l or !r) return false;

        if(!dfs(l->left,r->right) or !dfs(l->right,r->left)) return false;

        return l->val==r->val;
    }

    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
