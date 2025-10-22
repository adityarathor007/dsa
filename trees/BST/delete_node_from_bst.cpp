TreeNode* deleteHelper(TreeNode* node){
        if(!node->left) return node->right;
        if(!node->right) return node->left;

        TreeNode* left_node=findLeftMostNode(node->right);
        left_node->left=node->left;
        return node->right;
    }

    TreeNode* findLeftMostNode(TreeNode* node){
        while(node->left){
            node=node->left;
        }
        return node;
    }

TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        if(root->val==key){
           return deleteHelper(root);
        }

        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left and root->left->val==key){
                    root->left=deleteHelper(root->left);
                    break;
                }
                else root=root->left;
            }
            else if(root->val<key){
                if(root->right and root->right->val==key){
                    root->right=deleteHelper(root->right);
                    break;
                }
                else root=root->right;
            }
        }
        return dummy;

    }