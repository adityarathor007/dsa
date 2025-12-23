class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        k=min(k,n);
        vector<pair<int,int>>capital_with_profit;
        for(int i=0;i<n;i++){
            capital_with_profit.push_back({capital[i],profits[i]});
        }
        sort(capital_with_profit.begin(),capital_with_profit.end());
        priority_queue<int>pq;
        int i=0;
        while(k--){
            while(i<n and w>=capital_with_profit[i].first){
                pq.push(capital_with_profit[i++].second);
            }
            if(pq.empty()) return w;
            w+=pq.top();
            pq.pop();
        }

        return w;

    }
};
