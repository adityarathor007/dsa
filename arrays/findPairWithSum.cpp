#include <iostream>
#include <unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


// using hashing
// pair<int,int> findPair(vector<int>&arr,int k){
//     unordered_map<int,int>m;  //indices and the corresponding complement
//     int n=arr.size();
//     for(int i=0;i<n;i++){
//         int comp=k-arr[i];
//         if(m.find(comp)!=m.end()){
//             return {m[comp],i};
//         }
//         m[arr[i]]=i;

//     }
//     return {-1,-1};

// }

//without using hashing then 2 pointer approach(but it will only say whether pair exist or not)
bool findPair(vector<int>&arr,int k){
    sort(arr.begin(),arr.end());  //to store the position you have to store the index and number but will lead to space complexity of O(N2)
    int i=0;
    int j=arr.size()-1;
    while(i!=j){
        if(arr[i]+arr[j]<k){
            i++;
        }
        else if(arr[i]+arr[j]>k){
            j--;
        }
        else{
            return true;
        }

    }
    return false;
}


int main() {

    vector<int>arr{2,6,5,8,11};
    int k=14;
    // auto p=findPair(arr,k);
    // cout<<p.first<<"-"<<p.second<<endl;
    if(findPair(arr,k)){
        cout<<"yes pair is there"<<endl;
    }
    else{
        cout<<"Pair is not there"<<endl;
    }

    return 0;
}