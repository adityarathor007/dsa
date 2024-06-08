#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// in this question we have to find index of the element in the array but the array  is rotated about the pivot point 
// so without doing linear search we have to find the index and the below method is a modified binary search 

int findElementInRotatedArray( vector <int> arr,int k){
    int s=0;
    int e=arr.size()-1;
    while(s<=e){
        
        int mid=(s+e)/2;
        if(arr[mid]==k){
            return mid;
        }
        else{
            if(arr[s]<=arr[mid]){  //on L1
                if(arr[s]<=k and k<arr[mid]){
                    e=mid-1;  //move left 
                }
                else{
                    s=mid+1; //move right
                }
            }
            else if(arr[mid]<=arr[e]){ //on L2
            
                if(arr[mid]<k and k<=arr[e]){
                    s=mid+1; //move right
                }
                else{
                    e=mid-1; //move left
                }
            }
            
        }
    }
    return -1;
}




int main(){
    vector <int> input={7,9,10,2,3,4,5};
    int k;
    cin>>k;
    cout<<findElementInRotatedArray(input,k)<<endl;
    
}