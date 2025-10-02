#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// in this question we have to find index of the element in the array but the array  is rotated about the pivot point 
// so without doing linear search we have to find the index and the below method is a modified binary search 


int search(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        int ans=-1;
        while(i<=j){
            cout<<i<<"-"<<j<<endl;
            int mid=(i+j)/2;
            if(target==nums[mid]){
                ans=mid;
                break;
            }
            else if(nums[mid]<nums[j]){ //is right part sorted
                if(nums[mid]<target and target<=nums[j]){
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
            else if(nums[i]<=nums[mid]){ //is left part sorted
                if(nums[i]<=target and target<nums[mid]){
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
        }

        return ans;
        
    }



int main(){
    vector <int> input={4,5,6,7,0,1,2};
    int k=0;
    // cin>>k;
    cout<<search(input,k)<<endl;
    
}