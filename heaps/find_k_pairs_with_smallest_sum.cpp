struct customComparator {
    bool operator()(const pair<int,pair<int,int>>&a,const pair<int,pair<int,int>>&b) const {
        return a.first>b.first;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,customComparator>pq;
        int n=nums1.size(),m=nums2.size();

        for(int i=0;i<n;i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }

        vector<vector<int>>ans;

        while(!pq.empty() and k){
            auto [sum,postn]=pq.top();
            int i=postn.first;
            int j=postn.second;
            pq.pop();
            k-=1;
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<m){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return ans;
    }
};
