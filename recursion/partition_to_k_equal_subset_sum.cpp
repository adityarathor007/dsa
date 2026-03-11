 bool recCheck(int ind,vector<int>&res,int& targetSum,int& k,vector<int>&nums){
        if(ind==nums.size()){
            for(int i=0;i<k;i++){
                if(res[i]!=targetSum) return false;
            }
            return true;
        }
        for(int i=0;i<k;i++){
            if(res[i]+nums[ind]>targetSum) continue;
            if(i>0 and res[i]==res[i-1]) continue;
            int num=nums[ind];
            res[i]+=num;
            if(recCheck(ind+1,res,targetSum,k,nums)) return true;
            res[i]-=num;
        }

        return false;

    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%k) return false;
        int targetSum=sum/k;
        vector<int>res(k,0);
        sort(nums.begin(),nums.end(),greater<int>());
        return recCheck(0,res,targetSum,k,nums);

    }
