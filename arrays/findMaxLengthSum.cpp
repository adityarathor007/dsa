#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int lenOfLongSubArr(vector<int>&arr,int k){
    int n=arr.size();
    int ans=0;

    //brute force soln(O(n2))
    // for(int i=0;i<n;i++){
    //     int c_sum=0;
    //     for(int j=i;j<n;j++){
    //         c_sum+=arr[j];
    //         if(c_sum==k){
    //             ans=max(ans,j-i+1);
    //             break;
    //         }
    //     }
    // }

    
    //using hashing (O(nlogn)) if map and O(n*1) if it is unordered_map and in worst unordered_map can go O(n2)
    // unordered_map<int,int>m;  //to store the {p_sum and index till which it is}
    // int p_sum=0;
    // for(int i=0;i<n;i++){
    //     p_sum+=arr[i];
        
    //     // m[p_sum]=i; //this directly updating, fails as when we search n-x we want to go as behind as possible 
    //     // hence fails in this case {2,0,0,0,3} and k=3 will give length as 1 where actual ans is 4
        
    //     // to solve the above case update only when p_sum hasnt occured before
    //     if(m.find(p_sum)==m.end()){
    //         m[p_sum]=i;
    //     }

    //     if(p_sum==k){
    //         ans=max(ans,i+1);
    //     }
    //     int comp=p_sum-k;
    //     if(m.find(comp)!=m.end()){
    //         ans=max(ans,i-m[comp]);
    //     }
    // }

    // using the 2 pointer approach(only for positive numbers)
    int i=0;
    int j=0;
    int p_sum=0;
    while(j<n){
        p_sum+=arr[j];
        
        if(p_sum==k){
            ans=max(ans,j-i+1);
        }
        if(p_sum>k){
            while(p_sum>k and i<j){
                p_sum-=arr[i];  //shrink the array 
                i++;
                if(p_sum==k){
                    ans=max(ans,j-i+1);
                }
            }
        }
        j++;
        
    }

    return ans;
}


int main(){
    vector<int>arr{1,2,3,1,1,1,1,3,3};
    int k=6;
    cout<<lenOfLongSubArr(arr,k)<<endl;
}