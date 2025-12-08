vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        vector<int>ans;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                if(mid==0 or nums[mid-1]!=target){
                    ans.push_back(mid);
                    break;
                }
                else j=mid-1;
            }
            else if(nums[mid]<target) i=mid+1;
            else j=mid-1;
        }

        i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                if(mid==n-1 or nums[mid+1]!=target){
                    ans.push_back(mid);
                    break;
                }
                else i=mid+1;
            }
            else if(nums[mid]<target) i=mid+1;
            else j=mid-1;
        }
        if(ans.size()==0) return {-1,-1};
        return ans;
    }
