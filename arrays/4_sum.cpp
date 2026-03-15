vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            if(i!=0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 and nums[j-1]==nums[j]) continue;
                long long ct=(long long) target-nums[i]-nums[j];
                int l=j+1,r=n-1;
                while(l<r){
                    long long csum=(long long)nums[l]+nums[r];
                    if(csum<ct) l+=1;
                    else if(csum>ct) r-=1;
                    else{
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        r-=1;
                        l+=1;
                        while(l<r and nums[l]==nums[l-1]) l+=1;
                        while(l<r and nums[r]==nums[r+1]) r-=1;
                    }
                }

            }
        }
        return ans;
}
