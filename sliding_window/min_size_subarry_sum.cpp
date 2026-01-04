int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        int csum=0,minLen=INT_MAX;
        while(j<n){
            csum+=nums[j];
            while(csum>=target){
                minLen=min(minLen,j-i+1);
                csum-=nums[i];
                i+=1;
            }
            j+=1;
        }


        if(minLen==INT_MAX) return 0;
        return minLen;
    }
