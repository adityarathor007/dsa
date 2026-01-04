class Solution {
    unordered_map<int,int>inorder_ind;
public:
    TreeNode* recBuild(int s_pre,int e_pre,int s_in, int e_in, vector<int>&preorder,vector<int>&inorder){
        if(s_in>e_in) return nullptr;

        int root_val=preorder[s_pre];
        TreeNode* root=new TreeNode(root_val);
        int rootInd=inorder_ind[root_val];
        int left_size=rootInd-s_in;


        root->left=recBuild(s_pre+1,s_pre+left_size,s_in,rootInd-1,preorder,inorder);
        root->right=recBuild(s_pre+left_size+1,e_pre,rootInd+1,e_in,preorder,inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++){
            inorder_ind[inorder[i]]=i;
        }

        return recBuild(0,n-1,0,n-1,preorder,inorder);
    }
};
