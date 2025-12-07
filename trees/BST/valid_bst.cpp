bool checkRange(TreeNode* node, long min_value, long max_value){
        if(!node) return true;
        int node_val=node->val;
        if(node_val<=min_value or node_val>=max_value) return false;

        bool checkLeft=checkRange(node->left, min_value, node_val);
        bool checkRight=checkRange(node->right,node_val, max_value);
        return checkLeft and checkRight;
    }

    bool isValidBST(TreeNode* root) {
        return checkRange(root,LONG_MIN,LONG_MAX);
    }
