class Solution {
//     long long calcValue(vector<int>&curr,vector<int>&nums1,vector<int>&nums2){
//         long long sum=0;
//         int minVal=INT_MAX;
//         for(int ind:curr){
//             // cout<<ind<<", ";
//             sum+=nums1[ind];
//             minVal=min(minVal,nums2[ind]);
//         }
//         cout<<sum*minVal<<endl;

//         return sum*minVal;
//     }

// public:
//     void recHelper(int i,vector<int>&curr,long long&ans, int k, vector<int>& nums1, vector<int>& nums2){
//         int n=nums1.size();
//         if(i==n) return;
//         if(curr.size()==k){
//             ans=max(ans,calcValue(curr,nums1,nums2));
//             return;
//         }
        
//         for(int j=i+1;i<n;i++){
//             recHelper(j,curr,ans,k,nums1,nums2);
//             curr.push_back(j);
//             recHelper(j,curr,ans,k,nums1,nums2);
//             curr.pop_back();
//         }

//         return ;
//     }

//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         vector<int>curr;
//         long long ans=0;
//         recHelper(-1,curr,ans,k,nums1,nums2);
//         return ans;

//     }
public:
        long long maxScore(vector<int>&nums1,vector<int>&nums2, int k){
            int n=nums1.size();
            vector<pair<int,int>>ess(n);
            for(int i=0;i<n;i++){
                ess[i]={nums2[i],nums1[i]};
                
            }
            sort(rbegin(ess), rend(ess));  //sorting in descending order
            long long sumS=0,res=0;

            priority_queue <int,vector<int>,greater<int>>pq;  //min_heap
            for(auto [e,s]:ess){
                pq.emplace(s);
                sumS+=s;
                if(pq.size()>k){
                    sumS-=pq.top();
                    pq.pop();
                }
                if(pq.size()==k){
                    res=max(res,sumS*e);
                }
            }

            return res;
        }
};