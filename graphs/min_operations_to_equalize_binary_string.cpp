vector<int>next;

    int getNext(int x){
        if(next[x]==x) return next[x];
        return next[x]=getNext(next[x]);
    }

    int minOperations(string s, int k) {
        int cnt0=0;
        int n=s.size();
        for(char ch:s){
            if(ch=='0') cnt0+=1;
        }
        if(!(cnt0%k)) return cnt0/k;
        if(cnt0&1 and !(k&1)) return -1;

        vector<bool> visited(n+1,false);
        next.assign(n+1,false);

        for(int i=0;i<=n;i++) next[i]=i;

        queue<int>q;
        q.push(cnt0);
        visited[cnt0]=true;

        int steps=0;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int cc=q.front();
                q.pop();

                int cl=max(0,cc+k-n);
                int ch=min(k,cc);

                // compute reachable interval
                int nl=cc+k-2*ch;
                int nh=cc+k-2*cl;

                // iterate only unvisited states using DSU skipping
                int new0=getNext(nl);
                while(new0<=nh){
                    if(new0==0) return steps+1;
                    visited[x] = true;
                    q.push(new0);
                    if(new0+2<=n){
                        next[new0] = getNext(new0 + 2);   // remove new0
                        new0 = next[new0];
                    }
                    else new0+=2;
                }

            }
            steps+=1;
        }


        return -1;

    }
