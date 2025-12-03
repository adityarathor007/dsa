 void flatten(TreeNode* root) {
        if(!root or (!root->left and !root->right)) return;

        TreeNode* temp=root;
        TreeNode* right_fhead=NULL;

        if(root->left){
            flatten(root->left);
            right_fhead=root->right;
            root->right=root->left;
            root->left=NULL;
            temp=root->right;
            while(temp->right) temp=temp->right; //taking to the last node of the flattened left subtree

        }

        if(right_fhead){
            flatten(right_fhead);
            temp->right=right_fhead;
        }
        else{
            flatten(root->right);  //if no left child
        }



    }
