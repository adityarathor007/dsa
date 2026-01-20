int recCnt(TreeNode* node, int max_till_now){
        if(!node) return 0;
        int cnt=node->val>=max_till_now?1:0;
        int nxt_max=max(max_till_now,node->val);

        cnt+=recCnt(node->left,nxt_max);
        cnt+=recCnt(node->right,nxt_max);

        return cnt;

    }
int goodNodes(TreeNode* root) {
    return recCnt(root,INT_MIN);
}
