#include<iostream>
#include<vector>
using namespace std;

void recHelper(vector<int>&arr,vector<int>buff,int i,int n,vector<vector<int>>&ans){
    if(i==n){
        ans.push_back(buff);
        return ;
    }


    recHelper(arr,buff,i+1,n,ans);
    buff.push_back(arr[i]);
    recHelper(arr,buff,i+1,n,ans);


    return ;


}

vector<vector<int>>findPowerSubsets(vector<int>&arr){
    vector<vector<int>>ans;
    // vector<int>buff;
    int n=arr.size();
    // recHelper(arr,buff,0,n,ans);


    // using bit maniplutation 
    int subsets=1<<n;
    for(int num=0;num<subsets-1;num++){
        vector<int>buff;
        for(int i=0;i<n;i++){
            if(num&(1<<i)){
                buff.push_back(arr[i]);
            }
        }
        ans.push_back(buff);
    }

    return ans;
}

int main(){
    vector<int>arr{1,2,3};
    auto ans=findPowerSubsets(arr);
    for(int i=0;i<ans.size();i++){
        for(auto x:ans[i]){
            cout<<x<<",";
        }
        cout<<endl;
    }
}