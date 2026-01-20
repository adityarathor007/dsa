
vector<vector<int>>dirn{{-1,0},{0,1},{1,0},{0,-1}};

bool isValid(int x,int y,int m,int n){
    if(x>=0 and x<=m-1 and y>=0 and y<n) return true;
    return false;
}
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m=maze.size();
    int n=maze[0].size();


    queue<pair<int,int>>q;
    q.push({entrance[0],entrance[1]});
    maze[entrance[0]][entrance[1]]='#';

    int steps=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            auto [cx,cy]=q.front();
            q.pop();

            if(cx==0 or cx==m-1 or cy==0 or cy==n-1){
                if(cx!=entrance[0] or cy!=entrance[1]) return steps;
            }

            for(int k=0;k<4;k++){
                int nx=cx+dirn[k][0];
                int ny=cy+dirn[k][1];
                if(isValid(nx,ny,m,n) and maze[nx][ny]=='.'){
                    maze[nx][ny]='#';
                    q.push({nx,ny});
                }
            }

        }
        steps+=1;
    }

    return -1;
};
