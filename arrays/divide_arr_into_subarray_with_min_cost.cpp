int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int a=51,b=51; //smallest and second smallest logic prevents b marker to come before a

        for(int i=1;i<n;i++){
            if(nums[i]<a){
                b=a;
                a=nums[i];
            }
            else if(nums[i]<b) b=nums[i];
            if(a==1 and b==1) break;
        }

        return nums[0]+a+b;
    }
