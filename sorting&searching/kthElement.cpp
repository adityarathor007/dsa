#include <iostream>
#include <vector>
#include<climits>
using namespace std;
 
 

int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here

        // brute force O(n+m)
        // int i=0;
        // int j=0;
        // int n1=arr1.size();
        // int n2=arr2.size();
        // vector<int>arr(n1+n2);
        // int c=0;
        // while(i<n1 and j<n2){
        //     if(arr1[i]<arr2[j]){
                
        //         arr[c]=arr1[i];
        //         i+=1;
                
               
        //     }
        //     else{
        //         arr[c]=arr2[j];
        //         j+=1;
        //     }
        //     c+=1;
        // }
        
        // while(i<n1){
        //     arr[c]=arr1[i];
        //     i+=1;
        //     c+=1;
            
        // }
        // while(j<n2){
        //     arr[c]=arr2[j];
        //     arr.push_back(arr2[j]);
        //     j+=1;
            
        // }

        // for(int k=0;k<=c;k++){
        //     cout<<arr[k]<<",";
        // }
        // cout<<endl;
        
        // return arr[k-1];


    int n1=arr1.size();
    int n2=arr2.size();
    int left=k;
    if(n1>n2) return kthElement(k,arr2,arr1);
    int low=max(k-n2,0),high=min(k,n1);  
   
    // cout<<low<<"-"<<high<<endl;
    while(low<=high){
        int mid1=(low+high)>>1;
        int mid2=left-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n1) r1=arr1[mid1];
        if(mid2<n2) r1=arr2[mid2];
        if(mid1-1>=0) l1=arr1[mid1-1];
        if(mid2-1>=0) l2=arr2[mid2-1];
        if(l1<=r2 and l2<=r1){
            return max(l1,l2);
        }
        
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;
    
    }

    return 0;

    }

int main(){
    vector<int>arr1{2,3,6,7,9};
    vector<int>arr2{1,4,8,10};
    cout<<kthElement(5,arr1,arr2)<<endl;
}