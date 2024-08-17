#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

// Longest Common Subseq

// using top-down approach
int findLCS(string&s1,string&s2,int i,int j,vector<vector<int>>&dp){
    if(i<0 or j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=1+findLCS(s1,s2,i-1,j-1,dp);
    }
    return dp[i][j]=max(findLCS(s1,s2,i,j-1,dp),findLCS(s1,s2,i-1,j,dp));

}


// using bottom down approach
int findLCS(string &s1,string &s2,int n1,int n2){
    vector<vector<int>>dp(n1+1,vector<int>(n2+1));
    for(int i=0;i<=n1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=n2;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n1][n2];

    
}


int main(){

string s1="abcde";
string s2="ce";
int n1=s1.size();
int n2=s2.size();
vector<vector<int>>dp(n1,vector<int>(n2,-1));

// cout<<findLCS(s1,s2,n1-1,n2-1,dp)<<endl;
cout<<findLCS(s1,s2,n1,n2)<<endl;

}