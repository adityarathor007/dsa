//important is that we consider the case of reset because we can start from any node
 void maxZigZag(TreeNode* node, int dirn, int cl, int& ans){
        if(!node){
            ans=max(ans,cl-1);
            return ;
        }

        if(dirn==0){
            maxZigZag(node->left,1,cl+1,ans);
            maxZigZag(node->left,0,0,ans); //reset is needed in the case where we wantt to move to the left childs  left node but werent able to move because of the goLeft constraint sp we go in the same direction (this is important)
        }

        else{
            maxZigZag(node->right,0,cl+1,ans);
            maxZigZag(node->right,1,0,ans);
        }

        return;
    }

    int longestZigZag(TreeNode* root) {
        int ans=0;
        maxZigZag(root,0,0,ans);
        maxZigZag(root,1,0,ans);

        return ans;
    }
