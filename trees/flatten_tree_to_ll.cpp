 void flatten(TreeNode* root) {
        if(!root or (!root->left and !root->right)) return;
        // cout<<root->val<<endl;
        flatten(root->left);
        flatten(root->right);
        TreeNode* rightNode=root->right;
        // cout<<"right_node value: "<<rightNode->val<<endl;

        // if left node exists
        if(root->left) {
            root->right=root->left;
            TreeNode* temp=root;
            while(temp->right){
                temp=temp->right;
            }
            temp->right=rightNode;
            root->left=nullptr;
        }

        return;

    }
};
