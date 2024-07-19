#include<iostream>
#include<vector>
using namespace std;

// int countSubSeq(string s,string t,int i,int j,vector<vector<int>>&dp){
//         if(i==-1 and j==-1 or j==-1){
//             return 1;
//         }
//         if(i==-1){
//             return 0;
//         }
//         int a=0;
//         if(dp[i][j]!=-1){
//             a+=dp[i][j];
//             return a;
//         }
//         a+=countSubSeq(s,t,i-1,j,dp);   //finding the subseq in i-1 len s and j len t
//         if(s[i]==t[j]){
//             a+=countSubSeq(s,t,i-1,j-1,dp); //also including the contribution of i-1 length s and j-1 length t
//         }
//         return dp[i][j]=a;
//     }

//bottom up approach
int countSubSeq(string s,string t,int n,int m){
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,0)); //the 0 represent the null string
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<",";
        }
        cout<<endl;
    }
        
    return dp[n][m];
}



int main(){
    string s1="ABBCECDGCC";
    string s2="ABC";
    int i=s1.length();
    int j=s2.length();
    // vector<vector<int>>dp(i,vector<int>(j,-1));
    // cout<<countSubSeq(s1,s2,i-1,j-1,dp)<<endl;
    cout<<countSubSeq(s1,s2,i,j)<<endl;

}


