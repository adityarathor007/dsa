#include<iostream>
using namespace std;


int connectSticks(vector<int>& sticks) {

    int n=int(sticks.size());
    priority_queue<int,vector<int>,greater<int>>pq;

    if(n==1){
        return sticks[0];
    }

    for(int num:sticks){
        pq.push(num);
    }

    int ans=0;
    while(pq.size()>1){
        int l1=pq.top();
        pq.pop();
        int l2=pq.top();
        pq.pop();
        int comb_cost=l1+l2;
        ans+=comb_cost;
        pq.push(ans);

    }

    return ans;
    

}
