 int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int last_ele=nums[n-1]; //helps in finding where the mid is first half or second half after rotation
        int ans=-1;
        while(l<=r){
             int mid=l+(r-l)/2;
             if(nums[mid]<=last_ele){
                ans=nums[mid];
                r=mid-1;
             }
             else l=mid+1;
        }
        return ans;
    }
