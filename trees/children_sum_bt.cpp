#include <bits/stdc++.h>
using namespace std;




struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int num){
        val = num;
        left = NULL;
        right = NULL;
    }
};


TreeNode* buildTreeFromLevelOrder(vector<string>& level_order){
    if(level_order.empty() || level_order[0] == "N") return nullptr;
    TreeNode* root = new TreeNode(stoi(level_order[0]));

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    int num_nodes = level_order.size();

    while(!q.empty() && i < num_nodes){
        TreeNode* node = q.front();
        q.pop();

        if(i < num_nodes && level_order[i] != "N"){
            TreeNode* leftNode = new TreeNode(stoi(level_order[i]));
            q.push(leftNode);
            node->left = leftNode;
        }
        i++;

        if(i < num_nodes && level_order[i] != "N"){
            TreeNode* rightNode = new TreeNode(stoi(level_order[i]));
            q.push(rightNode);
            node->right = rightNode;
        }
        i++;
    }

    return root;
}

int isSumProperty(TreeNode* root){
    if(!root or (!root->left and !root->right)) return 1; //we need to check for the leaf nodes
    if(isSumProperty(root->left)==0 or isSumProperty(root->right)==0) return 0;

    int left=root->left?root->left->val:0;
    int right=root->right?root->right->val:0;

    // if(left+right!=root->val){
        // cout<<"the node is: "<<root->val<<endl;
    // }
    return left+right==root->val;
}


int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   infile.ignore();
   while(t--){
       //C-1: for vector input: infile >> vec[i]; and the numbers in the input file should be space seperated
       //C-2: if number of elements in the vector is not provided(after infile of t do infile.ignore() to remove the nextLine character from the buffer)
       string line;
       getline(infile,line);
       stringstream ss(line);
       vector<string>arr;
       string num;
       while(ss>>num) arr.push_back(num);

       auto root=buildTreeFromLevelOrder(arr);
       cout<<isSumProperty(root)<<endl;

   }
return 0;
}
