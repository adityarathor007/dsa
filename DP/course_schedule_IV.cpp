vector<vector<int>>dp;
    unordered_map<int,vector<int>>adjList;

    bool isConnected(int cn,int tgt){

        if(dp[cn][tgt]!=-1) return dp[cn][tgt];

        bool found=false;
        for(auto neighbour:adjList[cn]){
            if(isConnected(neighbour,tgt)){
                found=true;
                break;
            }
        }

        return dp[cn][tgt]=found;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adjList.clear();
        dp.assign(numCourses,vector<int>(numCourses,-1));


        for(auto edge:prerequisites){
            adjList[edge[0]].push_back(edge[1]);
            dp[edge[0]][edge[1]]=1;
        }

        vector<bool>ans;


        for(auto query:queries){
           int src=query[0],tgt=query[1];
           ans.push_back(isConnected(src,tgt));
        }

        return ans;

    }
