int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        if(n==1) return 0;
        while(i<=j){
            int mid=i+(j-i)/2;
            int curr_e=nums[mid];
            int prev_e=(mid!=0)?nums[mid-1]:INT_MIN;
            int next_e=(mid!=n-1)?nums[mid+1]:INT_MIN;
            if(curr_e>prev_e and curr_e>next_e) return mid;
            if(curr_e<next_e)i=mid+1;
            else j=mid-1;
        }

        return -1;
    }
