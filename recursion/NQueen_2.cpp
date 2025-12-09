// count the total number of distinct solution


 bool isValid(int i,int j,vector<vector<int>>&board){
        // checking colm
        for(int row=0;row<i;row++){
            if(board[row][j]) return false;
        }

        //checking upper-left-diagonal;
        int dx=i-1,dy=j-1;
        while(dx>=0 and dy>=0){
            if(board[dx--][dy--]) return false;
        }

        //checking upper-right diagonal
        dx=i-1,dy=j+1;
        while(dx>=0 and dy<board.size()){
            if(board[dx--][dy++]) return false;
        }

        return true;
    }

    int recCount(int row,int n,vector<vector<int>>&board){
        if(row==n) return 1;

        int cnt=0;
        for(int col=0;col<n;col++){
            if(isValid(row,col,board)){
                // cout<<row<<" "<<col<<endl;
                board[row][col]=1;
                cnt+=recCount(row+1,n,board);
                board[row][col]=0;
            }
        }
        return cnt;
    }

    int totalNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n));
        return recCount(0,n,board);
    }
