TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(root->val==key){
            TreeNode* lc=root->left;
            if(!lc) return root->right;
            TreeNode* rc=root->right;
            TreeNode* node=lc->right;
            if(rc){
                lc->right=rc;
                while(rc->left) rc=rc->left;
                rc->left=node;
            }
            delete(root);
            return lc;
        }

        if(root->val<key){
            TreeNode* nr=deleteNode(root->right,key);
            root->right=nr;
        }
        else{
            TreeNode* nl=deleteNode(root->left,key);
            root->left=nl;
        }
        return root;
}
