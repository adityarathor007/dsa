vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adjList;
        vector<int>indegree(numCourses,0);

        for(vector<int> edge:prerequisites){
           adjList[edge[1]].push_back(edge[0]);
           indegree[edge[0]]+=1;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(int next:adjList[curr]){
                indegree[next]-=1;
                if(indegree[next]==0) q.push(next);
            }
        }

        if(ans.size()!=numCourses) return {};
        return ans;

    }
