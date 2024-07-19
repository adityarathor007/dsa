#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// between 2 string find the longest common subseq


// top down approach (memoisation)
// int findLongSub(string a,string b,int i,int j,vector<vector<int>> &dp){
    // if(i==a.length() or j==b.length()){
    //     return 0;
    // }
    // // check if the state is already computed
    // if(dp[i][j]!=-1){
    //     return dp[i][j];
    // }
    // if(a[i]==b[j]){
    //     return dp[i][j]=1+findLongSub(a,b,i+1,j+1,dp);
    // }
    
    // return dp[i][j]=max(findLongSub(a,b,i,j+1,dp),findLongSub(a,b,i+1,j,dp)); //skipping which character gives the maximum match   
    
    
// }


// // bottom up approach 
// int findLongSub(string a,string b,int i,int j){
//     int n1=a.length();
//     int n2=b.lenght();
//     vector<vector<int>> dp(n1+1,vector<int>(n2+1,0)){

//     }
// }


int findLongSub(string a,string b,int i,int j,vector<vector<int>>&dp){
    if(i==a.length() or j==b.length()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(a[i]==b[j]){
        return dp[i][j]=1+findLongSub(a,b,i+1,j+1,dp);
    }
    int opt1=findLongSub(a,b,i,j+1,dp);
    int opt2=findLongSub(a,b,i+1,j,dp);
    return dp[i][j]=max(opt1,opt2); 
}



int main(){
    string a="ABCD";
    string b="ABED";
    int n1=a.length();
    int n2=b.length();
    vector<vector<int> >dp(n1,vector<int>(n2,-1)); //storing the longestSubSeq length from index i to n1-1 and j to n2-1

    cout<<findLongSub(a,b,0,0,dp)<<endl;
}