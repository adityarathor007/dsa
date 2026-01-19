 bool isValidSize(int k,vector<vector<int>>&pref,int threshold){
        int m=pref.size(),n=pref[0].size();

        // sliding k*k window and checking if less then threshold
        for(int i=k-1;i<m;i++){
            for(int j=k-1;j<n;j++){
                //starting coordinates for the window
                int x1=i-k+1;
                int y1=j-k+1;
                int sum=pref[i][j]-(x1>0?pref[x1-1][j]:0)-(y1>0?pref[i][y1-1]:0)+(x1>0 and y1>0?pref[x1-1][y1-1]:0);
                if(sum<=threshold) return true;
            }
        }

        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>prefixSum=mat;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                prefixSum[i][j]+=prefixSum[i][j-1];
            }
        }

        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                prefixSum[i][j]+=prefixSum[i-1][j];
            }
        }

        int l=1,r=min(m,n);
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValidSize(mid,prefixSum,threshold)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return ans;
    }
