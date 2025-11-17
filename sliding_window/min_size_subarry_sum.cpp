int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        int csum=0;
        int min_len=INT_MAX;

        while(j<n){
            csum+=nums[j];
            if(csum>=target){
                while(csum>=target){
                    csum-=nums[i];
                    i+=1;
                }
                min_len=min(min_len,j-i+2);
            }
            j+=1;
        }

        return min_len!=INT_MAX?min_len:0;
    }
