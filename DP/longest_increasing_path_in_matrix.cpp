class Solution {
    vector<vector<int>>dirn{{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>>dp;
    bool isValid(int x,int y,int m,int n){
        if(x>=0 and y>=0 and x<m and y<n) return true;
        return false;
    }
public:
    int dfs(int x,int y,vector<vector<int>>&matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        if(dp[x][y]!=-1) return dp[x][y];

        int cmax=1;
        for(int k=0;k<4;k++){
            int nx=x+dirn[k][0];
            int ny=y+dirn[k][1];
            if(isValid(nx,ny,m,n) and  matrix[nx][ny]>matrix[x][y]){
                cmax=max(1+dfs(nx,ny,matrix),cmax);
            }
        }
        return dp[x][y]=cmax;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        dp.assign(m,vector<int>(n,-1));
        int max_len=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                max_len=max(max_len,dfs(i,j,matrix));
            }
        }
        return max_len;
    }
};
