class Solution {
    bool isValid(int x,int y,int m,int n){
        if(x>=0 and x<m and y>=0 and y<n) return true;
        return false;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int count_oranges=0;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                   q.push({i,j});
                }
                else if(grid[i][j]==1){
                    count_oranges+=1;
                }
            }
        }

        if(count_oranges==0) return 0;
        if(q.empty()) return -1;

        int time=0;
        vector<vector<int>>dirn={{-1,0},{0,1},{1,0},{0,-1}};

        while(!q.empty()){
            int size=q.size();
            for(int k=0;k<size;k++){
                auto cp=q.front();
                q.pop();
                int x=cp.first;
                int y=cp.second;
                for(int d=0;d<4;d++){
                    int nx=x+dirn[d][0];
                    int ny=y+dirn[d][1];
                    if(isValid(nx,ny,m,n) and grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                        count_oranges-=1;
                    }
                }
            }
            if(!q.empty()) time+=1;
        }

        if(count_oranges!=0) return -1;

        return time;

    }
};