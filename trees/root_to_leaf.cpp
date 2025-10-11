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


void dfs(TreeNode* root,vector<int>&buff,vector<vector<int>>&ans){
        if(!root) return;

        buff.push_back(root->val);

        if(!root->left and !root->right){
            ans.push_back(buff);
            buff.pop_back();
            return ;
        }

        if(root->left){
            dfs(root->left,buff,ans);
        }

        if(root->right){
            dfs(root->right,buff,ans);
        }

        buff.pop_back();

}


vector<vector<int>> Paths(TreeNode* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>buff;
        dfs(root,buff,ans);

        return ans;

    }


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
       auto leaf_paths=Paths(root);

       for(auto path:leaf_paths){
        for(auto node:path){
            cout<<node<<", ";
        }
        cout<<endl;
       }

   }
return 0;
}
