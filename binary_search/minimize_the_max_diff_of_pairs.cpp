int countValidPairs(int t,vector<int>&nums){
        int i=0,n=nums.size();
        int cnt=0;
        while(i<n-1){
            int diff=nums[i+1]-nums[i];
            if(diff<=t){
                cnt+=1;
                i+=1;
            }
            i+=1;
        }
        return cnt;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums[0];
        int ans=0;

        while(l<=r){
            int mid=(l+r)/2;
            if(countValidPairs(mid,nums)<=p){
                r=mid-1;
            }
            else l=mid+1;
        }

        return l;
    }
