    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>num_w_i;
        int n=nums.size();

        for(int i=0;i<n;i++){
            num_w_i.push_back({nums[i],i});
        }

        sort(num_w_i.begin(),num_w_i.end());

        int l=0,r=n-1;
        while(l<=r){
            if(num_w_i[l].first+num_w_i[r].first<target) l+=1;
            else if(num_w_i[l].first+num_w_i[r].first>target) r-=1;
            else return {num_w_i[l].second,num_w_i[r].second};
        }
        return {};
}
