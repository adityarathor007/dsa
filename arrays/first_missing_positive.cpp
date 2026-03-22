 int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]=0; //we dont care about negative numbers
        }

        for(int i=0;i<n;i++){
            int num=nums[i];
            while(1<=num and num<=n){
                int ind=num-1;
                num=nums[ind];
                nums[ind]=-1;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=-1) return i+1;
        }
        return n+1;
    }
