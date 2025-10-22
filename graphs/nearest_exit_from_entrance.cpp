 bool isValid(int x,int y,int m,int n){
        if(x>=0 and y>=0 and x<m and y<n){
            return true;
        }
        return false;
    }

    bool isExit(int x, int y, int m, int n){
        if(x==0 or y==0 or x==m-1 or y==n-1){
            return true;
        }
        return false;;
    }


    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{entrance[0],entrance[1]}});

        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[entrance[0]][entrance[1]]=1;

        vector<vector<int>>dirn{{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int cd=curr.first,cx=curr.second.first,cy=curr.second.second;
            if(isExit(cx,cy,m,n) and (cx!=entrance[0] or cy!=entrance[1])) return cd;
            for(int k=0;k<4;k++){
                int nx=cx+dirn[k][0];
                int ny=cy+dirn[k][1];
                if(isValid(nx,ny,m,n) and maze[nx][ny]=='.' and visited[nx][ny]==0){
                    // cout<<nx<<" "<<ny<<endl;
                    q.push({cd+1,{nx,ny}});
                    visited[nx][ny]=1;
                }
            }  
        }
        return -1;
    }