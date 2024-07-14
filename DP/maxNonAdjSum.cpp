#include<iostream>
using namespace std;

//problem_statement of finding the max_sum such that no element of the sum is adjacent

int findMaxNonAdjSum(vector<int>& v){
    int n=v.size();
    vector<int> dp(n,0); ///store the max_nonAdj_sum untill ith index
   
    dp[0]=v[0];
    dp[1]=max(v[0],v[1]); //edge case

    for(int i=2;i<n;i++){
        int inc=v[i]+dp[i-2];
        int exc=dp[i-1];
        dp[i]=max(inc,exc);

    }
    return dp[n-1];

}




int main(){

    vector<int> v{6,10,12,7,9,14};
    
    cout<<findMaxNonAdjSum(v)<<endl;
}