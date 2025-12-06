struct customComprator {
    bool operator()(const pair<int,pair<int,int>>&a,const pair<int,pair<int,int>>&b) const {
        return a.first>b.first;
    }
};

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size();
        int n=nums2.size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,customComprator>pq;



        // pushing all the pairs from the left and first right
        for(int i=0;i<m;i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }

        vector<vector<int>>ans;
        int pairs=0;

        while(!pq.empty() and pairs<k){
            auto p=pq.top();
            int i=p.second.first;
            int j=p.second.second;
            ans.push_back({nums1[i],nums2[j]});
            pq.pop();
            pairs+=1;

            if(j+1<n){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }

        }
        return ans;

    }
