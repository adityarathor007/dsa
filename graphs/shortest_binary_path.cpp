class Solution {
    vector<vector<int>>dirn{{-1,0},{-1,1},{1,0},{1,1},{0,1},{1,-1},{0,-1},{-1,-1}};
    bool isValid(int x,int y,int n){
        if(x>=0 and y>=0 and x<n and y<n) return true;
        return false;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] or grid[n-1][n-1]) return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [cx,cy]=q.front();
                if(cx==n-1 and cy==n-1) return steps+1;
                q.pop();
                for(int k=0;k<8;k++){
                    int nx=cx+dirn[k][0];
                    int ny=cy+dirn[k][1];
                    if(isValid(nx,ny,n) and !grid[nx][ny]){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            steps+=1;
        }
        return -1;
    }
};
