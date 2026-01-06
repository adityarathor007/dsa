 bool isSameTree(TreeNode* p,TreeNode* q){
        if(!p and !q) return true;
        if(!p or !q) return false;

        if(p->val!=q->val) return false;
        return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        return isSameTree(root,subRoot) or isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
