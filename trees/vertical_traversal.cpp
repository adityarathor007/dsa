class Solution {

public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>nodes; //to store coln level and the node value and set used to keep values in sorted order and multi as nodes may have the same value
        queue<pair<TreeNode*,pair<int,int>>> q; //storing node the coln and the level
        q.push({root,{0,0}});
        while(!q.empty()){
             int size=q.size();
             for(int i=0;i<size;i++){
                auto p=q.front();
                q.pop();
                int vc=p.second.first;
                TreeNode* n=p.first;
                int level=p.second.second;
                

                // cout<<level<<" - "<<vc<<" - "<<n->val<<endl;

                if(n->left){
                    q.push({n->left,{vc-1,level+1}});
                }
                if(n->right){
                    q.push({n->right,{vc+1,level+1}});

                }

                //inserting into the map 
                nodes[vc][level].insert(n->val);
                
             }
        }

        //inserting finally to the ans
        // storing order in the map {each col->multiple levels then inserting based on levels}
        for(auto x:nodes){
            vector<int>col;
            for(auto q:x.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
       
        return ans;
    }
};