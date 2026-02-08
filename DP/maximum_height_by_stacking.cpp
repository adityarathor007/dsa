int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(int i=0;i<n;i++){
            sort(cuboids[i].begin(),cuboids[i].end());  //keeping the height at the last which is to be maximized
        }

        sort(cuboids.begin(),cuboids.end());

        int ans=0;
        vector<int>dp(n,-1);

        for(int i=0;i<n;i++){
            dp[i]=cuboids[i][2];
            for(int j=0;j<i;j++){
                int l1=cuboids[i][0];
                int w1=cuboids[i][1];
                int h1=cuboids[i][2];
                int l0=cuboids[j][0];
                int w0=cuboids[j][1];
                int h0=cuboids[j][2];
                if(l1>=l0 and w1>=w0 and h1>=h0){
                    dp[i]=max(dp[i],h1+dp[j]);  //checking condition even after sorting because it may be possible that (15,100,100) and (25,20,120) is possible
                }
            }
            ans=max(dp[i],ans); //starting which each i as neccessary that in max_height it may be starting from any i
        }

        return ans;


    }
