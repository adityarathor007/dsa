 void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        while(j<n){
            if(nums[i]==0 and nums[j]!=0){
                swap(nums[i],nums[j]);
                i+=1;
            }
            else if(nums[i]!=0 and nums[j]==0){
                i+=1;
            }
            else if(nums[i]!=0 and nums[j]!=0){
                i+=1;
            }
            j+=1;
        }
    }
