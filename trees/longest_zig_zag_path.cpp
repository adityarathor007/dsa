 int longestZigZag(TreeNode* root) {
        //important is that we consider the case of reset because we can start from any node
        int ans=0;
        dfs(root,true,0,ans); //assuming start left
        dfs(root,false,0,ans); //assuming start right
        return ans;
    }

    void dfs(TreeNode* node,bool goLeft,int len,int& ans){
        if(!node) return ;
        ans=max(ans,len);
        if(goLeft){
            dfs(node->left,false,len+1,ans);
            dfs(node->right,true,1,ans);  //reset is needed in the case where we wantt to move to the left childs  left node but werent able to move because of the goLeft constraint sp we go in the same direction (this is important)
        }
        else{
            dfs(node->right,true,len+1,ans);
            dfs(node->left,false,1,ans);
        }
    }