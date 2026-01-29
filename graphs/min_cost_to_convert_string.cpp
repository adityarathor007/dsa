class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int len=original.size();
        vector<vector<int>>graph(26,vector<int>(26,INT_MAX));

        for(int i=0;i<len;i++){
            int n1=original[i]-'a';
            int n2=changed[i]-'a';
            graph[n1][n2]=min(graph[n1][n2],cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                if(graph[i][k]!=INT_MAX){
                    for(int j=0;j<26;j++){
                        if(graph[k][j]!=INT_MAX){
                            graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                        }
                    }
                }
            }
        }


        long long ans=0;
        int n=source.size();

        for(int i=0;i<n;i++){
            int src=source[i]-'a';
            int tgt=target[i]-'a';
            if(src==tgt) continue;
            if(graph[src][tgt]==INT_MAX) return -1;
            ans+=(long long) graph[src][tgt];
        }

        return ans;
    }
};
