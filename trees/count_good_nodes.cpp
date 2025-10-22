void countGoodNodes(TreeNode* node,int &cnt, int cmax){
        if(!node) return ;
        if(node->val>=cmax){
            cmax=max(node->val,cmax);
            cnt+=1;
        }
        countGoodNodes(node->left,cnt,cmax);
        countGoodNodes(node->right,cnt,cmax);
    }

    int goodNodes(TreeNode* root) {
        int cnt=0;
        countGoodNodes(root,cnt,root->val);
        return cnt;
    }