int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int n=nums.size();
        int max_len=0;
        while(j<n){
            long long prd=(long long) nums[i]*k;
            if(prd>=nums[j]){
                max_len=max(max_len,(j-i+1));
                j+=1;
            }
            else i+=1; //decrease the front side so that min_element gets increased to match the condition
        }
        return n-max_len;
    }
