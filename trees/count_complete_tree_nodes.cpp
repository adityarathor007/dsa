int countNodes(TreeNode* root) {
        // if(!root) return 0;
        // int lh=findLeftHeight(root->left);
        // int rh=findLeftHeight(root->right);
        // if(lh==rh){
        //     return pow(2,lh)+countNodes(root->right);
        // }
        // return pow(2,rh)+countNodes(root->left);

        if(!root) return 0;
        int lh=findLeftHeight(root->left);
        int rh=findRightHeight(root->right);
        if(lh==rh){
            return pow(2,lh+1)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;

    }

    int findLeftHeight(TreeNode* node){
        int depth=0;
        while(node){
            node=node->left;
            depth+=1;
        }
        return depth;

    }

      int findRightHeight(TreeNode* node){
        int depth=0;
        while(node){
            node=node->right;
            depth+=1;
        }
        return depth;

    }
