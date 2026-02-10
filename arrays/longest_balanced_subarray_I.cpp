 int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>unique_ele;
        int cnt=0;
        int max_len=0;

        for(int i=0;i<n;i++){
            unique_ele.insert(nums[i]);
            if(nums[i]&1) cnt-=1;
            else cnt+=1;
            for(int j=i+1;j<n;j++){
                if(!unique_ele.count(nums[j])){
                    if(nums[j]&1) cnt-=1;
                    else cnt+=1;
                    unique_ele.insert(nums[j]);
                }
                if(!cnt) max_len=max(max_len,j-i+1);

            }
            unique_ele.clear();
            cnt=0;
        }

        return max_len;
    }
