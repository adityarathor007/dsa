#include<iostream>
using namespace std;

    int maxProfit(vector<int>& prices) {
        // int i=0;
        // int j=0;
        // int profit=0;
        // int c_p=0;
        // while(j<prices.size()){
        //     if(prices[i]==prices[j]){
        //         j++;

        //     }
        //     else if(prices[i]<prices[j]){
        //         c_p=prices[j]-prices[i];
        //         profit=max(c_p,profit);
        //         j++;
        //     }   
        //     else{
        //         i++;
        //     }
        // }

        // better approach
        int profit=0;
        int buy=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            
            int curr_profit=prices[i]-buy;
            profit=max(profit,curr_profit);  
            buy=min(buy,prices[i]);  //rem the past as the the goal to maximize profit is you buy at min rate from 1 to i-1
        }

        return profit;
    }
