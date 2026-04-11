vector<vector<int>>dirn{{-1,0},{0,1},{1,0},{0,-1}};
    bool isValid(int x,int y,int m,int n){
        if(x>=0 and y>=0 and x<m and y<n) return true;
        return false;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,pair<int,int>>>q;

        // rather than checking from every water to a land go from a land to all water and when we include all lands at start for each water we get the nearest land to that water
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    visited[i][j]=true;
                    q.push({0,{i,j}});
                }
            }
        }
        int ans=-1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [cd,cp]=q.front();
                auto [cx,cy]=cp;
                q.pop();
                ans=max(ans,cd);
                for(int k=0;k<4;k++){
                    int nx=cx+dirn[k][0];
                    int ny=cy+dirn[k][1];
                    if(isValid(nx,ny,m,n) and !visited[nx][ny]){
                        visited[nx][ny]=true;
                        q.push({cd+1,{nx,ny}});
                    }
                }
            }
        }
        if(ans==0) return -1;
        return ans;
    }
