bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2) return true;
        if(!root1 or !root2) return false;

        if(root1->val!=root2->val) return false;

        // either they are not swapped
        bool o1=flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);

        // or they are swapped
        bool o2=flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);

        return o1 or o2;

    }
