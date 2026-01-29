vector<int>ans;

pair<int,int> dfs(TreeNode* node){
    if(!node) return {0,0};

    auto [lh,ls]=dfs(node->left);
    auto [rh,rs]=dfs(node->right);

    if(lh==rh and lh!=-1){
        int cs=1+rs+ls;
        arr.push_back(cs);
        return {1+lh,1+rs+ls};
    }
    return {-1,0};
}

int kthLargestPerfectSubtree(TreeNode* root, int k) {
    dfs(root);
    int n=arr.size();
    sort(arr.begin(),arr.end());
    if(n<k) return -1;
    return arr[n-k];
}
