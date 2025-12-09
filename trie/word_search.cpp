bool isValid(int x,int y,int m,int n){
        if(x<0 or x>=m or y<0 or y>=n) return false;
        return true;

    }

    bool dfs(int w_idx,int i,int j,vector<vector<char>>&board,string&word,vector<vector<bool>>&visited){
        if(w_idx==word.size()) return true;
        visited[i][j]=1;

        int m=board.size();
        int n=board[0].size();

        for(int k=0;k<4;k++){
            int nx=i+dirn[k][0];
            int ny=j+dirn[k][1];
            if(isValid(nx,ny,m,n) and !visited[nx][ny] and word[w_idx]==board[nx][ny]){
                if(dfs(w_idx+1,nx,ny,board,word,visited)) return true;
            }
        }
        visited[i][j]=0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(dfs(1,i,j,board,word,visited)) return true;
                }
            }
        }

        return false;
    }
