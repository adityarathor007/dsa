#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TreeNode {
public:
    char value;
    vector<TreeNode*> children;

    TreeNode(char val) : value(val) {}
};

TreeNode* buildTree(int n, const vector<vector<int>>& edges, const vector<char>& values, unordered_map<int, TreeNode*>& nodeMap) {
    for (int i = 1; i <= n; ++i) {
        nodeMap[i] = new TreeNode(values[i - 1]);
    }

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        nodeMap[u]->children.push_back(nodeMap[v]);
    }

    return nodeMap[1]; // assuming node 1 is the root
}

bool isPalindrome(const vector<char>& path) {
    int left = 0, right = path.size() - 1;
    while (left < right) {
        if (path[left] != path[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void postOrderTraversal(TreeNode* node, vector<char>& path) {
    if (!node) return;

    for (TreeNode* child : node->children) {
        postOrderTraversal(child, path);
    }
    
    path.push_back(node->value);
}

bool checkPalindromeFromNode(int startNode, unordered_map<int, TreeNode*>& nodeMap) {
    if (nodeMap.find(startNode) == nodeMap.end()) return false;

    vector<char> path;
    postOrderTraversal(nodeMap[startNode], path);
    return isPalindrome(path);
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{5, 3}, {2, 3}, {1, 4}, {4, 2}};
    vector<char> values = {'h', 'z', 'd', 'b', 'e'};

    unordered_map<int, TreeNode*> nodeMap;
    TreeNode* root = buildTree(n, edges, values, nodeMap);

    int startNode = 3;
    bool result = checkPalindromeFromNode(startNode, nodeMap);

    if (result) {
        cout << "A palindrome exists in the tree starting from node " << startNode << " in post-order traversal." << endl;
    } else {
        cout << "No palindrome exists in the tree starting from node " << startNode << " in post-order traversal." << endl;
    }

    return 0;
}
