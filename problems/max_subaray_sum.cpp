#include<iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> arr)
{
    // Complete this function, your function should return the maximum subarray sum
    int maxSubSum=INT_MIN,cSum=0;
    for(int num:arr){
        cSum=max(cSum+num,cSum);
        maxSum=max(cSum,maxSum);
    }
    return maxSum;

}


int main(){


    vector <int> arr{-1,2,3,-6,7,8};
    // vector <int> arr{-1,-2,-3};
    cout<<maxSubarraySum(arr)<<endl;
    return 0;

}
