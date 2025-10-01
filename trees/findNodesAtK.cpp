/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode*&root,unordered_map<TreeNode*,TreeNode*>&trackParents){
        //level order traversal
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left){
                    q.push(current->left);
                    trackParents[current->left]=current;
                }
                if(current->right){
                    q.push(current->right);
                    trackParents[current->right]=current;
                }
            }
        }


    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // mark parents
        unordered_map<TreeNode*,TreeNode*>trackParents;
        markParents(root,trackParents);

        //traverse like a graph(bfs) in tree
        int current_dist=0;
        queue<TreeNode*>q;
        unordered_set<int>visited;

        q.push(target);
        visited.insert(target->val);

        while(!q.empty()){
            int size=q.size();
            if(current_dist++==k) break;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();

                if(current->left and !visited.count(current->left->val)){
                    visited.insert(current->left->val);
                    q.push(current->left);
                }

                if(current->right and !visited.count(current->right->val)){
                    visited.insert(current->right->val);
                    q.push(current->right);
                }

                if(trackParents[current] and !visited.count(trackParents[current]->val)){
                    visited.insert(trackParents[current]->val);
                    q.push(trackParents[current]);
                }
            }
        }

        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;

    }
};
