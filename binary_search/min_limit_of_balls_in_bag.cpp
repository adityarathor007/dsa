 bool canDivide(int cp,vector<int>nums,int maxOps){
        int ops=0;
        for(int num:nums){
            int bags=num/cp;
            if(num%cp) bags+=1;
            ops+=(bags-1);
            if(ops>maxOps) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,r=INT_MIN;
        for(int num:nums){
            r=max(r,num);
        }
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(canDivide(mid,nums,maxOperations)){
                ans=mid;
                r=mid-1; //decreasing the penatly which may cause the operation to increase and we can afford that
            }
            else l=mid+1;
        }
        return ans;
    }
