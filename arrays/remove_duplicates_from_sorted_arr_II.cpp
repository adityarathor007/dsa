 int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        for(int i=1;i<n;i++){
            int prev_num=nums[i-1];
            int curr_num=nums[i];
            if(prev_num==curr_num){
                i+=1;
                while(i<n and nums[i]==curr_num){
                    nums[i]=INT_MAX;
                    i+=1;
                }
                i-=1;
            }
            cnt+=1;
        }

        sort(nums.begin(),nums.end());
        return cnt;

    }
