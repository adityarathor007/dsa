   TreeNode* nextNode=NULL, *rootNode=NULL;

    BSTIterator(TreeNode* root) {
        rootNode=root;
        nextNode=root;
        while(nextNode->left){
            nextNode=nextNode->left;
        }
    }

    int next() {
        TreeNode* key=nextNode,*temp=rootNode;
        nextNode=NULL;
        while(temp){
            if(temp->val>key->val){
                nextNode=temp;
                temp=temp->left;
            }
            else temp=temp->right;
        }

        return key->val;
    }

    bool hasNext() {
        return nextNode!=NULL;
    }
};
