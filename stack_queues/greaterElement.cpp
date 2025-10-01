 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=int(nums1.size());
        int m=int(nums2.size());
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums2[i]>st.top()){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]]=-1;
            }
            else{
                mp[nums2[i]]=st.top();
            }

            st.push(nums2[i]);
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;


// Continuation of the above problem what if after reaching the last index while searching you could again start from the beginning so in this what you just need is duplicate to be placed even if it is not present actually

vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() and nums[i%n]>=st.top()){
                st.pop();
            }

            if(i<n){
                ans[i]=!st.empty()?st.top():-1;
            }

            st.push(nums[i%n]);

        }


        return ans;

    }
};
