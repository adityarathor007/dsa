int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int last_ele=nums[r];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<=last_ele and target<=last_ele){
                if(nums[mid]<target) l=mid+1;
                else r=mid-1;
            }
            else if(nums[mid]<=last_ele and target>last_ele) r=mid-1;
            else if(nums[mid]>last_ele and target<=last_ele) l=mid+1;
            else{
                if(nums[mid]<target) l=mid+1;
                else r=mid-1;
            }
        }
        return -1;
    }
