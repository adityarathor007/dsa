class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num:nums) freq[num]+=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto [num,cnt]:freq){
            pq.push({cnt,num});
            if(pq.size()>k) pq.pop();
        }

        vector<int>ans;
        while(!pq.empty()){
            auto [cnt,num]=pq.top();
            pq.pop();
            ans.push_back(num);
        }

        return ans;
    }
};



