#include <iostream>
#include<vector>
using namespace std;

void sortArrayof012(vector<int>&arr){
    
    // Brute Force(O(nlogn))using sorting
        


    // storing the count of 0s 1s and 2s
    // int c0=0;
    // int c1=0;
    // int c2=0;



    // for(int x:arr){
    //     if(x==0) c0+=1;
    //     else if(x==1) c1+=1;
    //     else if(x==2) c2+=1;
    // }

    // // arr.clear();
    // for(int i=0;i<c1;i++){
    //     arr[i]=0;
    // }
    // for(int i=c1;i<c1+c2;i++){
    //     arr[i]=1;
    // }
    // for(int i=c1+c2;i<c0+c1+c2;i++){
    //     arr[i]=2;
    // }

    // DNF approach using 3 pointer(O(n)) in single pass
        // [0-low-1] its all zero
        // [low,mid-1] its all one
        // [high+1,n) its all 2
        // [mid,high] its unsorted
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low+=1;
                mid+=1;
            }
            else if(nums[mid]==1){
                mid+=1;
            }
            else {
                swap(nums[mid],nums[high]);
                high-=1;
            }
        }
        
    

return ;

}


int main() {

    vector<int>arr{2,0,2,1,1,0};
    sortArrayof012(arr);
    for(auto x:arr){
        cout<<x<<",";
    }
    cout<<endl;

    return 0;
}