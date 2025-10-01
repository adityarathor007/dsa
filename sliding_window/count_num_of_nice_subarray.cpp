class Solution {
    int numberOfSubarrays(vector<int>&nums,int k){
        int i=0,j=0;
        int n=nums.size();
        int current_odd=0;
        int ans=0;

        while(j<n){
            if(nums[j]&1) current_odd+=1;
            if(current_odd==k){
                while(nums[i]&1){
                    i+=1;
                    ans+=1;
                }
            }
            j+=1;
        }


    return ans;
    }

};
