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

TreeNode* getTargetNode(TreeNode* root,int target){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* cn=q.front();
        q.pop();
        if(cn->val==target) return cn;
        if(cn->left) q.push(cn->left);
        if(cn->right) q.push(cn->right);
    }
    return NULL;
}




void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp){
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,NULL});

        // level order traversal
        while(!q.empty()){
            auto cp=q.front();
            q.pop();
            TreeNode* cn=cp.first;
            TreeNode* parent=cp.second;
            mp[cn]=parent;

            if(cn->left) q.push({cn->left,cn});
            if(cn->right) q.push({cn->right,cn});

        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentNode;
        markParents(root,parentNode);

        // bfs traversal
        queue<TreeNode*>q;
        q.push(target);
        int dist=0;
        set<TreeNode*> visited;
        visited.insert(target);

        while(!q.empty()){
            if(dist==k) break;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* cn=q.front();
                q.pop();
                if(cn->left and !visited.count(cn->left)){
                    q.push(cn->left);
                    visited.insert(cn->left);
                }
                if(cn->right and !visited.count(cn->right)){
                    q.push(cn->right);
                    visited.insert(cn->right);
                }

                if(parentNode[cn]!=NULL and !visited.count(parentNode[cn])){
                    q.push(parentNode[cn]);
                    visited.insert(parentNode[cn]);
                }
            }
            dist+=1;
        }

        vector<int>ans;
        while(!q.empty()){
            auto cn=q.front();
            ans.push_back(cn->val);
            q.pop();
        }

        return ans;

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
       int targetNum,k;
       infile>>targetNum>>k;
       infile.ignore();
       auto targetNode=getTargetNode(root,targetNum);

       if(!targetNode){
            cout<<"targetNode: "<<targetNum<<" not found"<<endl;
       }
       vector<int> nodes=distanceK(root,targetNode,k);
       for(int node:nodes) cout<<node<<", ";
       cout<<endl;


   }
return 0;
}
