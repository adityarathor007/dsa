// continuation for the vertical order traversal of binary tree
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

vector<int> bottomView(TreeNode *root) {
        // code here
        map<int,int>bottomMap;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty()){
            auto currentPair=q.front();
            q.pop();

            TreeNode* TreeNode=currentPair.first;
            int col=currentPair.second;

            bottomMap[col]=TreeNode->val;
            if(TreeNode->left) q.push({TreeNode->left,col-1});

            if(TreeNode->right) q.push({TreeNode->right,col+1});
        }

        vector<int>bottomNodes;
        for(auto x:bottomMap){
            bottomNodes.push_back(x.second);
        }

        return bottomNodes;

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
       vector<string>input_arr;
       string node;
       while(ss>>node) input_arr.push_back(node);

        // for(string num:input_arr) cout<<num<<", ";
       TreeNode* root=buildTreeFromLevelOrder(input_arr);
       vector<int>ans=bottomView(root);

       cout<<"BottomView output: "<<endl;
       for(int num:ans) cout<<num<<", ";
       cout<<endl;


   }
return 0;
}
