int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0) return nums[0];
        if(n==1 and k&1) return -1;

        int ans=-1;
        int i;
        // checking for k-2 elements as 1 move required to insert it back also
        for(i=0;i<min(k-1,n);i++){
            ans=max(nums[i],ans);
        }
        // edge case if we can remove all the k elments
        if(i<n-1){
            ans=max(nums[i+1],ans);
        }
        return ans;
    }
