bool isLeaf(TreeNode* node){
        if(!node->left and !node->right) return true;
        return false;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return nullptr;
        TreeNode* nl=removeLeafNodes(root->left,target);
        TreeNode* nr=removeLeafNodes(root->right,target);
        root->left=nl;
        root->right=nr;
        if(isLeaf(root) and root->val==target) return nullptr;
        return root;
    }
