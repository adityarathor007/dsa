void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        int i=n-2;
        while(i>=0){
            // observed from the pattern
            if(nums[i]<nums[i+1]){
                // this index is the target that will be swapped with some number ahead to get the next permutation
                int j=n-1;
                while(nums[j]<=nums[i]) j-=1;
                swap(nums[i],nums[j]);
                sort(nums.begin()+i+1,nums.end());
                break;
            }
            i-=1;
        }
        if(i<0) sort(nums.begin(),nums.end());
}
