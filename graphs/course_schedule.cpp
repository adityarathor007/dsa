bool dfs(int node,
         unordered_map<int, vector<int>>& adjList,
         vector<int>& state) {
    // state: 0 = unvisited, 1 = visiting, 2 = done

    if (state[node] == 1) return false; // back-edge -> cycle
    if (state[node] == 2) return true;  // already checked, no cycle

    state[node] = 1; // mark as visiting (in recursion stack)

    for (int neighbor : adjList[node]) {
        if (!dfs(neighbor, adjList, state)) return false;
    }

    state[node] = 2; // mark as done
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    // dfs approach with checking for back edge
    unordered_map<int, vector<int>> adjList;

    for (auto& edge : prerequisites) {
        int n1 = edge[0];
        int n2 = edge[1];
        adjList[n2].push_back(n1); // n2 -> n1
    }

    // 0 = unvisited, 1 = visiting, 2 = done
    vector<int> state(numCourses, 0);

    // must check all courses 0..numCourses-1, not only keys in adjList
    for (int course = 0; course < numCourses; ++course) {
        if (!dfs(course, adjList, state)) {
            return false;
        }
    }
    return true;


    //using topo sort
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,int>indegree;
        unordered_map<int,vector<int>>adjList;

        for(auto edge:prerequisites){
            int n1=edge[0];
            int n2=edge[1];
            indegree[n1]+=1;
            adjList[n2].push_back(n1);
        }

        queue<int>q;
        vector<int>topoSort;
        for(auto [node,vec]:adjList){
            if(indegree[node]==0){
                topoSort.push_back(node);
                q.push(node);
            }
        }

        while(!q.empty()){
            int cn=q.front();
            q.pop();
            for(int neighbor:adjList[cn]){
                indegree[neighbor]-=1;
                if(indegree[neighbor]==0){
                    topoSort.push_back(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return topoSort.size()==indegree.size();
    }

}
