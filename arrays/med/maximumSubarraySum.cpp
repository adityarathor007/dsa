#include <iostream>
#include<vector>
using namespace std;

// find maximum sum possible for a subarray 


int maxSubArray(vector<int>& nums) {
        int cSum=0;
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;
        while(j<n){
            cSum+=nums[j];
            j+=1;
            ans=max(ans,cSum);  //rather than checking when the Csum is negative 
            //checking before a there is a possiblity of [-1] then ans is -1
             if(cSum<0){
                cSum=0;
                i=j; //starting from the next num with cSum made to zero
            }
           
        }

        return ans;



}