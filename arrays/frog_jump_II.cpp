int maxJump(vector<int>& stones) {
        // jumping to next to next nearest stones would be optimal as if we jumpt to the next nearest one then while returning we have to give more cost
        int ans=INT_MIN;
        int curr_dirn_cost=0;
        int n=stones.size();
        int i=2;
        for(i=2;i<n;i+=2){
            curr_dirn_cost=max(abs(stones[i]-stones[i-2]),curr_dirn_cost);
        }
        if(n&1){
            ans=max(curr_dirn_cost,ans);
            curr_dirn_cost=0;
            curr_dirn_cost=max(abs(stones[n-2]-stones[n-1]),curr_dirn_cost);
            i=n-2;

        }
        else{
            curr_dirn_cost=max(abs(stones[n-1]-stones[n-2]),curr_dirn_cost);
            ans=max(ans,curr_dirn_cost);
            i=n-1;
        }

        while(i>=2){
            curr_dirn_cost=max(abs(stones[i-2]-stones[i]),curr_dirn_cost);
            i-=2;
        }
        curr_dirn_cost=max(abs(stones[0]-stones[1]),curr_dirn_cost);
        ans=max(curr_dirn_cost,ans);

        return ans;

    }
