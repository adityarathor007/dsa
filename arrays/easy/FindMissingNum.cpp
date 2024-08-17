class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // using sum of n numbers
        // int Actualsum=0;
        // int n=nums.size();
        // for(auto x:nums){
        //     Actualsum+=x;
        // }
        // int predictedSum=(n*(n+1))>>1;
        // return predictedSum-Actualsum;

        // using xor 
        int n=nums.size();
        int actualXor=0;
        for(int i=0;i<=n;i++){
            actualXor^=i;
        }
        for(auto x:nums){
            actualXor^=x;
        }
        return actualXor;

    }
};