#include<iostream>
using namespace std;

vector<int>alternatePosNeg(vector<int>&arr){
    int pi=0;
    int ni=1;
    int n=arr.size();
    vector<int>ans(n);
    for(auto x:arr){
        if(x>0){
            ans[pi]=x;
            pi+=2;
        }
        else{
            ans[ni]=x;
            ni+=2;
        }
    }
    return ans;
}