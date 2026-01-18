class Solution {
    unordered_map<int,vector<pair<int,int>>>adjList;
    vector<int>ans;
public:
    void dfs1(int node,int p,int& min_rev){
        for(auto [neighbour,isRev]:adjList[node]){
            if(neighbour==p) continue;
            if(isRev) min_rev+=1;
            dfs1(neighbour,node,min_rev);
        }
    }

    void dfs2(int node, int p){
        for(auto [neighbour,isRev]:adjList[node]){
            if(neighbour==p) continue;
            ans[neighbour]=ans[node]+(isRev?-1:1);  //if it is not reversed means for the neigbour to reach the node it needs to reverse
            dfs2(neighbour,node);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adjList.clear();

        for(auto edge:edges){
            adjList[edge[0]].push_back({edge[1],0});
            adjList[edge[1]].push_back({edge[0],1});
        }

        ans.assign(n,0);
        int cnt=0;
        dfs1(0,-1,cnt);
        ans[0]=cnt;

        dfs2(0,-1);

        return ans;
    }
};
