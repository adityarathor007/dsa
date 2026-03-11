bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return true;

            // remove the duplicate between left and mid position
            if(nums[mid]==nums[l]){
                l+=1;
                continue;
            }

            // the array from l and mid is sorted
            if(nums[l]<nums[mid]){
                if(nums[l]<=target and target<nums[mid]){ //target in between the l and mid
                    r=mid-1;
                }
                else l=mid+1;
            }
            else{
                if(nums[mid]<target and target<=nums[r]) l=mid+1; //check if lies in the right part
                else r=mid-1;
            }
        }
        return false;
    }
