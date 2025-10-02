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


  void leaf_traversal(TreeNode* node,vector<int>&ans){
        if(!node) return;
        leaf_traversal(node->left,ans);
        leaf_traversal(node->right,ans);
        if(!node->right and !node->left) ans.push_back(node->val);
        return;
    }

    void left_traversal(TreeNode *node,vector<int>&ans){
        if(!node) return ;
        if(!node->right and !node->left) return ;
        ans.push_back(node->val);

        if(node->left) left_traversal(node->left,ans);
        else left_traversal(node->right,ans);
        return ;
    }

    void right_traversal(TreeNode* node,vector<int>&ans){
        if(!node) return ;
        if(!node->right and !node->left) return ;

        if(node->right) right_traversal(node->right,ans);
        else right_traversal(node->left,ans);

        ans.push_back(node->val);
        return ;

    }


    vector<int> boundaryTraversal(TreeNode *root) {
        // code here
        vector<int>ans;
        if(root->left or root->right) ans.push_back(root->val); //because if root is the leaf node then it will be added via leaf_traversal
        left_traversal(root->left,ans);
        leaf_traversal(root,ans);
        right_traversal(root->right,ans);
        return ans;
    }


  int main() {
     ifstream infile("input.txt");
     int t;
     infile >> t;
     while(t--){
         // for vector input: infile >> vec[i];
         int n;
         infile>>n;
         vector<string>nodes(n);

         for(int i=0;i<n;i++){
            infile>>nodes[i];
         }


         TreeNode* root=buildTreeFromLevelOrder(nodes);
         vector<int>bt=boundaryTraversal(root);
         for(int num:bt){
            cout<<num<<", ";
         }
         cout<<endl;

     }
  return 0;
  }
