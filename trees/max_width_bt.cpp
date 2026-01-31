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


int widthOfBinaryTree(TreeNode* root) {
    queue<pair<unsigned long long,TreeNode*>>q;
    q.push({0,root});
    int max_width=0;
    while(!q.empty()){
        int size=q.size();
        unsigned long long start;
        for(int i=0;i<size;i++){
            auto [ind,cn]=q.front();
            // if(cn->val!=0) cout<<ind<<endl;
            if(i==0) start=ind;
            if(i==size-1) {
                max_width=max(max_width,(int)(ind-start+1));
            }
            q.pop();
            if(cn->left) q.push({2*ind,cn->left});
            if(cn->right) q.push({2*ind+1,cn->right});
        }
    }
    return max_width;
}



int main() {
   ifstream infile("input.txt");
   int t;
   infile >> t;
   infile.ignore();
   while(t--){
       //C-1: for vector input: infile >> vec[i]; and the numbers in the input file should be space seperated
       //C-2: if number of elements in the vector is not provided(after infile of t do infile.ignore() to remove the nextLine character from the buffer)
       //string line;
       //getline(infile,line);
       //stringstream ss(line);
       //vector<int>arr;
       //int num;
       //while(ss>>num) arr.push_back(num);

       string line;
       getline(infile,line);
       stringstream ss(line);
       vector<string>nodes;
       string node;
       while(ss>>node) nodes.push_back(node);
       TreeNode* root=buildTreeFromLevelOrder(nodes);
       cout<<widthOfBinaryTree(root)<<endl;

   }
return 0;
}
