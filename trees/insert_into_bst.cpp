 TreeNode* func(TreeNode* root,int val){
    if(!root) return root;

    //either gets updated children node or nullptr
    if(root->val>val){
        TreeNode* lnode=func(root->left,val);
        if(!lnode) root->left=new TreeNode(val);
        else root->left=lnode;
    }

    else{
        TreeNode* rnode=func(root->right,val);
        if(!rnode) root->right=new TreeNode(val);
        else root->right=rnode;
    }

    return root;

}

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        return func(root,val);
    }
