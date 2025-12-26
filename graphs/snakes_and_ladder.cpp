    class Solution {
    public:
        pair<int,int>getMatrixCord(int sq,int n){
            int row=n-(sq/n)-1;
            if(!(sq%n)) row+=1;
            int colm=0;
            if((n-row)&1){
                colm=(sq%n)-1;
                if(colm<0) colm+=n;
            }
            else{
                colm=n-(sq%n);
                if(colm==n) colm=0;
            }

            return {row,colm};

        }

        int snakesAndLadders(vector<vector<int>>& board) {
            int n=board.size();
            vector<int>visited(n*n+1,false);
            queue<pair<int,int>>q;
            q.push({1,0});
            visited[1]=true;

            while(!q.empty()){
                auto [cp,ct]=q.front();
                q.pop();
                if(cp==n*n) return ct;

                for(int jump=1;jump<=6;jump++){
                    int nxt=cp+jump;
                    if(nxt>n*n) break;
                    auto [x,y]=getMatrixCord(nxt,n);
                    if(board[x][y]!=-1){
                        if(!visited[board[x][y]]){
                            visited[board[x][y]]=true;
                            q.push({board[x][y],ct+1}); }
                        }
                    else {
                        if(!visited[nxt]){
                            visited[nxt]=true;
                            q.push({nxt,ct+1});
                        }
                    }
                }
            }

            return -1;
        }
    };
