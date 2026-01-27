long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<long long> pSum{0};
        unordered_map<int,long long>mp;
        long long max_ans=LLONG_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++){
            pSum.push_back(pSum.back()+nums[i]);
            if(mp.count(nums[i]+k)){
                max_ans=max(max_ans,pSum[i+1]-pSum[mp[nums[i]+k]]);
            }
            if(mp.count(nums[i]-k)){
                max_ans=max(max_ans,pSum[i+1]-pSum[mp[nums[i]-k]]);
            }
            if(!mp.count(nums[i]) || pSum[i]-pSum[mp[nums[i]]]<=0){
                mp[nums[i]]=i; //as the other half is called only to subtract from the subarray sum so negative will inturn increase the max_sum
            }
        }
        return max_ans == LLONG_MIN ? 0 : max_ans;
    }
