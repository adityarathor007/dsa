class Solution {
public:

    int minOperations(string str1,int i,string str2,int j,vector<vector<int>>&dp){
        if(i==-1 and j==-1){
            return 0;
        }
        if(i==-1){ //if converting string gets exhausted then we have to perform operstion of insertion which is the number of characters that are left in the target string
            return j+1;
        }
        if(j==-1){ //target string gets exhausted then we have to perform opertion of deletion of input string
            return i+1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(str1[i]==str2[j]){
            return dp[i][j]=0+minOperations(str1,i-1,str2,j-1,dp);

        }
        else{
            int opt1=minOperations(str1,i,str2,j-1,dp); //insertion in 1st string
            int opt2=minOperations(str1,i-1,str2,j,dp); //deletion and moving behind
            int opt3=minOperations(str1,i-1,str2,j-1,dp); //updation of the character
            return dp[i][j]=1+min(opt1,min(opt2,opt3));
        }
    }

    int minDistance(string str1, string str2) {
       int n1=str1.size();
       int n2=str2.size();
       vector<vector<int>>dp(n1,vector<int>(n2,-1));
       return minOperations(str1,n1-1,str2,n2-1,dp);
    }
    
};