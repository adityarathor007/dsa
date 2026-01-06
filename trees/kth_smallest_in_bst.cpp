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



//cnt number of nodes

int cntNodes(TreeNode* node){
        if(!node) return 0;
        int cnt=1;
        return cnt+cntNodes(node->left)+cntNodes(node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        // cout<<root->val<<endl;
        int ln=cntNodes(root->left);
        if(ln==k-1) return root->val;
        if(ln>k-1) return kthSmallest(root->left,k);
        return kthSmallest(root->right,k-ln-1); //now searching among the remaining nodes
    }
