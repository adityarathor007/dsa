#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int num){
        val=num;
        left=NULL;
        right=NULL;
    }
};


TreeNode* buildTreeFromLevelOrder(vector<string>&level_order){
    if(level_order.empty() or level_order[0]=="N") return nullptr;
    TreeNode* root=new TreeNode(stoi(level_order[0]));

    queue<TreeNode*>q;
    q.push(root);

    int i=1;
    int num_nodes=level_order.size();

    while(!q.empty() and i<num_nodes){
        TreeNode* node=q.front();
        q.pop();
        if(i<num_nodes and level_order[i]!="N"){
            TreeNode* leftNode=new TreeNode(stoi(level_order[i]));
            q.push(leftNode);
            node->left=leftNode;
        }
        i+=1;
        if(i<num_nodes and level_order[i]!="N"){
            TreeNode* rightNode=new TreeNode(stoi(level_order[i]));
            q.push(rightNode);
            node->right=rightNode;
        }

        i+=1;

    }

    return root;
}


//utility function for testing: inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}



int main() {

    vector<string>level_order{"1","2","3","4","5","6","7","N","N","8","9","N","N","N","N"};
    TreeNode* root=buildTreeFromLevelOrder(level_order);
    inorder(root);


return 0;
}
