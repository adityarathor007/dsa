 vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);

        // vector<int>prefixPrd(n);
        // vector<int>suffixPrd(n);

        // for(int i=0;i<n;i++){
        //     if(i==0){
        //         prefixPrd[i]=nums[i];
        //         suffixPrd[n-i-1]=nums[n-i-1];
        //     }
        //     else{
        //         prefixPrd[i]=nums[i]*prefixPrd[i-1];
        //         suffixPrd[n-i-1]=nums[n-i-1]*suffixPrd[n-i];
        //     }
        // }



        // for(int i=0;i<n;i++){
        //     if(i>0) ans[i]*=prefixPrd[i-1];
        //     if(i<n-1) ans[i]*=suffixPrd[i+1];
        // }


        // using a variable to store the prefix and suff
        int curr=1;
        for(int i=0;i<n;i++){
            ans[i]*=curr;
            curr*=nums[i];
        }

        curr=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=curr;
            curr*=nums[i];
        }

        return ans;

    }
