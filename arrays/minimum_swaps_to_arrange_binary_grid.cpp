int minSwaps(vector<vector<int>>& grid) {
        vector<int>tz;
        int n=grid.size();

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0 and grid[i][j]==0;j--) cnt+=1;
            tz.push_back(cnt);
        }

        int swaps=0;
        for(int i=0;i<n-1;i++){
            int need=n-1-i;
            int j=i;
            while(j<n and tz[j]<need) j+=1;
            if(j==n) return -1;
            while(j>i){
                swap(tz[j],tz[j-1]);
                swaps+=1;
                j-=1;
            }
        }

        return swaps;
    }
