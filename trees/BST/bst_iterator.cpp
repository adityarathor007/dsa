class BSTIterator {
    TreeNode* nxtNode,*root;
public:
    BSTIterator(TreeNode* root) {
        this->root=root;
        nxtNode=root;
        while(nxtNode->left) nxtNode=nxtNode->left;
    }

    int next() {
        TreeNode* key=nxtNode;
        TreeNode* temp=root;
        while(temp){
            if(temp->val>key->val){
                nxtNode=temp;
                temp=temp->left;
            }
            else temp=temp->right;
        }
        if(nxtNode==key) nxtNode=nullptr;

        return key->val;
    }

    bool hasNext() {
        return nxtNode!=nullptr;
    }
};
