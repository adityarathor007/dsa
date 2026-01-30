class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string,int>strIds;
        unordered_set<int> lens;
        int m=original.size();
        int num_nodes=0;
        long long INF=LLONG_MAX;

        for(int i=0;i<m;i++){
            string s1=original[i];
            string s2=changed[i];
            if(!strIds.count(s1)){
                strIds[s1]=num_nodes++;
                lens.insert(original[i].size());
            }
            if(!strIds.count(s2)) strIds[s2]=num_nodes++;
        }

        vector<vector<long long>>graph(num_nodes,vector<long long>(num_nodes,INF));
        for(int i=0;i<m;i++){
            int i1=strIds[original[i]];
            int i2=strIds[changed[i]];
            graph[i1][i2]=min(graph[i1][i2],(long long) cost[i]);
        }

        // Floyd Warshall Algo
        for(int k=0;k<num_nodes;k++){
            for(int i=0;i<num_nodes;i++){
                if(graph[i][k]!=INF){
                    for(int j=0;j<num_nodes;j++){
                        if(graph[k][j]!=INF){
                            graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                        }

                    }
                }
            }
        }


        int n=source.size();
        vector<long long>dp(n+1,INF); //dp[i] = min cost of converting string of len i
        dp[0]=0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue;

            // Option 1: Characters match, 0 cost to move to next
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Option 2: Try all possible transformation lengths
            for (int L : lens) {
                if (i + L <= n) {
                    // Optimization: Only extract substring if necessary
                    string s = source.substr(i, L);
                    string t = target.substr(i, L);

                    if (strIds.count(s) && strIds.count(t)) {
                        long long d = graph[strIds[s]][strIds[t]];
                        if (d < INF) {
                            dp[i + L] = min(dp[i + L], dp[i] + d);
                        }
                    }
                }
            }
        }

        if(dp[n]==INF) return -1;
        return dp[n];
    }
};
