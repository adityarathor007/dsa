pair<int,int>ind_to_coor(int ind,int n){
        int q=ind/n;
        int r=ind%n;
        if(r==0){
            q-=1;
            r=n;
        }

        if(q%2!=1){
            return {n-q-1,r-1};
        }

        return {n-q-1,n-r};

    }


    struct ComparePairs{
        bool operator()(const pair<int,int>&p1,pair<int,int>&p2){
            return p1.first>p2.first;
        }
    };


    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        // priority_queue<pair<int,int>,vector<pair<int,int>>,ComparePairs>pq;
        queue<int>q;
        q.push(1);
        vector<int>dist(n*n+1,-1);
        dist[1]=0;

        while(!q.empty()){
            auto c_index=q.front();
            q.pop();
            if(c_index==n*n) return dist[c_index];
            for(int jump=1;jump<=6;jump++){
                int n_index=c_index+jump;
                if(n_index>n*n) break;
                // if(visited[n_index-1]) continue;

                auto p=ind_to_coor(n_index,n);
                int x=p.first,y=p.second;

                //no checking the n_index visited directly are as 35 will be having a ladder to 49 and there might be also a ladder to 35 which might have caused it be visited
                int dest = (board[x][y] == -1) ? n_index : board[x][y];
                if(dist[dest]!=-1) continue;

                dist[dest]=dist[c_index]+1;
                q.push(dest);

            }

        }

        return -1;
    }
