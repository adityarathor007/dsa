// using inoder traversal
// void inOrderTraversal(TreeNode* node, int&cnt, int&ans, int&k){
//         if(!node) return ;
//         inOrderTraversal(node->left,cnt,ans,k);
//         cnt+=1;
//         if(cnt==k){
//             ans=node->val;
//             return ;
//         }
//         inOrderTraversal(node->right,cnt,ans,k);
//         return ;

//     }

//     int kthSmallest(TreeNode* root, int k) {
//         int cnt=0;
//         int ans;
//         inOrderTraversal(root,cnt,ans,k);
//         return ans;
//     }



//cnt number of nodes (no requirement of it to be bfs it is the position in the inorder traversal   )

int cntNodes(TreeNode* node){
        if(!node) return 0;
        return 1+cntNodes(node->left)+cntNodes(node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        // cout<<root->val<<endl;
        int lc=cntNodes(root->left);
        if(lc==k-1) return root->val;
        if(lc>k-1) return kthSmallest(root->left,k);
        return kthSmallest(root->right,k-lc-1); //now searching among the remaining nodes
    }
