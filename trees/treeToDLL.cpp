   Node* prev=NULL;
    Node* bToDLL(Node* root) {
        // code here
            if(!root){
                return NULL;
         }
    
    Node* head=bToDLL(root->left);
    if(!prev){
        head=root;
    }
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;  //keeping track of the prev Node not necessarilty the parent
    
    bToDLL(root->right);
    
    return head;
    }