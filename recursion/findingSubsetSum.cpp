#include <climits>
#include<iostream>
#include<vector>
using namespace std;



int findingSubsetSum( vector <int> arr,int curr_sum_req,int i=0){
    int index=arr.size();
    if(index==i){
        if(curr_sum_req==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    
    int inc=findingSubsetSum(arr, curr_sum_req-arr[i],i+1);
    int exc=findingSubsetSum(arr, curr_sum_req,i+1);
    
    return inc+exc;
}


int main(){
    vector <int> arr={1,2,3,4,5,6};
    int k;
    cin>>k;
    cout<<findingSubsetSum(arr,k)<<endl;
}