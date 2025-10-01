// pointers can be changed in function

void flatten(TreeNode* root) {
        if(!root){
            return ;
        }
        flatten(root->left);
        flatten(root->right);

        if(root->left!=nullptr){
            TreeNode* tail=root->left;
            while(tail->right!=nullptr){
                tail=tail->right;
            }

            tail->right=root->right;
            root->right=root->left;
            root->left=nullptr;

        }


    }
