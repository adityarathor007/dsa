// IMPORTANT: Only hashmap and binary search can be used for finding the unique pairs (uniquness based on the indicies)
// 2 pointer approach wont be able to find all pairs, it wont be able to decide how to move pointers in case of duplicate values

 int findpow(int x){
        int pow=0;
        while(x){
            x/=2;
            pow++;
        }
        return pow-1;
    }

    int countPairs(vector<int>& deliciousness) {
        long long ans=0;
        int MOD=1e9+7;
        int n=deliciousness.size();
        if(n==1) return 0;
        sort(deliciousness.begin(),deliciousness.end());
         int maxpow = deliciousness[n-1]+deliciousness[n-2];
        int power = findpow(maxpow);

        for(int i=0;i<n;i++){
            int num=deliciousness[i];
            long long cnt=0;
            int target=1;
            for(int j=0;j<=power;j++){
                int rem=target-num;
                auto it1=lower_bound(deliciousness.begin()+i+1,deliciousness.end(),rem);
                auto it2=upper_bound(deliciousness.begin()+i+1,deliciousness.end(),rem);
                cnt+=it2-it1;
                target=target<<1;
            }
            ans=(ans+(cnt%MOD))%MOD;
        }

        return ans;
    }
