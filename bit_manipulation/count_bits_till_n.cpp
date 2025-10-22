    vector<int> countBits(int n) {
        // vector<int>ans;
        // ans.push_back(0);
        // for(int i=1;i<=n;i++){
        //     ans.push_back(numSetBits(i));  // function to count set bits
        // }
        // return ans;

        vector<int>ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
            ans[i]=ans[i/2]+i%2;
        }
        return ans;

    }