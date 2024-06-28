#include<iostream>
using namespace std;

int longestSubarrayKSum(vector<int> arr,int k){
    //Complete this function and return the length of longest subarray
    unordered_map<int,int> m;
    vector<int> pSum;
    int c_sum=0;
    for(int i=0;i<arr.size();i++){
        c_sum+=arr[i];
        pSum.push_back(c_sum);
        m[c_sum]=i;
    }
     
    for(int i=0;i<pSum.size();i++){
        int comp=k+pSum[i]; 
        auto it=m.find(comp);
        if(it!=m.end()){
            int j=it->second; 
            return j-i;
        }
        
    }
    
    auto it=m.find(k);
    if(it!=m.end()){
        return it->second+1;    
    }
    
    return 0;
    
}

int main(){
    vector<int> arr{1,2,3,4};
    int k=6;
    cout<<longestSubarrayKSum(arr, k)<<endl;
    
    return 0;
    
}
