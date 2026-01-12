 void recReverseOdd(TreeNode* left, TreeNode* right, int level){
        if(!left || !right) return ;
        if(level&1){
            swap(left->val,right->val);
        }

        // recursive on the mirror nodes
        recReverseOdd(left->left,right->right,level+1);
        recReverseOdd(left->right,right->left,level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        recReverseOdd(root->left,root->right,1);
        return root;
    }
