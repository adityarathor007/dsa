class Solution {
    vector<vector<int>>dirn{{-1,0},{0,1},{1,0},{0,-1}};
public:
    bool isValid(int x,int y,int m,int n){
        if(x>=0 and x<m and y>=0 and y<n) return true;
        return false;
    }

    void dfs(int i,int j, vector<vector<char>>&board){
        board[i][j]='A';
        int m=board.size();
        int n=board[0].size();
        for(int k=0;k<4;k++){
            int nx=i+dirn[k][0];
            int ny=j+dirn[k][1];
            if(isValid(nx,ny,m,n) and board[nx][ny]=='O'){
                dfs(nx,ny,board);
            }
        }
        return ;
    }


    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board);
            }
            if(board[i][n-1]=='O'){
                dfs(i,n-1,board);
            }
        }

        for(int j=0;j<n;j++){
            if(board[0][j]=='O') dfs(0,j,board);
            if(board[m-1][j]=='O') dfs(m-1,j,board);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='A') board[i][j]='O';
            }
        }




    }
};
