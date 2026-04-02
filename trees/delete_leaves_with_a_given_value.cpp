    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return nullptr;
        //get children after updated from below
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);

        // if is leaf and is target
        if(root->val==target and !root->left and !root->right) return nullptr;
        return root;
    }
