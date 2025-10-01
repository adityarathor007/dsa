class Solution {
public:
    int numSubarraysWithSumlessthangoal(vector<int>&arr,int goal){
        int l=0,r=0;
        int n=arr.size();
        int c_sum=0;
        int ans=0;
        while(r<n){
            c_sum+=arr[l];
            while(c_sum>goal){
                c_sum-=arr[l];
                l+=1;
            }

            ans+=r-l+1;
            r+=1;

        }

        return ans;
    }

};
