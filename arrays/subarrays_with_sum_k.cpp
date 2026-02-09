int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        int ans=0;
        unordered_map<int,int>freq;
        int prefixSum=0;

        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            if(prefixSum==k) ans+=1;
            int prev=prefixSum-k;
            if(freq.count(prev)) ans+=freq[prev];
            freq[prefixSum]+=1;
        }

        return ans;
    }
