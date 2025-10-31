 int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int cnt=2;
        for(int i=2;i<n;i++){
            if(nums[i-2]==nums[i]){
                int num_to_remove=nums[i-2];
                while(i!=n and nums[i]==num_to_remove){
                    nums[i]=INT_MAX;
                    i+=1;
                }
                i-=1;
            }
            else cnt+=1;
        }
        sort(nums.begin(),nums.end());
        return cnt;
    }
