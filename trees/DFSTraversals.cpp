/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void inOrderTraversal(vector<vector<int>>&ans,TreeNode *root){
    if(!root){
        return;
    }
    inOrderTraversal(ans, root->left);
    ans[0].push_back(root->data);
    inOrderTraversal(ans, root->right);
}

void preOrderTraversal(vector<vector<int>>&ans,TreeNode *root){
    // recursive approach
    // if(!root){
    //     return;
    // }
    // ans[1].push_back(root->data);
    // preOrderTraversal(ans, root->left);
    // preOrderTraversal(ans, root->right);
    // return ;

    // iterative approach
    s   tack<TreeNode*>s;
    s.push(root);
    while(!s.empty()){
        TreeNode*n=s.top();
        ans.push_back(n->val);
        s.pop();
        if(n->right){
            s.push(n->right);
        }
        if(n->left){
            s.push(n->left);
        }

    }



    return ;

}


void postOrderTraversal(vector<vector<int>>&ans,TreeNode *root){
    // using recursion
    // if(!root){
    //     return;
    // }
    // postOrderTraversal(ans, root->left);
    // postOrderTraversal(ans, root->right);
    // ans[2].push_back(root->data);

 //using 2 stacks
        // stack<TreeNode*>s1;
        // stack<TreeNode*>s2;
        // if(!root){
        //     return ;
        // }
        // s1.push(root);
        // while(!s1.empty()){
        //     TreeNode* n=s1.top();
        //     s1.pop();
        //     s2.push(n);
        //     if(n->left){
        //         s1.push(n->left);
        //     }
        //     if(n->right){
        //         s1.push(n->right);
        //     }
        // }
        // while(!s2.empty()){
        //     ans.push_back(s2.top()->val);
        //     s2.pop();
        // }
        // return ;

        // using 1 stack
        stack<TreeNode*>s;
        TreeNode* curr=root;
        while(curr||!s.empty()){
            if(curr){
                s.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* temp=s.top()->right;
                if(!temp){
                    temp=s.top();
                    ans.push_back(temp->val);
                    s.pop();
                    while(!s.empty() && temp==s.top()->right){ 
                        temp=s.top();
                        ans.push_back(temp->val); //reached the right most node of the tree
                        s.pop();
                    }
                }
                else{
                    curr=temp;
                }
            }

        }

        return ;


}


void oneTraversal(vector<vector<int>>&ans,Node* root){
    if(!node){
        return ;
    }
    ans[0].push_back(root->val);
    oneTraversal(ans,root->left);
    ans[1].push_back(root->val);
    oneTraversal(ans,root->right);
    ans[2].push_back(root->val);
}




vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>>ans(3);
    inOrderTraversal(ans,root);
    preOrderTraversal(ans,root);
    postOrderTraversal(ans,root);
    oneTraversal(ans,root);

    return ans;

}