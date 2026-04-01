vector<int>getTopoSort(int k,vector<vector<int>>&vec){
        vector<int>indegree(k+1,0);
        indegree[0]=-1;
        unordered_map<int,vector<int>>adjMap;
        int n=vec.size();
        for(int i=0;i<n;i++){
            int above=vec[i][0],below=vec[i][1];
            indegree[below]+=1;
            adjMap[above].push_back(below);
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<=k;i++){
            if(!indegree[i]) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();

            for(int neighbour:adjMap[node]){
                indegree[neighbour]-=1;
                if(!indegree[neighbour]) q.push(neighbour);
            }
        }
        // cout<<ans.size()<<endl;
        if(ans.size()<k) return {};

        // for(int i=0;i<k;i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;

        return ans;

    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>rowTopoSort=getTopoSort(k,rowConditions);
        if(rowTopoSort.empty()) return {};
        vector<int>colmTopoSort=getTopoSort(k,colConditions);
        if(colmTopoSort.empty()) return {};



        unordered_map<int,int>rowMap;
        for(int i=0;i<k;i++){
            int num=rowTopoSort[i];
            rowMap[num]=i;
        }
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            int num=colmTopoSort[i];
            int row=rowMap[num];
            ans[row][i]=num;
        }

        return ans;
    }
