  int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        int i=1;
        for(i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                int num_to_remove=nums[i];
                while(i!=n and nums[i]==num_to_remove){
                    nums[i]=INT_MAX;
                    i+=1;
                }
                i-=1; //because the for loop increases the counter
            }
            else cnt+=1;
        }

        sort(nums.begin(),nums.end());

        return cnt;

    }
