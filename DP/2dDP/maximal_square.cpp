class Solution {
    vector<vector<int>>dirn{{-1,0},{0,-1},{-1,-1}};

    bool isValid(int x,int y,int m,int n){
        if(x>=0 and y>=0 and x<m and y<n) return true;
        return false;
    }
public:

    int recFind(int x,int y,vector<vector<char>>& matrix,vector<vector<int>>& dp){
        if(dp[x][y]!=-1) return dp[x][y];

        int m=matrix.size();
        int n=matrix[0].size();

        if(matrix[x][y]=='0') return dp[x][y]=0;
        int cmin=INT_MAX;

        for(int k=0;k<3;k++){
            int nx=x+dirn[k][0];
            int ny=y+dirn[k][1];
            if(isValid(nx,ny,m,n)) cmin=min(recFind(nx,ny,matrix,dp),cmin);
            else return 1;

        }

        return dp[x][y]=cmin+1;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));

        // int max_area=0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]=='1'){
        //             int curr_area=pow(recFind(i,j,matrix,dp),2);
        //             max_area=max(max_area,curr_area);
        //         }
        //     }
        // }

        vector<vector<int>>dp(m,vector<int>(n,0));
        int max_area=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    int cmin=INT_MAX;
                    for(int k=0;k<3;k++){
                        int ni=i+dirn[k][0];
                        int nj=j+dirn[k][1];
                        if(isValid(ni,nj,m,n)){
                            cmin=min(cmin,dp[ni][nj]);
                        }
                        else  cmin = 0;
                    }
                    dp[i][j] = 1 + cmin;
                    max_area = max(max_area, dp[i][j] * dp[i][j]);

                }
            }
        }

        return max_area;
    }
};
