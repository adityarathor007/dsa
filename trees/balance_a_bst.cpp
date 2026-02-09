
void inorder(TreeNode* root,vector<TreeNode*>& nodes){
        if(!root) return ;
        inorder(root->left,nodes);
        nodes.push_back(root);
        inorder(root->right,nodes);
    }

    TreeNode* build(vector<TreeNode*>&nodes,int l,int r){
        if(l>r) return nullptr;
        int mid=(l+r)/2;
        TreeNode* root=nodes[mid];
        root->left=build(nodes,l,mid-1);
        root->right=build(nodes,mid+1,r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>nodes;
        inorder(root,nodes);
        int n=nodes.size();
        //  <<n<<endl;
        return build(nodes,0,n-1);
    }



// alternative DSW algo (skewed to right using rightRotation and doing leftRotations n-m and m times where n is the total number of nodes and m is the nodes if the tree is Perfect)
// void rightRotate(TreeNode* parent, TreeNode* node){
//         TreeNode* tmp=node->left;
//         node->left=tmp->right;
//         tmp->right=node;
//         parent->right=tmp;
//     }

//     void leftRotate(TreeNode* parent, TreeNode* node){
//         TreeNode* tmp=node->right;
//         node->right=tmp->left;
//         tmp->left=node;
//         parent->right=tmp;
//     }

//     void makeRotations(TreeNode* vineHead,int cnt){
//         TreeNode* curr=vineHead;
//         for(int i=0;i<cnt;i++){
//             TreeNode* tmp=curr->right;
//             leftRotate(curr,tmp);
//             curr=curr->right;
//         }
//     }


//     TreeNode* balanceBST(TreeNode* root) {
//         TreeNode* vineHead=new TreeNode(0);
//         vineHead->right=root;
//         TreeNode* curr=vineHead;

//         while(curr->right){
//             if(curr->right->left){
//                 rightRotate(curr,curr->right);
//             }
//             else curr=curr->right;
//         }

//         int n=0;
//         curr=vineHead->right;
//         while(curr){
//             curr=curr->right;
//             n+=1;
//         }

//         int m=pow(2,floor(log2(n+1)))-1;
//         makeRotations(vineHead,n-m);

//         while(m>1){
//             m/=2;
//             makeRotations(vineHead,m);
//         }

//         TreeNode* balancedRoot=vineHead->right;

//         delete vineHead;
//         return balancedRoot;


//     }
