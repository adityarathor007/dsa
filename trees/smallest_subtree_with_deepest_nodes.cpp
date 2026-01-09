class Solution {
    unordered_map<TreeNode*,TreeNode*>nodeParentMap;
public:
    int findMaxDepth(TreeNode* node){
        if(!node) return 0;

        return 1+max(findMaxDepth(node->left),findMaxDepth(node->right));
    }

    TreeNode* findLCA(TreeNode* n1,TreeNode* n2){
        if(n1==n2) return n1;
        TreeNode* p1=nodeParentMap[n1];
        TreeNode* p2=nodeParentMap[n2];

        while(p1!=p2){
            p1=nodeParentMap[p1];
            p2=nodeParentMap[p2];
        }
        return p1;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        nodeParentMap.clear();
        int maxDepth=findMaxDepth(root);

        queue<TreeNode*>q;
        q.push(root);
        nodeParentMap[root]=root;

        vector<TreeNode*>lastLevelNodes;
        int level=1;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* cn=q.front();
                if(level==maxDepth) lastLevelNodes.push_back(cn);
                q.pop();
                if(cn->left){
                    q.push(cn->left);
                    nodeParentMap[cn->left]=cn;
                }
                if(cn->right){
                    q.push(cn->right);
                    nodeParentMap[cn->right]=cn;
                }
            }
            level+=1;
        }


        int numLeafNodes=lastLevelNodes.size();

        if(numLeafNodes==1) return lastLevelNodes[0];
        TreeNode* n1=lastLevelNodes[0];
        TreeNode* n2=lastLevelNodes[numLeafNodes-1];
        return findLCA(n1,n2);
    }
};
