bool canMake(vector<int>& nums,int threshold,int p){
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=threshold){  //allowing the less than one also as then the max diff will be threshold which is what is required
                p-=1;
                if(p==0) return true;
                i+=1;
            }
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums[0];
        int ans=0;

        while(l<=r){
            int mid=(l+r)/2;
            if(canMake(mid,nums)){
                ans=mid;
                r=mid-1; //because we need to minimize the mid
            }
            else l=mid+1; //increasing the threshold allows us to make more pairs
        }

        return ans;
    }
