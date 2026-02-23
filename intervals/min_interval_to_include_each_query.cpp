class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<vector<int>>pq;
        unordered_map<int,int> res;
        vector<int> Q=queries,res2;

        sort(intervals.begin(),intervals.end());
        sort(Q.begin(),Q.end());

        int i=0,n=intervals.size();

        // for each query
        for(int q:Q){
            while(i<n and intervals[i][0]<=q){
                int l=intervals[i][0], r=intervals[i++][1];
                pq.push({l-r-1,r}); //storing len with negative sign so that it acts as min heap (i.e more negative value will be at last)
            }

            // removing intervals with the end time less than the q as that events would be completed
            while(pq.size() and pq.top()[1]<q) pq.pop();
            res[q]=pq.size()?-pq.top()[0]:-1;
        }

        for(int q:queries){
            res2.push_back(res[q]);
        }

        return res2;
    }
};
