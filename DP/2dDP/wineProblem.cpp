#include<iostream>
#include<vector>
using namespace std;


<<<<<<< Updated upstream
//storing in 1d arr like for a particular year is wrong as that year can be produced by 2 pairs of s and e like for example this case of 0,0 or 1,1 where the year is same but the scenario is different
// int findMaxProfit(vector<int>& prices,int n,int s,int e,vector<vector<int>> &dp){
//     int year=n-(e-s);

    
//     if(dp[s][e]!=-1){
//         return dp[s][e];
//     }
    
//     if(s==e){
//         return dp[s][e]=year*prices[s];
//     }

//     int opt1=year*prices[s]+findMaxProfit(prices,n,s+1,e,dp);
//     int opt2=year*prices[e]+findMaxProfit(prices,n,s,e-1,dp);
//     return dp[s][e]=max(opt1,opt2);
// }


int findMaxProfit(vector<int>&prices){
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(n,0)); //here the ith and jth element denotes the maxProfit for start=i and end=j and year is n-(j-i)


    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i<=j){
                int y=n-(j-i);
                if(i==j){
                    dp[i][j]=y*prices[i];
                    continue;
                }
                int left_choice=y*prices[i]+dp[i+1][j];
                int right_choice=y*prices[j]+dp[i][j-1];
                dp[i][j]=max(left_choice,right_choice);

            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<",";
        }
        cout<<endl;
    }


    return dp[0][n-1];
=======
int maxProfit(vector<int> &arr,vector<vector<int>> &dp,int s,int e,int n){

    int year=n-(e-s);
    if(s==e){
        return year*arr[s];
    }
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    int op1=year*arr[s]+maxProfit(arr,dp,s+1,e,n);
    int op2=year*arr[e]+maxProfit(arr,dp,s,e-1,n);

    
    return dp[s][e]=max(op1,op2);
    
>>>>>>> Stashed changes


}


<<<<<<< Updated upstream

int main(){
    vector<int> prices={2,3,5,1,4};
     int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
   
    // cout<<findMaxProfit(prices,n,0,n-1,dp)<<endl;
    cout<<findMaxProfit(prices)<<endl;
} 
=======
int main(){
    vector<int> arr{2,4,6,2,5};
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));  //this will contain the optimal profit for i=start and j=end;
    
    cout<<maxProfit(arr,dp,0,n-1,n)<<endl;

}
>>>>>>> Stashed changes
