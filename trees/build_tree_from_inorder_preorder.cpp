 TreeNode* recBuildTree(int l_in,int r_in,int l_pre,int r_pre,vector<int>&preorder,vector<int>&inorder){

        if(l_in>r_in) return NULL;

        cout<<preorder[l_pre]<<endl;
        int root_val=preorder[l_pre];
        TreeNode* root=new TreeNode(root_val);

        auto it=find(inorder.begin(), inorder.end(), root_val);
        int inorder_root_index = std::distance(inorder.begin(), it);

        int lst_size=inorder_root_index-l_in;
        root->left=recBuildTree(l_in,inorder_root_index-1,l_pre+1,l_pre+lst_size,preorder,inorder);
        root->right=recBuildTree(inorder_root_index+1,r_in,l_pre+lst_size+1,r_pre,preorder,inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int l_pre=0,r_pre=n-1;
        int l_in=0,r_in=n-1;
        return recBuildTree(l_in,r_in,l_pre,r_pre,preorder,inorder);
    }
