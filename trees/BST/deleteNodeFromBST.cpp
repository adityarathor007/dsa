#include<iostream>
#include<vector>
using namespace std;



class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

};


TreeNode* deleteNode(TreeNode* root, int key) {

    if(root==NULL){
            return root;
        }
        if(root->val==key){ //if root is to be deleted
            return helper(root);
        }
        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left and root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }

            }
            else{
                if(root->right and root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }


            return dummy;
        }

        TreeNode* helper(TreeNode* root) {
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            // if(both root->left and root->right exists)
            TreeNode* leftChild=root->left;
            TreeNode* lastLeft=findLastLeft(root->right);
            lastLeft->left=leftChild;
            return root->right;
        }

        TreeNode* findLastLeft(TreeNode* root){
            while(root->left){
                root=root->left;
            }

            return root;
    }