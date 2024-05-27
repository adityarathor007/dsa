#include<iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> arr)
{
    // Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    int max=0;
    int c_sum=0;
    for(int i=0;i<n;){
        if(arr[i]>0){
            while(c_sum>=0 and i<n){
                c_sum+=arr[i];
                cout<<"the current sum is "<<c_sum<<endl;
                i++;
                if(max<=c_sum){
                    max=c_sum;
                }
            }
           if(c_sum<0){
            // i++;
            c_sum=0;
            continue;
           } 
        }
        else{
            i++;
        }  
    }

    return max;

}


int main(){


    vector <int> arr{-1,2,3,-6,7,8};
    // vector <int> arr{-1,-2,-3};
    cout<<maxSubarraySum(arr)<<endl;
    return 0;
    
}