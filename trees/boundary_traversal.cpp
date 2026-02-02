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


    void dfs(Node* node,vector<int>&ans){
        if(!node) return;

        if(!node->left and !node->right) ans.push_back(node->data);

        dfs(node->left,ans);
        dfs(node->right,ans);
        return;
    }

    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root->left or root->right) ans.push_back(root->data); //if root is not leaf node
        Node* temp=root->left;

        // left traversal
        while(temp){
            if(!temp->left and !temp->right) break;

            ans.push_back(temp->data);
            if(temp->left) temp=temp->left;
            else temp=temp->right;
        }

        // leafNodes using preorder traversal
        dfs(root,ans);

        // rightTraversal
        temp=root->right;
        vector<int>rightSide;
        while(temp){
            if(!temp->left and !temp->right) break;

            rightSide.push_back(temp->data);
            if(temp->right) temp=temp->right;
            else temp=temp->left;
        }

        reverse(rightSide.begin(),rightSide.end());
        ans.insert(ans.end(),rightSide.begin(),rightSide.end());

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
