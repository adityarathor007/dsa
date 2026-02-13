 TreeNode* firstNode=nullptr,*secondNode=nullptr;
    TreeNode* prevNode=new TreeNode(INT_MIN);
public:
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);

        if(!firstNode and prevNode->val>root->val){
            firstNode=prevNode;
        }
        if(firstNode and prevNode->val>root->val){
            secondNode=root;
        }
        prevNode=root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        swap(firstNode->val,secondNode->val);
    }
