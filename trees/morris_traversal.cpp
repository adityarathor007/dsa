
    void morris_inorder(TreeNode* root,vector<int>&ans){
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right and prev->right!=curr){  //creating a threaded binary tree
                    prev=prev->right;
                }
                if(!prev->right){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }


            }
        }
    }








void morris_preorder(TreeNode* root,vector<int>ans){

 TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);   
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right and prev->right!=curr){
                    prev=prev->right;
                }
                if(!prev->right){
                    prev->right=curr; //creating a threaded binary tree
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    curr=curr->right;
                }


            }
        }
}
