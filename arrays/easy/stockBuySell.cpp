#include<iostream>
using namespaces std;

int maxProfit(vector<int>&prices){
    int profit=0;
    int buy=prices[0];
    int n=prices.size();
    for(int i=1;i<n;i++){
        int curr_profit=prices[i]-buy;
        profit=max(profit,curr_profit);
        buy=min(buy,prices[i]);
    }
    return profit;
}


int main(){

}