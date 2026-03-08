class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>numsi;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            numsi.push_back({nums1[i],i});
        }
        sort(numsi.begin(),numsi.end());
        long long csum=0;

        priority_queue<int,vector<int>,greater<int>>pq;
        vector<long long>ans(n,0);
        int prev=-1;
        for(int i=0;i<n;i++){
            auto [num,ind]=numsi[i];
            if(i==0 or numsi[i].first>numsi[i-1].first) ans[ind]=csum;
            else ans[ind]=ans[prev];  //because this number will be greater than all the numbers with which  prev was greater so their max_sum will be same
            pq.push({nums2[ind]});
            csum+=nums2[ind];
            if(pq.size()>k){
                int val=pq.top();
                pq.pop();
                csum-=val;
            }
            prev=ind;
        }

        return ans;

    }
};
