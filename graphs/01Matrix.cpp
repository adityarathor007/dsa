// we start bfs from all 0 nodes as bfs gives shortest distance from the [starting node] and we need to find the shortest distance from all 0s to a cell 1 rather than shortest distance from 1 to all 0s and then selecting the one which is minimum .
// This will need different bfs from each 1 to all 0s and choosing the one which is minimum (TIME CONSUMING)


// PROBLEM PATTERN OF multi source bfs
vector<vector<int>>dist;
vector<vector<int>>dirn{{-1,0},{0,1},{1,0},{0,-1}};
bool isValid(int x,int y,int m,int n){
    if(x>=0 and y>=0 and x<m and y<n) return true;
    return false;
}


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();

    dist.assign(m,vector<int>(n,INT_MAX));
    queue<pair<int,int>>q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }

    int level=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            auto [cx,cy]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx=cx+dirn[k][0];
                int ny=cy+dirn[k][1];
                if(isValid(nx,ny,m,n) and mat[nx][ny]==1){
                    if(dist[nx][ny]>level+1){
                        dist[nx][ny]=level+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        level+=1;
    }

    return dist;

}
