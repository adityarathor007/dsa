#include<iostream>
#include<vector>
using namespace std;

//using top up approach
// int fibonacchi(int n,vector<int> &dp){

//     if(n==0||n==1){
//         dp[n]=n;
//         return n;
//     }

//     if(dp[n]!=0){
//         return dp[n];
//     }
//     return dp[n]=fibonacchi(n-1,dp)+fibonacchi(n-2,dp);

// }


// using bottom up approach(using small solution we solve bigger problem)
int fibonacchi(int n){
    // as two variable are needed so we dont make a complete array to store all values
    
    int a=0;
    int b=1;
    int ans=0;
    for(int i=2;i<=n;i++){
        ans=a+b;
        a=b;
        b=ans;
    }

    return ans;
}




int main(){
    // vector<int> dp{1,0};
    cout<<fibonacchi(5)<<endl;
}

//0 1 1 2 3 5