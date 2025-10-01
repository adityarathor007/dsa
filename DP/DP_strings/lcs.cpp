class Solution {
public:
    // int recFun(int i,int j,string& text1,string& text2,vector<vector<int>>&dp){
    //     if(i<0 || j<0){
    //         return 0;
    //     }

    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     if(text1[i]==text2[j]){
    //         return dp[i][j]=1+recFun(i-1,j-1,text1,text2,dp);
    //     }
    //     return dp[i][j]=max(recFun(i-1,j,text1,text2,dp),recFun(i,j-1,text1,text2,dp));

    // }

    int longestCommonSubsequence(string text1, string text2) {

        //top down approach
        // int i=int(text1.size())-1;
        // int j=int(text2.size())-1;
        // vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        // return recFun(i,j,text1,text2,dp);


        // bottom up approach (shifting index)
        int n=int(text1.size());
        int m=int(text2.size());

        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //space optimization
        vector<int>prev(m+1,-1);
        vector<int>curr(m+1,-1);


        for(int j=0;j<=m;j++){
            // dp[0][j]=0;
            prev[j]=0;
            curr[j]=0;
        }


        // for(int i=0;i<=n;i++){
            // dp[i][0]=0;
        // }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    // dp[i][j]=1+dp[i-1][j-1];
                    curr[j]=1+prev[j-1];
                }
                else{
                    // dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }

        // return dp[n][m];

        // return prev[m];


        // PRINTING the longest subsequence 
        int len_lcs=dp[n][m];
        string lcs="";
        for(int i=0;i<len_lcs;i++){
            lcs+='$';
        }
        int index=len_lcs-1;

        int i=n,j=m;
        while(i>0 and j>0){
            if(s1[i-1]==s2[j-1]){
                lcs[index]=s1[i-1];
                i--;j--;
                index-=1;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    j-=1;
                }
                else{
                    i-=1;
                }
            }
        }

        return lcs;


    }

};
